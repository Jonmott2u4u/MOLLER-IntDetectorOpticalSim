import random
import os
import numpy as np

#This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
#This script is different from MakeScanMacros3.py in that it was designed for the mocha computing cluster at UMass Amherst.
#At the time of making this script, the geometric parameters for the rings have been decided. The scannable parameters listed (the ones that are looped over) 
#are connected to the beam's controls (angle of incidence, spread, hit region, etc)

runscript = "#!/bin/bash\n\n"           
datadir =  "R6ParamScan/"                   #Location where macros are stored after generation
OutputFilePrefix = "MOLLEROpt_Scan"         #String that starts all the output files from this script (all macro files and root output files)

Energy = 8000 #Units of MeV. Normally disabled, but can be reenabled in MOLLEROptPrimaryGeneratorAction.cc

NumEvents = [10000,10000,10000,10000,10000,10000,10000,10000,10000] #Number of events for each Hit Region (controlled by EventHitRegion variable)

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 5    #See macros for hr info
hr_stop = 5
hr_step = 1     #Increments over each value of hr

cut_start = 10  #Breaks the quartz tiles up into multiple segments. Only works for EventRegion == 8,9. Currently not looped over. If it needs to be used, add to loop
cut_stop = 10
cut_step = 1

sa_start = 0    #Controls the angular spread of the beam from the Z-axis (in +- degrees).
sa_stop = 0
sa_step = 5

ID_start = 1    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 1   #The detector you wish to scan over
det_stop = 6
det_step = 1

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
                RndSeed2 = random.randrange(600001, 900000) #       
                Text = ""
                FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_det"+str(det)
                if det == 1:
                    Text += "#------------------#Ring 1 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 22 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 75 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 400 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 251 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 17.7 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Det/QuartzSizeX 169 mm" + "\n"
                    Text += "/Det/QuartzSizeY 30 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 2:
                    Text += "#------------------#Ring 2 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 22 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 75 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 400 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 205 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 18.7 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Det/QuartzSizeX 179 mm" + "\n"
                    Text += "/Det/QuartzSizeY 60 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 3:
                    Text += "#------------------#Ring 3 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 22 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 75 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 300 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 259 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 19.8 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Det/QuartzSizeX 190 mm" + "\n"
                    Text += "/Det/QuartzSizeY 60 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 4:
                    Text += "#------------------#Ring 4 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 22 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 75 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 200 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 253 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 22.1 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Det/QuartzSizeX 213 mm" + "\n"
                    Text += "/Det/QuartzSizeY 120 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset 3 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 5:
                    Text += "#------------------#Ring 5 BF Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 19 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 90 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 0.001 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 329.5 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 17 mm" + "\n"
                    Text += "/Det/QuartzSizeX 80 mm" + "\n"
                    Text += "/Det/QuartzSizeY 140 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 51:
                    Text += "#------------------#Ring 5 FF1 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 19 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 90 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 0.001 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 329.5 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 17 mm" + "\n"
                    Text += "/Det/QuartzSizeX 80 mm" + "\n"
                    Text += "/Det/QuartzSizeY 140 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 52:
                    Text += "#------------------#Ring 5 FF2 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 19 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 90 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 0.001 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 329.5 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 17 mm" + "\n"
                    Text += "/Det/QuartzSizeX 80 mm" + "\n"
                    Text += "/Det/QuartzSizeY 140 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                if det == 6:
                    Text += "#------------------#Ring 6 Geometry --------------------#" + "\n\n"
                    Text += "/Det/LightGuideLowerConeBackAngle 20 deg" + "\n"
                    Text += "/Det/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                    Text += "/Det/LightGuideLowerInterface 83 mm" + "\n"
                    Text += "/Det/LightGuideMiddleBox 90 mm" + "\n"
                    Text += "/Det/LightGuideUpperInterface 163 mm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningX 26.8 cm" + "\n"
                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/Det/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Det/QuartzSizeX 260 mm" + "\n"
                    Text += "/Det/QuartzSizeY 100 mm" + "\n"                
                    Text += "/Det/LightGuideQuartzToPMTOffset 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInY 0 mm" + "\n"
                    Text += "/Det/SetCenterPositionInZ 0 mm" + "\n\n"
                Text += "#------------------#General commands --------------------#" + "\n\n"
                Text += "/Det/QuartzRotX -3 deg" + "\n"
                Text += "/Det/PolarRotation 3 deg" + "\n"
                Text += "/Det/QuartzBevelSize 0.5 mm" + "\n"
                Text += "/Det/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                Text += "/Det/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                Text += "/Det/UpdateGeometry" + "\n\n"
                Text += "/Generator/EventHitRegion " + str(hr) + "\n"
                #Text += "/Generator/QuartzHitRegion " + str(cut) + "\n"
                Text += "/Generator/BeamEnergy "+str(Energy) + "\n"
                Text += "/Generator/BeamSolidAngle "+str(sa) + "\n"
                Text += "/RunAction/SetID " + str(id) + "\n"
                Text += "/RunAction/SetOutputName " + FileIDString + "\n"
                Text += "/random/setSeeds " + str(RndSeed1) + " " + str(RndSeed2) + "\n"
                Text += "/run/beamOn " + str(NumEvents[hr-1]) + "\n"
                #The below 2 lines are for Mocha and IFarm respectively. Hopefully the Mocha line works for the ifarm. If it does not, use the 2nd line instead
                text_root += "rootfiles/" + FileIDString + "_000" + str(id) + ".root" + "\n"
                #text_root += "lustre19/expphy/volatile/halla/moller12gev/'username'/'path-to-file'/build/rootfiles/" + FileIDString + "_000" + str(id) + ".root" + "\n"

                FileName = OutputFilePrefix + FileIDString + "_ID" + str(id) + ".mac"
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
