import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"

datadir =  "R6ParamScan/"
OutputFilePrefix = "MOLLEROpt_Scan"

hr_start = 10    #Hit region. 1 = Ring 1, 2 = Ring 2, 3 = Ring 3, 4 = Ring 4, 5 = Ring 5 FF, 6 & 7 = Ring 5 BF, 8 = Ring 6, 9 = spread, 10 = segment scan
hr_stop = 10
hr_step = 1     #Increments over each value of hr

cut_start = 1  #Keep start = stop unless hr = 10. Otherwise, multiple identical files will be created.
cut_stop = 65
cut_step = 2

sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). May be removed and set in src/...PrimaryGeneratorAction.cc for new UMass cosmic stand
sa_stop = 0
sa_step = 5

ID_start = 3    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 3
ID_step = 1

for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for cut in np.arange(cut_start,cut_stop+cut_step,cut_step):
                FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_cut"+str(cut)
                rootfile = "_sa"+str(sa)+"_hR"+str(hr)+"_cut"+str(cut)+".root"
                jobs="jobs"
                if not os.path.exists(jobs):
                    os.system("mkdir "+jobs)
                outDir = "rootfiles/"
                home = sourceDir
                FileName="./R6ParamScan/"+OutputFilePrefix + FileIDString+".mac"
                if os.path.exists(FileName):
                    jsubf=open(jobs+"/"+OutputFilePrefix + FileIDString+".sh", "w")
                    jsubf.write("#!/bin/bash\n")
                    #jsubf.write("#SBATCH --account=halla\n")
                    jsubf.write("#SBATCH --partition=mocha\n")
                    jsubf.write("#SBATCH --job-name=PMT_EP\n")
                    jsubf.write("#SBATCH --output=out.out\n")
                    jsubf.write("#SBATCH --error=e.err\n")
                    jsubf.write("#SBATCH --time=24:00:00\n")
                    jsubf.write("#SBATCH --nodes=1\n")
                    jsubf.write("#SBATCH --ntasks=1\n")
                    jsubf.write("#SBATCH --cpus-per-task=1\n")
                    jsubf.write("#SBATCH --mem=40G\n")
                    jsubf.write("cd "+home+"\n")
                    jsubf.write("echo \"Current working directory is `pwd`\"\n")	
                    jsubf.write("./MOLLEROpt "+FileName+"\n")
                    jsubf.write("mv "+rootfile+" "+outDir+rootfile+"\n")
                    print("sbatch "+jobs+"/"+OutputFilePrefix + FileIDString+".sh")
