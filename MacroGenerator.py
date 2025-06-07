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

Particle = 1      #Sets the primary particle type. 1 for electrons, 2 for muons
Energy = 8000     #Sets energy of primary particle in units of MeV. Only works for electrons. This is handled automatically for muons using a custom distribution
EnergyCut = 0     #Sets a minimum energy for primary particles to be accepted in units of MeV. Only works for muons

NumEvents = 10000 #Number of events for each Hit Region (controlled by EventHitRegion variable)

shift = 0         #Shifts the particle spawn location by that much. What this affects is set in PrimaryGeneratorAction.cc. -125 for SayakStand

tilt_dir = 90     #Controls the direction of the beam tilt (units of degrees, 0 = x-axis, 90 = y-axis, rotation about z-axis)

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 9      #1->8 = BF det centers 1-8, 9->16 FF det centers. 17->18 segment scans, 19->20 cosmics
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
tilt_step = 0.0

sa_start = 0      #Controls the angular spread of the beam from the Z-axis (in +- degrees). Depends on the geometry of the scintillator
sa_stop = 0
sa_step = 5

ID_start = 1      #Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)
ID_stop = 1
ID_step = 1

det_start = 999    #Sets which detector will have its info stored in the root file
det_stop = 999     #0 for all detectors, 1 for Ring1, 2 for Ring2, etc. 999 saves only pe histograms
det_step = 1

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
        for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
            for det in np.arange(det_start,det_stop+det_step,det_step):
                for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
                    for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
                        for tilt in np.arange(tilt_start,tilt_stop+tilt_step,tilt_step):
                            RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
                            RndSeed2 = random.randrange(600001, 900000) #
                            Text = ""
                            FileIDString = "_sa"+str(sa)+"_hR"+str(hr)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_tilt"+str(round(tilt,2))+"_det"+str(det)
                            Text += "#------------------#BackFlush Segment commands --------------------#" + "\n\n"
                            Text += "#------------------#Ring 1 commands --------------------#" + "\n\n"
                            Text += "/Ring1/LightGuideLowerConeBackAngle 22 deg" + "\n"
                            Text += "/Ring1/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring1/LightGuideLowerInterface 75 mm" + "\n"
                            Text += "/Ring1/LightGuideMiddleBox 410 mm" + "\n"
                            Text += "/Ring1/LightGuideUpperInterface 251 mm" + "\n"
                            Text += "/Ring1/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring1/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring1/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring1/LightGuideQuartzInterfaceOpeningX 17.7 cm" + "\n"
                            Text += "/Ring1/LightGuideQuartzInterfaceOpeningZ 2.7 cm" + "\n"
                            Text += "/Ring1/QuartzSizeZ 20 mm" + "\n"
                            Text += "/Ring1/QuartzSizeX 169 mm" + "\n"
                            Text += "/Ring1/QuartzSizeY 20 mm" + "\n"  
                            Text += "/Ring1/QuartzRotX -3 deg" + "\n"              
                            Text += "/Ring1/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring1/SetCenterPositionInY 270.7 mm" + "\n"
                            Text += "/Ring1/SetCenterPositionInZ 1923.94 mm" + "\n"
                            Text += "/Ring1/PolarRotation 3 deg" + "\n"
                            Text += "/Ring1/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring1/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 2 commands --------------------#" + "\n\n"
                            Text += "/Ring2/LightGuideLowerConeBackAngle 22 deg" + "\n"
                            Text += "/Ring2/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring2/LightGuideLowerInterface 75 mm" + "\n"
                            Text += "/Ring2/LightGuideMiddleBox 400 mm" + "\n"
                            Text += "/Ring2/LightGuideUpperInterface 205 mm" + "\n"
                            Text += "/Ring2/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring2/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring2/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring2/LightGuideQuartzInterfaceOpeningX 18.7 cm" + "\n"
                            Text += "/Ring2/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                            Text += "/Ring2/QuartzSizeZ 20 mm" + "\n"
                            Text += "/Ring2/QuartzSizeX 179 mm" + "\n"
                            Text += "/Ring2/QuartzSizeY 60 mm" + "\n"   
                            Text += "/Ring2/QuartzRotX -3 deg" + "\n"
                            Text += "/Ring2/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring2/SetCenterPositionInY 292.8 mm" + "\n"
                            Text += "/Ring2/SetCenterPositionInZ 1645.6 mm" + "\n"
                            Text += "/Ring2/PolarRotation 3 deg" + "\n"
                            Text += "/Ring2/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring2/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 3 commands --------------------#" + "\n\n"
                            Text += "/Ring3/LightGuideLowerConeBackAngle 22 deg" + "\n"
                            Text += "/Ring3/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring3/LightGuideLowerInterface 75 mm" + "\n"
                            Text += "/Ring3/LightGuideMiddleBox 300 mm" + "\n"
                            Text += "/Ring3/LightGuideUpperInterface 259 mm" + "\n"
                            Text += "/Ring3/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring3/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring3/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring3/LightGuideQuartzInterfaceOpeningX 19.8 cm" + "\n"
                            Text += "/Ring3/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                            Text += "/Ring3/QuartzSizeZ 20 mm" + "\n"
                            Text += "/Ring3/QuartzSizeX 190 mm" + "\n"
                            Text += "/Ring3/QuartzSizeY 60 mm" + "\n"   
                            Text += "/Ring3/QuartzRotX -3 deg" + "\n"
                            Text += "/Ring3/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring3/SetCenterPositionInY 329.8 mm" + "\n"
                            Text += "/Ring3/SetCenterPositionInZ 1371.51 mm" + "\n"
                            Text += "/Ring3/PolarRotation 3 deg" + "\n"
                            Text += "/Ring3/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring3/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 4 commands --------------------#" + "\n\n"
                            Text += "/Ring4/LightGuideLowerConeBackAngle 22 deg" + "\n"
                            Text += "/Ring4/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                            Text += "/Ring4/LightGuideLowerInterface 75 mm" + "\n"
                            Text += "/Ring4/LightGuideMiddleBox 200 mm" + "\n"
                            Text += "/Ring4/LightGuideUpperInterface 253 mm" + "\n"
                            Text += "/Ring4/LightGuideQuartzToPMTOffset 3 mm" + "\n"
                            Text += "/Ring4/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring4/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring4/LightGuideQuartzInterfaceOpeningX 22.1 cm" + "\n"
                            Text += "/Ring4/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                            Text += "/Ring4/QuartzSizeZ 20 mm" + "\n"
                            Text += "/Ring4/QuartzSizeX 213 mm" + "\n"
                            Text += "/Ring4/QuartzSizeY 120 mm" + "\n"  
                            Text += "/Ring4/QuartzRotX -3 deg" + "\n"      
                            Text += "/Ring4/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring4/SetCenterPositionInY 366.9 mm" + "\n"
                            Text += "/Ring4/SetCenterPositionInZ 1092.08 mm" + "\n"
                            Text += "/Ring4/PolarRotation 3 deg" + "\n"
                            Text += "/Ring4/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring4/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 5 FF commands --------------------#" + "\n\n"
                            Text += "/Ring5/LightGuideLowerConeBackAngle 19 deg" + "\n"
                            Text += "/Ring5/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring5/LightGuideLowerInterface 90 mm" + "\n"
                            Text += "/Ring5/LightGuideMiddleBox 0.001 mm" + "\n"
                            Text += "/Ring5/LightGuideUpperInterface 329.5 mm" + "\n"
                            Text += "/Ring5/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring5/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring5/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring5/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                            Text += "/Ring5/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                            Text += "/Ring5/QuartzSizeZ 17 mm" + "\n"
                            Text += "/Ring5/QuartzSizeX 80 mm" + "\n"
                            Text += "/Ring5/QuartzSizeY 140 mm" + "\n" 
                            Text += "/Ring5/QuartzRotX -3 deg" + "\n"
                            Text += "/Ring5/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring5/SetCenterPositionInY 435.3 mm" + "\n"
                            Text += "/Ring5/SetCenterPositionInZ 651.64 mm" + "\n"
                            Text += "/Ring5/PolarRotation 3 deg" + "\n"
                            Text += "/Ring5/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring5/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 5 BF1 commands --------------------#" + "\n\n"
                            Text += "/Ring6/LightGuideLowerConeBackAngle 19 deg" + "\n"
                            Text += "/Ring6/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring6/LightGuideLowerInterface 90 mm" + "\n"
                            Text += "/Ring6/LightGuideMiddleBox 0.001 mm" + "\n"
                            Text += "/Ring6/LightGuideUpperInterface 329.5 mm" + "\n"
                            Text += "/Ring6/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring6/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring6/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring6/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                            Text += "/Ring6/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                            Text += "/Ring6/QuartzSizeZ 17 mm" + "\n"
                            Text += "/Ring6/QuartzSizeX 80 mm" + "\n"
                            Text += "/Ring6/QuartzSizeY 140 mm" + "\n" 
                            Text += "/Ring6/QuartzRotX -3 deg" + "\n"
                            Text += "/Ring6/SetCenterPositionInX -86.7 mm" + "\n"
                            Text += "/Ring6/SetCenterPositionInY 427.4 mm" + "\n"
                            Text += "/Ring6/SetCenterPositionInZ 802.47 mm" + "\n"
                            Text += "/Ring6/PolarRotation 3 deg" + "\n"
                            Text += "/Ring6/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring6/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 5 BF2 commands --------------------#" + "\n\n"
                            Text += "/Ring7/LightGuideLowerConeBackAngle 19 deg" + "\n"
                            Text += "/Ring7/LightGuideLowerConeFrontAngle 18 deg" + "\n"
                            Text += "/Ring7/LightGuideLowerInterface 90 mm" + "\n"
                            Text += "/Ring7/LightGuideMiddleBox 0.001 mm" + "\n"
                            Text += "/Ring7/LightGuideUpperInterface 329.5 mm" + "\n"
                            Text += "/Ring7/LightGuideQuartzToPMTOffset -2 mm" + "\n"
                            Text += "/Ring7/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring7/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring7/LightGuideQuartzInterfaceOpeningX 8.8 cm" + "\n"
                            Text += "/Ring7/LightGuideQuartzInterfaceOpeningZ 2.4 cm " + "\n"
                            Text += "/Ring7/QuartzSizeZ 17 mm" + "\n"
                            Text += "/Ring7/QuartzSizeX 80 mm" + "\n"
                            Text += "/Ring7/QuartzSizeY 140 mm" + "\n" 
                            Text += "/Ring7/QuartzRotX -3 deg" + "\n"
                            Text += "/Ring7/SetCenterPositionInX 86.7 mm" + "\n"
                            Text += "/Ring7/SetCenterPositionInY 427.4 mm" + "\n"
                            Text += "/Ring7/SetCenterPositionInZ 802.47 mm" + "\n"
                            Text += "/Ring7/PolarRotation 3 deg" + "\n"
                            Text += "/Ring7/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring7/UpdateGeometry" + "\n\n"
                            Text += "#------------------#Ring 6 commands --------------------#" + "\n\n"
                            Text += "/Ring8/LightGuideLowerConeBackAngle 20 deg" + "\n"
                            Text += "/Ring8/LightGuideLowerConeFrontAngle 17 deg" + "\n"
                            Text += "/Ring8/LightGuideLowerInterface 83 mm" + "\n"
                            Text += "/Ring8/LightGuideMiddleBox 90 mm" + "\n"
                            Text += "/Ring8/LightGuideUpperInterface 163 mm" + "\n"
                            Text += "/Ring8/LightGuideQuartzToPMTOffset 0 mm" + "\n"
                            Text += "/Ring8/LightGuidePMTInterfaceOpeningX 7.0 cm" + "\n"
                            Text += "/Ring8/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                            Text += "/Ring8/LightGuideQuartzInterfaceOpeningX 26.8 cm" + "\n"
                            Text += "/Ring8/LightGuideQuartzInterfaceOpeningZ 2.7 cm " + "\n"
                            Text += "/Ring8/QuartzSizeZ 20 mm" + "\n"
                            Text += "/Ring8/QuartzSizeX 260 mm" + "\n"
                            Text += "/Ring8/QuartzSizeY 100 mm" + "\n"  
                            Text += "/Ring8/QuartzRotX -3 deg" + "\n"             
                            Text += "/Ring8/SetCenterPositionInX 0 mm" + "\n"
                            Text += "/Ring8/SetCenterPositionInY 517 mm" + "\n"
                            Text += "/Ring8/SetCenterPositionInZ 501.78 mm" + "\n"
                            Text += "/Ring8/PolarRotation 3 deg" + "\n"
                            Text += "/Ring8/AzimuthalRotation 0 deg" + "\n"
                            Text += "/Ring8/UpdateGeometry" + "\n\n"
                            Text += "#------------------#General commands --------------------#" + "\n\n"
                            Text += "/Generator/PrimaryParticle " + str(Particle) + "\n"
                            Text += "/Generator/EventHitRegion " + str(hr) + "\n"
                            Text += "/Generator/EventShift " + str(shift) + " mm" + "\n"
                            Text += "/Generator/SegmentHitPosX " + str(cutx) + " cm" + "\n"
                            Text += "/Generator/SegmentHitPosY " + str(cuty) + " cm" + "\n"
                            Text += "/Generator/BeamEnergy " + str(Energy) + "\n"
                            Text += "/Generator/BeamEnergyCut " + str(EnergyCut) + "\n"
                            Text += "/Generator/BeamSolidAngle " + str(sa) + "\n"
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

            
