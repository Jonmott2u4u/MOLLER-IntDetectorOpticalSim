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

Particle = 2    #Sets the initial particle type. 1 for electrons, 2 for muons
Energy = 8000   #Sets energy of primary particle in units of MeV. Only works for electrons. This is handled automatically for muons using a custom distribution
EnergyCut = 0 #Sets a minimum energy for primary particles to be accepted in units of MeV. Only works for muons

NumEvents = [10000,10000,10000,10000,10000,10000,10000,10000,10000,10000,100000] #Number of events for each Hit Region (controlled by EventHitRegion variable)
#ScintYPos = [-380,-320,-245,-140,30,150]
#ScintZPos = [1911,1643,1376,1108,946,515]
shift = 0     #Shifts the particle spawn location by that much. What this affects is set in PrimaryGeneratorAction.cc. -125 for SayakStand

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 11   #Hit region. 1 = Ring 1, 2 = Ring 2, 3 = Ring 3, 4 = Ring 4, 5 = Ring 5 FF, 6 & 7 = Ring 5 BF, 8 = Ring 6, 9 = Spread, 10 = Segment Scan, 11 = Cosmic Stand
hr_stop = 11
hr_step = 1     #Increments over each value of hr

cut_start = 1  #Used for hr = 10. Selects a section of the full segment to scan over (bounds will be determined later) in 10 mm increments (can be adjusted). 0 is the first 10 mm of R1.
cut_stop = 1   #Currently repurposed to move scintillator around
cut_step = 1

sa_start = 18    #Controls the angular spread of the beam from the Z-axis (in +- degrees). Depends on the geometry of the scintillator
sa_stop = 18
sa_step = 5

ID_start = 1    #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 100
ID_step = 1

det_start = 1    #Sets which detector will have its info stored in the root file. For storing all detectors, set 0
det_stop = 1
det_step = 1

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                for cut in np.arange(cut_start,cut_stop+cut_step,cut_step):
                    RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
                    RndSeed2 = random.randrange(600001, 900000) #
                    Text = ""
                    FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_cut"+str(cut)+"_det"+str(det)
                    Text += "#------------------#Ring 1 commands --------------------#" + "\n\n"
                    Text += "/R1/LightGuideLowerConeBackAngle 22 deg" + "\n"
                    Text += "/R1/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                    Text += "/R1/LightGuideLowerInterface 75 mm" + "\n"
                    Text += "/R1/LightGuideMiddleBox 410 mm" + "\n"
                    Text += "/R1/LightGuideUpperInterface 251 mm" + "\n"
                    Text += "/R1/LightGuideQuartzInterfaceOpeningX 17.7 cm" + "\n"
                    Text += "/R1/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                    Text += "/R1/QuartzSizeZ 20 mm" + "\n"
                    Text += "/R1/QuartzSizeX 169 mm" + "\n"
                    Text += "/R1/QuartzSizeY 20 mm" + "\n"                
                    Text += "/R1/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                    Text += "/R1/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/R1/SetCenterPositionInY 13 mm" + "\n"
                    Text += "/R1/SetCenterPositionInZ 1423.94 mm" + "\n\n"
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
                    Text += "/R2/SetCenterPositionInY 50.24 mm" + "\n"
                    Text += "/R2/SetCenterPositionInZ 1145.60 mm" + "\n\n"
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
                    Text += "/R3/SetCenterPositionInY 101.69 mm" + "\n"
                    Text += "/R3/SetCenterPositionInZ 871.51 mm" + "\n\n"
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
                    Text += "/R4/SetCenterPositionInY 153.50 mm" + "\n"
                    Text += "/R4/SetCenterPositionInZ 592.08 mm" + "\n\n"
                    Text += "#------------------#Ring 5 FF commands --------------------#" + "\n\n"
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
                    Text += "/R5/SetCenterPositionInY 245.10 mm" + "\n"
                    Text += "/R5/SetCenterPositionInZ 151.64 mm" + "\n\n"
                    Text += "#------------------#Ring 5 BF1 commands --------------------#" + "\n\n"
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
                    Text += "/R6/SetCenterPositionInY 237.21 mm" + "\n"
                    Text += "/R6/SetCenterPositionInZ 302.47 mm" + "\n\n"
                    Text += "#------------------#Ring 5 BF2 commands --------------------#" + "\n\n"
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
                    Text += "/R7/SetCenterPositionInY 237.21 mm" + "\n"
                    Text += "/R7/SetCenterPositionInZ 302.47 mm" + "\n\n"
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
                    Text += "/R8/SetCenterPositionInY 334.77 mm" + "\n"
                    Text += "/R8/SetCenterPositionInZ 1.78 mm" + "\n\n"
                    Text += "#------------------#Scint1 commands ---------------#" + "\n\n"
                    Text += "/Scint1/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Scint1/QuartzSizeX 300 mm" + "\n"
                    Text += "/Scint1/QuartzSizeY 250 mm" + "\n"
                    Text += "/Scint1/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Scint1/SetCenterPositionInY -45 mm" +"\n"
                    Text += "/Scint1/SetCenterPositionInZ -430 mm" +"\n"
                    Text += "#------------------#Scintillator 2 commands ---------------#" + "\n\n"
                    Text += "/Scint2/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Scint2/QuartzSizeX 300 mm" + "\n"
                    Text += "/Scint2/QuartzSizeY 250 mm" + "\n"
                    Text += "/Scint2/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Scint2/SetCenterPositionInY 204 mm" + "\n"
                    Text += "/Scint2/SetCenterPositionInZ -404 mm" + "\n"
                    Text += "#------------------#Scintillator 3 commands ---------------#" + "\n\n"
                    Text += "/Scint3/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Scint3/QuartzSizeX 300 mm" + "\n"
                    Text += "/Scint3/QuartzSizeY 250 mm" + "\n"
                    Text += "/Scint3/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Scint3/SetCenterPositionInY -250 mm" + "\n"
                    Text += "/Scint3/SetCenterPositionInZ 1560 mm" + "\n"
                    Text += "#------------------#Scintillator 4 commands ---------------#" + "\n\n"
                    Text += "/Scint4/QuartzSizeZ 20 mm" + "\n"
                    Text += "/Scint4/QuartzSizeX 300 mm" + "\n"
                    Text += "/Scint4/QuartzSizeY 250 mm" + "\n"
                    Text += "/Scint4/SetCenterPositionInX 0 mm" + "\n"
                    Text += "/Scint4/SetCenterPositionInY -1 mm" + "\n"
                    Text += "/Scint4/SetCenterPositionInZ 1586 mm" + "\n"
                    Text += "#------------------#General commands --------------------#" + "\n\n"
                    Text += "/Det/QuartzRotX -3 deg" + "\n"
                    Text += "/Det/PolarRotation 6 deg" + "\n"
                    Text += "/Det/QuartzBevelSize 0.5 mm" + "\n"
                    Text += "/Det/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                    Text += "/Det/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                    Text += "/Det/UpdateGeometry" + "\n\n"
                    Text += "/Generator/PrimaryParticle " + str(Particle) + "\n"
                    Text += "/Generator/EventHitRegion " + str(hr) + "\n"
                    Text += "/Generator/EventShift " + str(shift) + " mm" + "\n"
                    Text += "/Generator/SegmentHitRegion " + str(cut) + " cm" + "\n"
                    Text += "/Generator/BeamEnergy " + str(Energy) + "\n"
                    Text += "/Generator/BeamEnergyCut " + str(EnergyCut*cut) + "\n"
                    Text += "/Generator/BeamSolidAngle " + str(sa) + "\n"
                    Text += "/Storage/DetectorFocus " + str(det) + "\n"
                    Text += "/RunAction/SetID " + str(id) + "\n"
                    Text += "/RunAction/SetOutputName " + FileIDString + "\n"
                    Text += "/random/setSeeds " + str(RndSeed1) + " " + str(RndSeed2) + "\n"
                    Text += "/vis/disable \n"
                    Text += "/run/beamOn " + str(NumEvents[hr-1]) + "\n"
                    text_root += "rootfiles/" + FileIDString + "_000" + str(id) + ".root" + "\n"
        
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

            
