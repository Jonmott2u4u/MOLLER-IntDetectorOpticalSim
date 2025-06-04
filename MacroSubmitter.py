import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"
datadir =  "Macrofolder/"
OutputFilePrefix = "MOLLEROpt_Scan"

#source /etc/skel/.bashrc

hr_start = 10    #Hit region. 1 = Ring 1, 2 = Ring 2, 3 = Ring 3, 4 = Ring 4, 5 = Ring 5 FF, 6 & 7 = Ring 5 BF, 8 = Ring 6, 9 = spread, 10 = segment scan, 11 = Cosmic Stand
hr_stop = 10
hr_step = 1     #Increments over each value of hr

cutx_start = 0.0
cutx_stop = 0.0
cutx_step = 5.0

cuty_start = 0.0 #Keep start = stop unless hr = 10. Otherwise, multiple identical files will be created.
cuty_stop = 40.0
cuty_step = 0.1

#sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). Set to ~16 for new Cosmic Stand
#sa_stop = 0
#sa_step = 5

tilt_start = 0.0   #Tilts the beam from the z-axis (units of degrees, rotation about y-axis))
tilt_stop = 0.0
tilt_step = 0.1

ID_start = 1    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 12    #Sets which detector will have its info stored in the root file. For storing all detectors, set 0
det_stop = 12     #For no detectors, set >= 12. Used to minimize data storage every 100 events to ~ 300 MB. Otherwise ~ 800 MB is required per save
det_step = 1

for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
                    for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
                        for tilt in np.arange(tilt_start,tilt_stop+tilt_step,tilt_step):
                            FileIDString = "_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_det"+str(det)+"_tilt"+str(round(tilt,2))+"_ID"+str(id)
                            rootfile = "_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_det"+str(det)+"_tilt"+str(round(tilt,2))+".root"
                            jobs="jobs"
                            outDir = "rootfiles/"
                            if not os.path.exists(jobs):
                                os.system("mkdir "+jobs)
                            home = sourceDir
                            FileName="./Macrofolder/"+OutputFilePrefix + FileIDString+".mac"
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
                                jsubf.write("#SBATCH --partition=production\n")
                                #jsubf.write("#SBATCH --partition=priority\n")
                                jsubf.write("#SBATCH --job-name=PMT_EP\n")
                                jsubf.write("#SBATCH --constraint=el9\n")
                                jsubf.write("#SBATCH --output=/farm_out/%u/%x-%j-%N.out\n")
                                jsubf.write("#SBATCH --error=/farm_out/%u/%x-%j-%N.err\n")
                                jsubf.write("#SBATCH --time=24:00:00\n") #Normally 30 for 10k events
                                jsubf.write("#SBATCH --nodes=1\n")
                                jsubf.write("#SBATCH --ntasks=1\n")
                                jsubf.write("#SBATCH --cpus-per-task=1\n")
                                jsubf.write("#SBATCH --mem=300M\n") #Use 800M if collecting all data for a single det, 300M for just PE histograms.
                                #---General submission info---
                                #jsubf.write("cd "+home+"\n")
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
