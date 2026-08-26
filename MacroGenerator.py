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

Particle = 2      #Sets the primary particle type. 1 for electrons, 2 for muons
Energy = 1000     #Sets energy of primary particle in units of MeV. Only works for electrons. This is handled automatically for muons using a custom distribution
EnergyCut = 0     #Sets a minimum energy for primary particles to be accepted in units of MeV. Only works for muons

NumEvents = 100  #Number of events for each Hit Region (controlled by EventHitRegion variable)

shift = 0         #Shifts the particle spawn location by that much. What this affects is set in PrimaryGeneratorAction.cc. -125 for SayakStand

tilt_dir = 90     #Controls the direction of the beam tilt (units of degrees, 0 = x-axis, 90 = y-axis, rotation about z-axis)

#Scannable parameters (those that can be easily adjusted for each run)
hr_start = 2      #hr = 2 for this branch. This spawns particles at the US scint (scint1)
hr_stop = 2
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
ID_stop = 10
ID_step = 1

det = 999       #Sets the memory storage in the NTuple. 999 for nothing, 1 for events hitting ShowerMax, 0 for everything

text_root = ""
for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
    for id in np.arange(ID_start,ID_stop+ID_step,ID_step):
        for cutx in np.arange(cutx_start,cutx_stop+cutx_step,cutx_step):
            for cuty in np.arange(cuty_start,cuty_stop+cuty_step,cuty_step):
                RndSeed1 = random.randrange(300000, 600000) #Random seeds for simulation
                RndSeed2 = random.randrange(600001, 900000) #
                Text = ""
                FileIDString = "_hR"+str(hr)+"_tilt"+str(tilt)+"_cutx"+str(round(cutx,2))+"_cuty"+str(round(cuty,2))+"_det"+str(det)
                Text += "#------------------#Ring 6 commands --------------------#" + "\n\n"
                Text += "/ShowerMax/LightGuideLowerConeBackAngle 12.9 deg" + "\n"
                Text += "/ShowerMax/LightGuideLowerConeFrontAngle 12.9 deg" + "\n"
                Text += "/ShowerMax/LightGuideLowerInterface 67.462 mm" + "\n"
                Text += "/ShowerMax/LightGuideMiddleBox 0.01 mm" + "\n"
                Text += "/ShowerMax/LightGuideUpperInterface 250.52 mm" + "\n"
                Text += "/ShowerMax/LightGuideQuartzToPMTOffset 0 mm" + "\n"
                Text += "/ShowerMax/LightGuidePMTInterfaceOpeningX 26.6 cm" + "\n"
                Text += "/ShowerMax/LightGuidePMTInterfaceOpeningZ 7.0 cm" + "\n"
                Text += "/ShowerMax/LightGuideQuartzInterfaceOpeningX 26.6 cm" + "\n"
                Text += "/ShowerMax/LightGuideQuartzInterfaceOpeningZ 5.496 cm " + "\n"
                Text += "/ShowerMax/QuartzSizeZ 6 mm" + "\n"
                Text += "/ShowerMax/QuartzSizeX 265 mm" + "\n"
                Text += "/ShowerMax/QuartzSizeY 160 mm" + "\n"  
                Text += "/ShowerMax/TungstenSizeZ 8 mm" + "\n"
                Text += "/ShowerMax/TungstenSizeX 265 mm" + "\n"
                Text += "/ShowerMax/TungstenSizeY 160 mm" + "\n"
                Text += "/ShowerMax/QuartzRotX 0 deg" + "\n"             
                Text += "/ShowerMax/SetCenterPositionInX 0 mm" + "\n"
                Text += "/ShowerMax/SetCenterPositionInY 0 mm" + "\n"
                Text += "/ShowerMax/SetCenterPositionInZ 0 mm" + "\n"
                Text += "/ShowerMax/PolarRotation 0 deg" + "\n"
                Text += "/ShowerMax/AzimuthalRotation 0 deg" + "\n"
                Text += "/ShowerMax/UpdateGeometry" + "\n\n"
                Text += "#------------------#Scintillator commands --------------------#" + "\n\n"
                Text += "/Scint1/SetSizeX 30.5 cm" + "\n"
                Text += "/Scint1/SetSizeY 30.5 cm" + "\n"
                Text += "/Scint1/SetSizeZ 2.54 cm" + "\n"
                Text += "/Scint1/SetCenterPositionInX 0 mm" + "\n"
                Text += "/Scint1/SetCenterPositionInY 0 mm" + "\n"
                Text += "/Scint1/SetCenterPositionInZ -400 mm" + "\n"
                Text += "/Scint1/PolarRotation 0 deg" + "\n"
                Text += "/Scint1/AzimuthalRotation 0 deg" + "\n"
                Text += "/Scint1/UpdateGeometry" + "\n"
                Text += "/Scint2/SetSizeX 30.5 cm" + "\n"
                Text += "/Scint2/SetSizeY 30.5 cm" + "\n"
                Text += "/Scint2/SetSizeZ 2.54 cm" + "\n"
                Text += "/Scint2/SetCenterPositionInX 0 mm" + "\n"
                Text += "/Scint2/SetCenterPositionInY 0 mm" + "\n"
                Text += "/Scint2/SetCenterPositionInZ -400 mm" + "\n"
                Text += "/Scint2/PolarRotation 0 deg" + "\n"
                Text += "/Scint2/AzimuthalRotation 0 deg" + "\n"
                Text += "/Scint2/UpdateGeometry" + "\n"
                Text += "/Scint3/SetSizeX 30.5 cm" + "\n"
                Text += "/Scint3/SetSizeY 30.5 cm" + "\n"
                Text += "/Scint3/SetSizeZ 2.54 cm" + "\n"
                Text += "/Scint3/SetCenterPositionInX 0 mm" + "\n"
                Text += "/Scint3/SetCenterPositionInY 0 mm" + "\n"
                Text += "/Scint3/SetCenterPositionInZ -400 mm" + "\n"
                Text += "/Scint3/PolarRotation 0 deg" + "\n"
                Text += "/Scint3/AzimuthalRotation 0 deg" + "\n"
                Text += "/Scint3/UpdateGeometry" + "\n"
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

            
