import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"

RunID = 2
datadir =  "R6ParamScan/"
OutputFilePrefix = "MOLLEROpt_Scan"

#Loop over values (to fix a variable set the start and stop both to the desired value)
ba_start = 20 #degress
ba_stop = 20  #degress
ba_step = 1

fa_start = 17 #degress 
fa_stop = 17 #degress
fa_step = 1

li_start = 83 #mm
li_stop = 83  #mm
li_step = 1

qt_start = 20 #mm
qt_stop = 20 #mm
qt_step = 1

of_start = 0 #mm
of_stop = 0  #mm
of_step = 2

lo_start = 163 #mm
lo_stop = 163 #mm
lo_step = 1

hr_start = 1 #Takes values from 1-9
hr_stop = 1
hr_step = 1

cut_start = 10 #Value does not matter if hr != 7,8 so set the start/stop to the same value unless hr = 7,8
cut_stop = 10 #
cut_step = 1

theta_start = 0 #Off by default
theta_stop = 0  #
theta_step = 1  #
                #
phi_start = 0   #
phi_stop = 0    #
phi_step = 45   #


for ba in np.arange(ba_start,ba_stop+ba_step,ba_step):
  for fa in np.arange(fa_start,fa_stop+fa_step,fa_step):
    for li in np.arange(li_start,li_stop+li_step,qt_step):
      for qt in np.arange(qt_start,qt_stop+qt_step,qt_step):
        for of in np.arange(of_start,of_stop+of_step,of_step):
          for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
	    for lo in np.arange(lo_start,lo_stop+lo_step,lo_step):
	      for cut in np.arange(cut_start,cut_stop+cut_step,cut_step):
                for phi in np.arange(phi_start,phi_stop+phi_step,phi_step):
                  for theta in np.arange(theta_start,theta_stop+theta_step,theta_step):
                    FileIDString = "_theta"+str(theta)+"_phi"+str(phi)+"_cut"+str(cut)+"_fA"+str(fa)+"_bA"+str(ba)+"_hR"+str(hr)+"_lI"+str(li)+"_qT"+str(qt) + "_oF"+str(of) + "_lo"+str(lo) + "_000"+str(RunID)
                    rootfile = "_theta"+str(theta)+"_phi"+str(phi)+"_cut"+str(cut)+"_fA"+str(fa)+"_bA"+str(ba)+"_hR"+str(hr)+"_lI"+str(li)+"_qT"+str(qt) + "_oF"+str(of) + "_lo"+str(lo) + "_000"+str(RunID) + ".root"
                    jobs="jobs"
                    if not os.path.exists(jobs):
                      os.system("mkdir "+jobs)

      	            outDir="/lustre19/expphy/volatile/halla/moller12gev/jonmott/sim_folders/SIMFOLDER/build/rootfiles/"            
                    home = sourceDir
                    FileName="./R6ParamScan/"+OutputFilePrefix + FileIDString+".mac"
                    if os.path.exists(FileName):
                      jsubf=open(jobs+"/"+OutputFilePrefix + FileIDString+".sh", "w")
                      jsubf.write("#!/bin/bash\n")
                      jsubf.write("#SBATCH --account=halla\n")
                      jsubf.write("#SBATCH --partition=production\n")
                      jsubf.write("#SBATCH --job-name=PMT_EP\n")
                      jsubf.write("#SBATCH --output=/farm_out/%u/%x-%j-%N.out\n")
                      jsubf.write("#SBATCH --error=/farm_out/%u/%x-%j-%N.err\n")
                      jsubf.write("#SBATCH --time=24:00:00\n")
                      jsubf.write("#SBATCH --nodes=1\n")
                      jsubf.write("#SBATCH --ntasks=1\n")
                      jsubf.write("#SBATCH --cpus-per-task=1\n")
                      jsubf.write("#SBATCH --mem=80G\n")
                      jsubf.write("cd "+home+"\n")
                      jsubf.write("echo \"Current working directory is `pwd`\"\n")	
                      jsubf.write("./MOLLEROpt "+FileName+"\n")
                      jsubf.write("mv "+rootfile+" "+outDir+rootfile+"\n")
                      print("sbatch "+jobs+"/"+OutputFilePrefix + FileIDString+".sh") 
 
