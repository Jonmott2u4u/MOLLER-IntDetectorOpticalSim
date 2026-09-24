import sys
import os
import subprocess
import time
import numpy as np

sourceDir = "./"
datadir =  "MacroFolder/"
OutputFilePrefix = "MOLLEROpt_Scan"
Detector = 8
data = 999      #Sets what data is stored in the rootfile. Can be 999, 0 or 1
scan_type = 3   #Sets the beam position (1 is tile center, 2 & 3 are controlled positions, 4-6 are for other branches)

#Looped parameters
cutx_start, cutx_stop, cutx_step = 0.0, 0.0, 5.0

cuty_start, cuty_stop, cuty_step = 0.5, 0.5, 5.0

ID_start, ID_stop, ID_step = 1, 1, 1

tilt_start, tilt_stop, tilt_step = 0, 0, 1

#tilt_dir_start, tilt__dir_stop, tilt_dir_step = 0, 0, 1

energy_start, energy_stop, energy_step = 2, 1000, 2
#End of looped parameters


for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
    for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
        for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
            for tilt in np.arange(tilt_start,tilt_stop+tilt_step,tilt_step):
            #for tilt_dir in np.arange(tilt_dir_start,tilt_dir_stop+tilt_dir_step,tilt_dir_step):
                for energy in np.arange(energy_start,energy_stop+energy_step,energy_step):
                    FileIDString = "_ST"+str(scan_type)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt"+str(round(tilt,2))+"_Energy"+str(energy)+"MeV_detector"+str(Detector)+"_ID"+str(id)
                    rootfile = "_ST"+str(scan_type)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt"+str(round(tilt,2))+"_Energy"+str(energy)+"MeV_detector"+str(Detector)+".root"
                    #FileIDString = "_ST"+str(scan_type)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt_dir"+str(round(tilt_dir,2))+"_det"+str(det)+"_ID"+str(id)
                    #rootfile = "_ST"+str(scan_type)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt_dir"+str(round(tilt_dir,2))+"_det"+str(det)+".root"
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
                        jsubf.write("#SBATCH --mem=400M\n")
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
