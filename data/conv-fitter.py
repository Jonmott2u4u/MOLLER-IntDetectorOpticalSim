import numpy as np
#import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split, GridSearchCV
from sklearn.metrics import mean_squared_error
from sklearn.preprocessing import PolynomialFeatures
from sklearn.pipeline import make_pipeline
from sklearn.linear_model import LinearRegression
from scipy.optimize import curve_fit

# Define a function to model polynomial and exponential combinations
def model_func(x, *params):
    # Split the parameters into polynomial and exponential parts
    poly_order = int(params[0])
    poly_params = params[1:poly_order + 1]
    exp_params = params[poly_order + 1:]
    
    # Polynomial part
    polynomial = sum(p * (x ** i) for i, p in enumerate(poly_params))
    
    # Exponential part
    exponential = sum(a * np.exp(b * x) for a, b in zip(exp_params[::2], exp_params[1::2]))
    
    return polynomial + exponential

# Load data from a text file
def load_data(file_path):
    data = pd.read_csv(file_path, delim_whitespace=True, header=None)
    x = data.iloc[:, 0].values
    y = data.iloc[:, 1].values
    return x, y

# Fit the model using curve fitting
def fit_model(x, y):
    # Initial guess for parameters
    # The first parameter is the polynomial order
    initial_params = [1] + [0] * 4 + [1, 0]  # Example: 1st degree poly, one exponential
    
    # Bounds for parameters
    bounds = ([0, -np.inf, -np.inf, -np.inf, -np.inf, -np.inf, -np.inf], 
              [5, np.inf, np.inf, np.inf, np.inf, np.inf, np.inf])
    
    popt, _ = curve_fit(model_func, x, y, p0=initial_params, bounds=bounds)
    
    return popt

# Main script
if __name__ == "__main__":
    # Load data
    x, y = load_data('filtered_UVC32deg.txt')  # Update this with your file path

    # Fit model
    params = fit_model(x, y)

    # Predict
    y_fit = model_func(x, *params)

    # Plot results
    plt.scatter(x, y, label='Data', color='red')
    plt.plot(x, y_fit, label='Fitted Model', color='blue')
    plt.xlabel('X')
    plt.ylabel('Y')
    plt.title('Polynomial and Exponential Fit')
    plt.legend()
    plt.show()

    # Print parameters
    print("Fitted parameters:", params)