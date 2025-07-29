import random
import os
import numpy as np

#This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
#This script is different from MakeScanMacros3.py in that it was designed for a full segment (front or back flush) of the MOLLER main detector. 
#At the time of making this script, the geometric parameters for the rings have been decided. The scannable parameters listed (the ones that are looped over) 
#are connected to the beam's controls (angle of incidence, spread, hit region, etc)

runscript = "#!/bin/bash\n\n"           
datadir =  "MacroFolder/"                   #Location where macros are stored after generation
OutputFilePrefix = "MOLLEROpt_Scan"         #String that starts all the output files from this script (all macro files and root output files)

Detector = 5      #Sets the detector to use

Particle = 1      #Sets the primary particle type. 1 for electrons, 2 for muons
Energy = 8000     #Sets energy of primary particle in units of MeV. Only works for electrons. This is handled automatically for muons using a custom distribution
EnergyCut = 0     #Sets a minimum energy for primary particles to be accepted in units of MeV. Only works for muons

NumEvents = 10000 #Number of events for each Hit Region (controlled by EventHitRegion variable)

shift = 0         #Shifts the particle spawn location by that much. What this affects is set in PrimaryGeneratorAction.cc. -125 for SayakStand

tilt_dir = 90     #Controls the direction of the beam tilt (units of degrees, 0 = x-axis, 90 = y-axis, rotation about z-axis)

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 9      #1->8 = BF det centers 1-8, 9->10 are segment scans
hr_stop = 9
hr_step = 1     

cutx_start = 0.0  #Used for hr = 9. Used to move the beam across the segment in mm increments
cutx_stop = 0.0   #X moves across the width of the tiles (the long sides of R1->R4, R6), and 0 is the center
cutx_step = 5.0   

cuty_start = 0.0  #Y moves the beam in the radial direction, and R1 starts at 0.5 mm, R2 at 30.5, etc
cuty_stop = 0.0
cuty_step = 0.1

sa = 0            #Controls the angular spread of the beam from the Z-axis (in +- degrees)

tilt = 00          #Controls the tilt of the beam from the z-axis in degrees

ID_start = 1      #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 999    #Sets which detector will have its info stored in the root file
det_stop = 999     #0 for all detectors, 999 for no detectors, 1 for events hitting the main detector, etc
det_step = 1

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
        for det in np.arange(det_start,det_stop+det_step,det_step):
            for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
                for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
                    RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
                    RndSeed2 = random.randrange(600001, 900000) #
                    Text = ""
                    FileIDString = "_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_det"+str(det)
                    if Detector == 1:
                        Text += "#------------------#Ring 1 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 22 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 75 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 410 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 251 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 17.7 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.7 cm" + "\n"
                        Text += "/MainDet/QuartzSizeZ 20 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 169 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 20 mm" + "\n"  
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"              
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 270.7 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 1923.94 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 2:
                        Text += "#------------------#Ring 2 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 22 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 75 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 400 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 205 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 18.7 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 20 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 179 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 60 mm" + "\n"   
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 292.8 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 1645.6 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 3:
                        Text += "#------------------#Ring 3 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 22 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 75 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 300 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 259 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 19.8 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 20 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 190 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 60 mm" + "\n"   
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 329.8 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 1371.51 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 4:
                        Text += "#------------------#Ring 4 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 22 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 75 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 200 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 253 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset 3 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 22.1 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 20 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 213 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 120 mm" + "\n"  
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"      
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 366.9 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 1092.08 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 5:
                        Text += "#------------------#Ring 5 FF commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 19 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 90 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 0.001 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 329.5 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 17 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 80 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 140 mm" + "\n" 
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 435.3 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 651.64 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 6:
                        Text += "#------------------#Ring 5 BF1 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 19 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 90 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 0.001 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 329.5 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 17 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 80 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 140 mm" + "\n" 
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"
                        Text += "/MainDet/SetCenterPositionInX -86.7 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 427.4 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 802.47 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 7:
                        Text += "#------------------#Ring 5 BF2 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 19 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 90 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 0.001 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 329.5 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 17 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 80 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 140 mm" + "\n" 
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"
                        Text += "/MainDet/SetCenterPositionInX 86.7 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 427.4 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 802.47 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    if Detector == 8:
                        Text += "#------------------#Ring 6 commands --------------------#" + "\n\n"
                        Text += "/MainDet/LightGuideLowerConeBackAngle 20 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                        Text += "/MainDet/LightGuideLowerInterface 83 mm" + "\n"
                        Text += "/MainDet/LightGuideMiddleBox 90 mm" + "\n"
                        Text += "/MainDet/LightGuideUpperInterface 163 mm" + "\n"
                        Text += "/MainDet/LightGuideQuartzToPMTOffset 0 mm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningX 26.8 cm" + "\n"
                        Text += "/MainDet/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                        Text += "/MainDet/QuartzSizeZ 20 mm" + "\n"
                        Text += "/MainDet/QuartzSizeX 260 mm" + "\n"
                        Text += "/MainDet/QuartzSizeY 100 mm" + "\n"  
                        Text += "/MainDet/QuartzRotX -3 deg" + "\n"             
                        Text += "/MainDet/SetCenterPositionInX 0 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInY 517 mm" + "\n"
                        Text += "/MainDet/SetCenterPositionInZ 501.78 mm" + "\n"
                        Text += "/MainDet/PolarRotation 3 deg" + "\n"
                        Text += "/MainDet/AzimuthalRotation 0 deg" + "\n"
                        Text += "/MainDet/UpdateGeometry" + "\n\n"
                    Text += "#------------------#General commands --------------------#" + "\n\n"
                    Text += "/Generator/PrimaryParticle " + str(Particle) + "\n"
                    Text += "/Generator/EventHitRegion " + str(hr) + "\n"
                    Text += "/Generator/EventShift " + str(shift) + " mm" + "\n"
                    Text += "/Generator/SegmentHitPosX " + str(cutx) + " mm" + "\n"
                    Text += "/Generator/SegmentHitPosY " + str(cuty) + " mm" + "\n"
                    Text += "/Generator/BeamEnergy " + str(Energy) + "\n"
                    Text += "/Generator/BeamEnergyCut " + str(EnergyCut) + "\n"
                    Text += "/Generator/BeamSolidAngle " + str(sa) + " degree" + "\n"
                    Text += "/Generator/BeamTiltAngle " + str(tilt) + " degree" + "\n"
                    Text += "/Generator/BeamTiltDirection " + str(tilt_dir) + " degree" + "\n"
                    Text += "/Storage/DetectorFocus " + str(det) + "\n"
                    Text += "/RunAction/SetID " + str(id) + "\n"
                    Text += "/RunAction/SetOutputName " + FileIDString + "\n"
                    Text += "/random/setSeeds " + str(RndSeed1) + " " + str(RndSeed2) + "\n"
                    Text += "/vis/disable \n"
                    Text += "/run/beamOn " + str(NumEvents) + "\n"
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

            
