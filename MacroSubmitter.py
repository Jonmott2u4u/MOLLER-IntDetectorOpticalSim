import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"
datadir =  "MacroFolder/"
OutputFilePrefix = "MOLLEROpt_Scan"

hr_start = 9    #1->8 = BF det centers 1-8, 9 = segment scan
hr_stop = 9
hr_step = 1     

cutx_start = 0.0  #Used for hr = 9. Used to move the beam across the segment in mm increments
cutx_stop = 0.0   #X moves across the width of the tiles (the long sides of R1->R4, R6), and 0 is the center
cutx_step = 5.0   

cuty_start = 0.0  #Y moves the beam in the radial direction, and R1 starts at -0.5 mm, R2 at 29.5, etc
cuty_stop = 0.0
cuty_step = 0.1

tilt_start = 0.0
tilt_stop = 0.0
tilt_step = 0.1

sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). Set to ~16 for new Cosmic Stand
sa_stop = 0
sa_step = 5

ID_start = 1     #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 999    #Sets which detector will have its info stored in the root file
det_stop = 999     #0 for all detectors, 1 for Ring1, 2 for Ring2, etc. 999 saves only pe histograms
det_step = 1

for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
                    for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
                        for tilt in np.arange(tilt_start,tilt_stop+tilt_step,tilt_step):
                            FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt"+str(round(tilt,2))+"_det"+str(det)+"_ID"+str(id)
                            rootfile = "_sa"+str(sa)+"_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt"+str(round(tilt,2))+"_det"+str(det)+".root"
                            jobs="jobs"
                            outDir = "rootfiles/"
                            if not os.path.exists(jobs):
                                os.system("mkdir "+jobs)
                            home = sourceDir
                            FileName="./MacroFolder/"+OutputFilePrefix + FileIDString+".mac"
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
                                #jsubf.write("#SBATCH --account=halla\n")
                                #jsubf.write("#SBATCH --partition=priority\n")
                                jsubf.write("#SBATCH --partition=production\n")
                                jsubf.write("#SBATCH --job-name=PMT_EP\n")
                                jsubf.write("#SBATCH --constraint=el9\n")
                                jsubf.write("#SBATCH --output=/farm_out/%u/%x-%j-%N.out\n")
                                jsubf.write("#SBATCH --error=/farm_out/%u/%x-%j-%N.err\n")
                                jsubf.write("#SBATCH --time=24:00:00\n")
                                jsubf.write("#SBATCH --nodes=1\n")
                                jsubf.write("#SBATCH --ntasks=1\n")
                                jsubf.write("#SBATCH --cpus-per-task=1\n")
                                jsubf.write("#SBATCH --mem=300M\n")
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
