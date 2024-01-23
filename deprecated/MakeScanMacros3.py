import random
import os
import numpy as np

#This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
#This script will also produce a bash script at the end, called "StartRuns" that can be used to run all of the generated macros at the same time.
#Care should be taken with respect to the number of variations. Each simulation run takes about 1GB of memory. On my own machine with 20 cores and 15 GB Memory + 15 GB Swap
#I can comfortably run about 20 such processes at a time.

runscript = "#!/bin/bash\n\n"
#datadir =  "../data/February2022/Ring5LGAngleParamScan/" # with respect to the sim executable directory - change this to preferred dir
datadir =  "R6ParamScan/"
OutputFilePrefix = "MOLLEROpt_Scan"                      # String that starts all the output files from this script (all macro files and root output files)
RunID = 2  #Set this to distinguish scans - the same ID is assigned to each run in this scan - see below for additional run identifiers within the scan

#Fixed values
QWidth = 260  #mm
QHeight = 100 #mm                     This does not count the segment with the 45* cut. That part has max height equal to quartz thickness (qt parameter below)
QLGOInterfOpening = QWidth + 8  #mm   This is the opening where the quartz and light guide meet. The extra space is dictated by CAD design
#LightGuideLength = 243  #mm          This is the total guide length, fixed for each module by the detector tiling (location) and the cathode position
LGPMTInterfaceOpening = 70 #mm        This is fixed by the PMT size, which is 3 inches for the main detector 
QuartzBevelSize = 0.5 #mm             This should be as small as possible - 0 is desirable but not peferred by manufacturer
QuartzRotX = -3  #degrees             This is the ralative rotation between the quartz and the light guide. It is optimized to minimize background in the LG
PolarRotation = 3  #degress           This counter rotates the detector module so that the electrons are nomarlly incident on the quartz. Opposite to former
QuartzRadDamage = 170 #MRad           This should be the peak radiation damage in a tile. This is normally turned off and currently the wrong damage level until we get new data from Dustin
BoxHeight = 90 #mm                    This controls the height of the box between the upper and lower cone
Energy = 8000 #MeV		      This sets the energy of the beam

RndSeed1 = random.randrange(300000, 600000)
RndSeed2 = random.randrange(600001, 900000)

NumEvents = [100,100000,100000,100000,100000,100,100,100000,100000]   #Number of events on region 1-9 involving the quartz, lower guide funnel, and upper guide funnel - vary to taste ... 

                                   #Regions 8 & 9 are the vertical and horizontal quartz cuts respectively
                                   #The LG funnel regions can run many more events than the quartz since not many photons are generated there


#If new parameters are to be varied, implement a new nested loop below.
#Presently we have
#ba = LightGuideLowerConeBackAngle   - downstream angle 
#fa = LightGuideLowerConeFrontAngle  - upstream angle
#li = LightGuideLowerInterface       - length of the lower guide cone
#qt = QuartzSizeZ                    - quartz thickness in beam direction
#of = LightGuideQuartzToPMTOffset    - offset of PMT wrt. quartz in the beam direction
#lo - LightGuideUpperInterface       - length of light guide overall (not including the box)

#The following parameters control the beam
#hr = Electron hit region            - quartz, lower cone/funnel, or upper cone/funnel
#cut = quartz segmentation           - segment of quartz to hit. Location and size of segment determined by total number of segments, which is adjusted in src/MOLLEROptPrimaryGeneratorAction.cc
#theta/phi = beam angles             - controls the angle of the beam about the normal to the quartz. These are currently disabled and do nothing
#sa = Solid angle of beam            - controls the angular spread of the beam about the z-axis (beam axis)

#Refer to the detector limits presentation for details on these parameters.
#The correspondence with parameters specified there is:
#ba = a2
#fa = a1
#li = d3
#qt = d4 - 7 mm
#of = d6
#lo = d2



#Loop over values (to fix a variable set the start and stop both to the desired value)
ba_start = 20 #degrees
ba_stop = 20  #degrees
ba_step = 1  

fa_start = 17 #degrees 
fa_stop = 17 #degrees
fa_step = 1

li_start = 83 #mm
li_stop = 83  #mm
li_step = 1

qt_start = 20 #mm
qt_stop = 20 #mm
qt_step = 1

of_start = 0 #mm
of_stop = 0  #mm
of_step = 2

lo_start = 163 #mm
lo_stop = 163 #mm
lo_step = 1

hr_start = 5
hr_stop = 5
hr_step = 1

cut_start = 10 #Value does not matter if hr != 7,8. Cuts currently span from 0 to 9 (The quartz is broken into 10 segments either horizontally or vertically, but not both yet)
cut_stop = 10 #
cut_step = 1

sa_start = 0 #degrees
sa_stop =0 #
sa_step = 5  #

theta = 0 #degrees
phi = 0   #degrees

text_root = ""
for ba in np.arange(ba_start,ba_stop+ba_step,ba_step):
    for fa in np.arange(fa_start,fa_stop+fa_step,fa_step):
        for li in np.arange(li_start,li_stop+li_step,li_step):
            for qt in np.arange(qt_start,qt_stop+qt_step,qt_step):
                for of in np.arange(of_start,of_stop+of_step,of_step):
                    for hr in np.arange(hr_start,hr_stop+hr_step,hr_step):
			for lo in np.arange(lo_start,lo_stop+lo_step,lo_step):
			    for cut in np.arange(cut_start,cut_stop+cut_step,cut_step):
                                for sa in np.arange(sa_start,sa_stop+sa_step,sa_step):
                                    Text = ""
                                    FileIDString = "_sa"+str(sa)+"_cut"+str(cut)+"_fA"+str(fa)+"_bA"+str(ba)+"_hR"+str(hr)+"_lI"+str(li)+"_qT"+str(qt) + "_oF"+str(of) + "_lo"+str(lo)
                                    Text += "/Det/LightGuideLowerConeBackAngle " + str(ba) + " deg" + "\n"
                                    Text += "/Det/LightGuideLowerConeFrontAngle " + str(fa) + " deg" + "\n"
                                    Text += "/Det/LightGuideLowerInterface "+ str(li) + " mm" + "\n"
                                    Text += "/Det/LightGuideUpperInterface " + str(lo) + " mm" + "\n"
                                    Text += "/Det/LightGuideMiddleBox " + str(BoxHeight) + " mm" + "\n"
                                    Text += "/Det/LightGuidePMTInterfaceOpeningX " + str(LGPMTInterfaceOpening) + " mm" + "\n" 
                                    Text += "/Det/LightGuidePMTInterfaceOpeningZ " + str(LGPMTInterfaceOpening) + " mm" + "\n" 
                                    Text += "/Det/LightGuideQuartzInterfaceOpeningX " + str(QLGOInterfOpening) + " mm" + "\n" 
                                    Text += "/Det/LightGuideQuartzInterfaceOpeningZ " + str(qt+7) + " mm" + "\n" 
                                    Text += "/Det/QuartzSizeX " + str(QWidth) + " mm" + "\n"
                                    Text += "/Det/QuartzSizeY " + str(QHeight) + " mm" + "\n"
                                    Text += "/Det/QuartzSizeZ " + str(qt) + " mm" + "\n"
                                    Text += "/Det/QuartzBevelSize " + str(QuartzBevelSize) + " mm" + "\n"
                                    Text += "/Det/QuartzRotX " + str(QuartzRotX) + " deg" + "\n"   
                                    Text += "/Det/PolarRotation " + str(PolarRotation) + " deg" + "\n" 
                                    Text += "/Det/LightGuideQuartzToPMTOffset " + str(of) + " mm" + "\n"
                                    Text += "#/Det/SetSegmentedRadDamageFlag" + "\n"  #currently turned off 
                                    Text += "#/MOLLEROpt/QuartzRadDamage " + str(QuartzRadDamage) + "\n"  #currently turned off
                                    Text += "/Det/UpdateGeometry" + "\n"
                                    Text += "/Generator/EventHitRegion "+str(hr) + "\n"
			            Text += "/Generator/QuartzHitRegion "+str(cut) + "\n"
                                    Text += "/Generator/BeamTheta "+str(theta) + "\n"
                                    Text += "/Generator/BeamPhi "+str(phi) + "\n"
                                    Text += "/Generator/BeamSolidAngle "+str(sa) + "\n"
				    Text += "/Generator/BeamEnergy "+str(Energy) + "\n"
                                    Text += "/RunAction/SetID " + str(RunID) + "\n"
                                    Text += "/RunAction/SetOutputName " + FileIDString + "\n"
                                    Text += "/random/setSeeds " + str(RndSeed1) + " " + str(RndSeed2) + "\n"
                                    Text += "/run/beamOn " + str(NumEvents[hr-1]) + "\n"
			            text_root += "/lustre19/expphy/volatile/halla/moller12gev/jonmott/2023-sims/mod-reflectivity-studies/20mm-mylar-tosoh/build/rootfiles/" + FileIDString + "_000"+str(RunID) + ".root" + "\n"			      

                                    FileName = OutputFilePrefix + FileIDString + "_000"+str(RunID) + ".mac"
                                    fout = open(datadir+FileName, "w")
                                    fout.write(Text)
                                    fout.close()
                                    runscript += "./MOLLEROpt " + datadir + FileName + " > " + datadir + OutputFilePrefix + FileIDString + "_000"+str(RunID) + ".out" + " & \n"


scfile = open("StartRuns","w")
scfile.write(runscript)
scfile.close()
files_dat = open("files.dat","w")
files_dat.write(text_root)
files_dat.close()
        





