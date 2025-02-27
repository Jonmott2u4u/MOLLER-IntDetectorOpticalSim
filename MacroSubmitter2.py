import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"
datadir =  "MacroFolder/"
OutputFilePrefix = "MOLLEROpt_Scan"

hr_start = 5    #See macros for hr info
hr_stop = 5
hr_step = 1     #Increments over each value of hr

cut_start = 0  #Breaks the quartz tiles up into multiple segments. How it is broken up is determined using hr. Not currently implemented for the 8 detector setup
cut_stop = 0
cut_step = 1


#sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). May be removed and set in src/...PrimaryGeneratorAction.cc for new UMass cosmic stand
#sa_stop = 0
#sa_step = 5
sa = 0

ID_start = 1    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 6   #The detector you wish to scan over
det_stop = 6
det_step = 1

ua_start = 10   #Controls the angle of the US reflector plate for the lower cone
ua_stop = 30
ua_step = 0.5

lg_start = 50   #Controls the height of the lower cone
lg_stop = 90
lg_step = 0.5

for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for ua in np.arange(ua_start,ua_stop+ua_step,ua_step):
        for lg in np.arange(lg_start,lg_stop+lg_step,lg_step):
            for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
                for det in np.arange(det_start,det_stop+det_step,det_step):
                    for cut in np.arange(cut_start,cut_stop+cut_step,cut_step):
                        FileIDString = "_ua"+str(ua)+"_lg"+str(lg)+"_hR"+str(hr)+"_det"+str(det)+"_cut"+str(cut)+"_ID"+str(id)
                        rootfile = "_ua"+str(ua)+"_lg"+str(lg)+"_hR"+str(hr)+"_det"+str(det)+"_cut"+str(cut)+".root"
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
                            #jsubf.write("#SBATCH --partition=mocha\n")
                            #jsubf.write("#SBATCH --job-name=PMT_EP\n")
                            #jsubf.write("#SBATCH --output=out.out\n")
                            #jsubf.write("#SBATCH --error=e.err\n")
                            #jsubf.write("#SBATCH --time=24:00:00\n")
                            #jsubf.write("#SBATCH --nodes=1\n")
                            #jsubf.write("#SBATCH --ntasks=1\n")
                            #jsubf.write("#SBATCH --cpus-per-task=1\n")
                            #jsubf.write("#SBATCH --mem=40G\n")
                            #---Submission info for IFarm---
                            jsubf.write("#SBATCH --account=halla\n")
                            jsubf.write("#SBATCH --partition=production\n")
                            jsubf.write("#SBATCH --job-name=PMT_EP\n")
                            jsubf.write("#SBATCH --constraint=el9\n")
                            jsubf.write("#SBATCH --output=/farm_out/%u/%x-%j-%N.out\n")
                            jsubf.write("#SBATCH --error=/farm_out/%u/%x-%j-%N.err\n")
                            jsubf.write("#SBATCH --time=24:00:00\n")
                            jsubf.write("#SBATCH --nodes=1\n")
                            jsubf.write("#SBATCH --ntasks=1\n")
                            jsubf.write("#SBATCH --cpus-per-task=1\n")
                            jsubf.write("#SBATCH --mem=2G\n")
                            #---General submission info---
                            jsubf.write("echo \"Current working directory is `pwd`\"\n")	
                            jsubf.write("source /etc/skel/.bashrc \n")
                            jsubf.write("module reset \n")
                            jsubf.write("module use /group/halla/modulefiles \n")
                            jsubf.write("module load root/6.30.04 geant4/11.2.1 \n")
                            jsubf.write("export G4LEDATA=$GEANT4_DATA_DIR/G4EMLOW8.5 \n")
                            jsubf.write("env \n")
                            jsubf.write("ldd ./MOLLEROpt \n")
                            jsubf.write("./MOLLEROpt "+FileName+"\n")
                            print("sbatch "+jobs+"/"+OutputFilePrefix + FileIDString+".sh")
