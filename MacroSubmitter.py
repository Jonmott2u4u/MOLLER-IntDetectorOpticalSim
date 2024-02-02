import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"
datadir =  "R6ParamScan/"
OutputFilePrefix = "MOLLEROpt_Scan"

hr_start = 5    #See macros for hr info
hr_stop = 5
hr_step = 1     #Increments over each value of hr

cut_start = 10  #Breaks the quartz tiles up into multiple segments. How it is broken up is determined using hr. Not currently implemented for the 8 detector setup
cut_stop = 10
cut_step = 1

sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). May be removed and set in src/...PrimaryGeneratorAction.cc for new UMass cosmic stand
sa_stop = 0
sa_step = 5

ID_start = 1    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 1   #The detector you wish to scan over
det_stop = 6
det_step = 1

for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_det"+str(det)+"_ID"+str(id)
                rootfile = FileIDString + ".root"
                jobs="jobs"
                if not os.path.exists(jobs):
                    os.system("mkdir "+jobs)
                outDir = "rootfiles/"
                home = sourceDir
                FileName="./R6ParamScan/"+OutputFilePrefix + FileIDString+".mac"
                if os.path.exists(FileName):
                    jsubf=open(jobs+"/"+OutputFilePrefix + FileIDString+".sh", "w")
                    jsubf.write("#!/bin/bash\n")
                    #---Submission info for Mocha---
                    jsubf.write("#SBATCH --partition=mocha\n")
                    jsubf.write("#SBATCH --job-name=PMT_EP\n")
                    jsubf.write("#SBATCH --output=out.out\n")
                    jsubf.write("#SBATCH --error=e.err\n")
                    jsubf.write("#SBATCH --time=24:00:00\n")
                    jsubf.write("#SBATCH --nodes=1\n")
                    jsubf.write("#SBATCH --ntasks=1\n")
                    jsubf.write("#SBATCH --cpus-per-task=1\n")
                    jsubf.write("#SBATCH --mem=40G\n")
                    #---Submission info for IFarm---
                    #jsubf.write("#SBATCH --account=halla\n")
                    #jsubf.write("#SBATCH --partition=production\n")
                    #jsubf.write("#SBATCH --job-name=PMT_EP\n")
                    #jsubf.write("#SBATCH --output=/farm_out/%u/%x-%j-%N.out\n")
                    #jsubf.write("#SBATCH --error=/farm_out/%u/%x-%j-%N.err\n")
                    #jsubf.write("#SBATCH --time=24:00:00\n")
                    #jsubf.write("#SBATCH --nodes=1\n")
                    #jsubf.write("#SBATCH --ntasks=1\n")
                    #jsubf.write("#SBATCH --cpus-per-task=1\n")
                    #jsubf.write("#SBATCH --mem=80G\n")
                    #---General submission info---
                    jsubf.write("cd "+home+"\n")
                    jsubf.write("echo \"Current working directory is `pwd`\"\n")	
                    jsubf.write("./MOLLEROpt "+FileName+"\n")
                    jsubf.write("mv "+rootfile+" "+outDir+rootfile+"\n")
                    print("sbatch "+jobs+"/"+OutputFilePrefix + FileIDString+".sh")
