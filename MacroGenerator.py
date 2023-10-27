import random
import os
import numpy as np

#This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
#This script is different from MakeScanMacros3.py in that it was designed for a full segment (front or back flush) of the MOLLER main detector. 
#At the time of making this script, the geometric parameters for the rings have been decided. The scannable parameters listed (the ones that are looped over) 
#are connected to the beam's controls (angle of incidence, spread, hit region, etc)

runscript = "#!/bin/bash\n\n"           
datadir =  "R6ParamScan/"                   #Location where macros are stored after generation
OutputFilePrefix = "MOLLEROpt_Scan"         #String that starts all the output files from this script (all macro files and root output files)

Energy = 8000 #Units of MeV. Normally disabled, but can be reenabled in MOLLEROptPrimaryGeneratorAction.cc

RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
RndSeed2 = random.randrange(600001, 900000) #

NumEvents = [10000,10000,10000,10000,10000,10000,10000,10000,10000] #Number of events for each Hit Region (controlled by EventHitRegion variable)

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 9    #Hit region. 1 = Ring 1, 2 = Ring 2, 3 = Ring 3, 4 = Ring 4, 5 = Ring 5 FF, 6 & 7 = Ring 5 BF, 8 = Ring 6
hr_stop = 9
hr_step = 1     #Increments over each value of hr

cut_start = 0  #Used for hr = 10. Selects a section of the full segment to scan over (bounds will be determined later) in 10 mm increments (can be adjusted). 0 is the first 10 mm of R1.
cut_stop = 0
cut_step = 1

sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees). May be removed and set in src/...PrimaryGeneratorAction.cc for new UMass cosmic stand
sa_stop = 0
sa_step = 5

ID_start = 3    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 3
ID_step = 1

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            Text = ""
            FileIDString = "_sa"+str(sa)+"_hR"+str(hr)
            Text += "#------------------#Ring 1 commands --------------------#" + "\n\n"
            Text += "/R1/LightGuideLowerConeBackAngle 22 deg" + "\n"
            Text += "/R1/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R1/LightGuideLowerInterface 75 mm" + "\n"
            Text += "/R1/LightGuideMiddleBox 400 mm" + "\n"
            Text += "/R1/LightGuideUpperInterface 251 mm" + "\n"
            Text += "/R1/LightGuideQuartzInterfaceOpeningX 17.7 cm" + "\n"
            Text += "/R1/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
            Text += "/R1/QuartzSizeZ 20 mm" + "\n"
            Text += "/R1/QuartzSizeX 169 mm" + "\n"
            Text += "/R1/QuartzSizeY 30 mm" + "\n"                
            Text += "/R1/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R1/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R1/SetCenterPositionInY 0 mm" + "\n"
            Text += "/R1/SetCenterPositionInZ 1396 mm" + "\n\n"
            Text += "#------------------#Ring 2 commands --------------------#" + "\n\n"
            Text += "/R2/LightGuideLowerConeBackAngle 22 deg" + "\n"
            Text += "/R2/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R2/LightGuideLowerInterface 75 mm" + "\n"
            Text += "/R2/LightGuideMiddleBox 400 mm" + "\n"
            Text += "/R2/LightGuideUpperInterface 205 mm" + "\n"
            Text += "/R2/LightGuideQuartzInterfaceOpeningX 18.7 cm" + "\n"
            Text += "/R2/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
            Text += "/R2/QuartzSizeZ 20 mm" + "\n"
            Text += "/R2/QuartzSizeX 179 mm" + "\n"
            Text += "/R2/QuartzSizeY 60 mm" + "\n"                
            Text += "/R2/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R2/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R2/SetCenterPositionInY 37 mm" + "\n"
            Text += "/R2/SetCenterPositionInZ 1128 mm" + "\n\n"
            Text += "#------------------#Ring 3 commands --------------------#" + "\n\n"
            Text += "/R3/LightGuideLowerConeBackAngle 22 deg" + "\n"
            Text += "/R3/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R3/LightGuideLowerInterface 75 mm" + "\n"
            Text += "/R3/LightGuideMiddleBox 300 mm" + "\n"
            Text += "/R3/LightGuideUpperInterface 259 mm" + "\n"
            Text += "/R3/LightGuideQuartzInterfaceOpeningX 19.8 cm" + "\n"
            Text += "/R3/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
            Text += "/R3/QuartzSizeZ 20 mm" + "\n"
            Text += "/R3/QuartzSizeX 190 mm" + "\n"
            Text += "/R3/QuartzSizeY 60 mm" + "\n"                
            Text += "/R3/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R3/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R3/SetCenterPositionInY 94 mm" + "\n"
            Text += "/R3/SetCenterPositionInZ 861 mm" + "\n\n"
            Text += "#------------------#Ring 4 commands --------------------#" + "\n\n"
            Text += "/R4/LightGuideLowerConeBackAngle 22 deg" + "\n"
            Text += "/R4/LightGuideLowerConeFrontAngle 17 deg" + "\n"
            Text += "/R4/LightGuideLowerInterface 75 mm" + "\n"
            Text += "/R4/LightGuideMiddleBox 200 mm" + "\n"
            Text += "/R4/LightGuideUpperInterface 253 mm" + "\n"
            Text += "/R4/LightGuideQuartzInterfaceOpeningX 22.1 cm" + "\n"
            Text += "/R4/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
            Text += "/R4/QuartzSizeZ 20 mm" + "\n"
            Text += "/R4/QuartzSizeX 213 mm" + "\n"
            Text += "/R4/QuartzSizeY 120 mm" + "\n"                
            Text += "/R4/LightGuideQuartzToPMTOffset 3 mm" + "\n"
            Text += "/R4/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R4/SetCenterPositionInY 146 mm" + "\n"
            Text += "/R4/SetCenterPositionInZ 593 mm" + "\n\n"
            Text += "#------------------#Ring 5 BF commands --------------------#" + "\n\n"
            Text += "/R5/LightGuideLowerConeBackAngle 19 deg" + "\n"
            Text += "/R5/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R5/LightGuideLowerInterface 90 mm" + "\n"
            Text += "/R5/LightGuideMiddleBox 0.001 mm" + "\n"
            Text += "/R5/LightGuideUpperInterface 329.5 mm" + "\n"
            Text += "/R5/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
            Text += "/R5/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
            Text += "/R5/QuartzSizeZ 17 mm" + "\n"
            Text += "/R5/QuartzSizeX 80 mm" + "\n"
            Text += "/R5/QuartzSizeY 140 mm" + "\n"                
            Text += "/R5/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R5/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R5/SetCenterPositionInY 221 mm" + "\n"
            Text += "/R5/SetCenterPositionInZ 431 mm" + "\n\n"
            Text += "#------------------#Ring 5 FF1 commands --------------------#" + "\n\n"
            Text += "/R6/LightGuideLowerConeBackAngle 19 deg" + "\n"
            Text += "/R6/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R6/LightGuideLowerInterface 90 mm" + "\n"
            Text += "/R6/LightGuideMiddleBox 0.001 mm" + "\n"
            Text += "/R6/LightGuideUpperInterface 329.5 mm" + "\n"
            Text += "/R6/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
            Text += "/R6/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
            Text += "/R6/QuartzSizeZ 17 mm" + "\n"
            Text += "/R6/QuartzSizeX 80 mm" + "\n"
            Text += "/R6/QuartzSizeY 140 mm" + "\n"                
            Text += "/R6/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R6/SetCenterPositionInX -86.7 mm" + "\n"
            Text += "/R6/SetCenterPositionInY 230 mm" + "\n"
            Text += "/R6/SetCenterPositionInZ 274 mm" + "\n\n"
            Text += "#------------------#Ring 5 FF2 commands --------------------#" + "\n\n"
            Text += "/R7/LightGuideLowerConeBackAngle 19 deg" + "\n"
            Text += "/R7/LightGuideLowerConeFrontAngle 18 deg" + "\n"
            Text += "/R7/LightGuideLowerInterface 90 mm" + "\n"
            Text += "/R7/LightGuideMiddleBox 0.001 mm" + "\n"
            Text += "/R7/LightGuideUpperInterface 329.5 mm" + "\n"
            Text += "/R7/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
            Text += "/R7/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
            Text += "/R7/QuartzSizeZ 17 mm" + "\n"
            Text += "/R7/QuartzSizeX 80 mm" + "\n"
            Text += "/R7/QuartzSizeY 140 mm" + "\n"                
            Text += "/R7/LightGuideQuartzToPMTOffset -2 mm" + "\n"
            Text += "/R7/SetCenterPositionInX 86.7 mm" + "\n"
            Text += "/R7/SetCenterPositionInY 230 mm" + "\n"
            Text += "/R7/SetCenterPositionInZ 274 mm" + "\n\n"
            Text += "#------------------#Ring 6 commands --------------------#" + "\n\n"
            Text += "/R8/LightGuideLowerConeBackAngle 20 deg" + "\n"
            Text += "/R8/LightGuideLowerConeFrontAngle 17 deg" + "\n"
            Text += "/R8/LightGuideLowerInterface 83 mm" + "\n"
            Text += "/R8/LightGuideMiddleBox 90 mm" + "\n"
            Text += "/R8/LightGuideUpperInterface 163 mm" + "\n"
            Text += "/R8/LightGuideQuartzInterfaceOpeningX 26.8 cm" + "\n"
            Text += "/R8/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
            Text += "/R8/QuartzSizeZ 20 mm" + "\n"
            Text += "/R8/QuartzSizeX 260 mm" + "\n"
            Text += "/R8/QuartzSizeY 100 mm" + "\n"                
            Text += "/R8/LightGuideQuartzToPMTOffset 0 mm" + "\n"
            Text += "/R8/SetCenterPositionInX 0 mm" + "\n"
            Text += "/R8/SetCenterPositionInY 330 mm" + "\n"
            Text += "/R8/SetCenterPositionInZ 0 mm" + "\n\n"
            Text += "#------------------#General commands --------------------#" + "\n\n"
            Text += "/Det/QuartzRotX -3 deg" + "\n"
            Text += "/Det/PolarRotation 3 deg" + "\n"
            Text += "/Det/QuartzBevelSize 0.5 mm" + "\n"
            Text += "/Det/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
            Text += "/Det/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
            Text += "/Det/UpdateGeometry" + "\n\n"
            Text += "/Generator/EventHitRegion " + str(hr) + "\n"
            Text += "/Generator/SegmentHitRegion " + str(cut) + "\n"
            Text += "/Generator/BeamEnergy "+str(Energy) + "\n"
            Text += "/Generator/BeamSolidAngle "+str(sa) + "\n"
            Text += "/RunAction/SetID " + str(id) + "\n"
            Text += "/RunAction/SetOutputName " + FileIDString + "\n"
            Text += "/random/setSeeds " + str(RndSeed1) + " " + str(RndSeed2) + "\n"
            Text += "/run/beamOn " + str(NumEvents[hr-1]) + "\n"
            #text_root += "/home/jonmott/simulations/Moller-mocha/build/rootfiles/" + FileIDString + "_000" + str(id) + ".root" + "\n"
            text_root += "rootfiles/" + FileIDString + "_000" + str(id) + ".root" + "\n"

            FileName = OutputFilePrefix + FileIDString + ".mac"
            fout = open(datadir+FileName, "w")
            fout.write(Text)
            fout.close()
            runscript += "./MOLLEROpt " + datadir + FileName + " > " + datadir + OutputFilePrefix + FileIDString + ".out" + " & \n"

scfile = open("StartRuns","w")
scfile.write(runscript)
scfile.close()
files_dat = open("files.dat","w")
files_dat.write(text_root)
files_dat.close()

            
