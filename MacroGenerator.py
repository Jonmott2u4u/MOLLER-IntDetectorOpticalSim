import os
import random
import numpy as np

# This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
# This script is different from MakeScanMacros3.py in that it was designed for a full segment (front or back flush) of the MOLLER main detector.
# At the time of making this script, the geometric parameters for the rings have been decided. The scannable parameters listed are connected to the beam's controls.

runscript = "#!/bin/bash\n\n"
datadir = "MacroFolder/"
OutputFilePrefix = "MOLLEROpt_Scan"
Detector = 1
data = 999 #Sets what data is stored in the rootfile. Can be 999, 0 or 1

beam_controls = {
    "Particle": 1,
    "Energy": 8000,
    "EnergyCut": 0,
    "NumEvents": 10000,
    "sa": 0,
    "tilt": 1.0,
    "tilt_dir": 90,
    "shift": 0,
}

#Looped parameters
hr_start, hr_stop, hr_step = 2, 2, 1

cutx_start, cutx_stop, cutx_step = 85.0, 85.0, 5.0

cuty_start, cuty_stop, cuty_step = 0.5, 0.5, 5.0

ID_start, ID_stop, ID_step = 1, 2, 1
#End of looped parameters

common_geometric_commands = [
    ("LightGuidePMTInterfaceOpeningX", "7.0 cm"),
    ("LightGuidePMTInterfaceOpeningZ", "7.0 cm"),
    ("QuartzRotX", "-3 deg"),
    ("PolarRotation", "3 deg"),
    ("AzimuthalRotation", "0 deg"),
    ("UpdateGeometry", ""),
]

det_configs = {
    1: (
        "Ring 1",
        {
            "LightGuideLowerConeBackAngle": "22 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "75 mm",
            "LightGuideMiddleBox": "410 mm",
            "LightGuideUpperInterface": "251 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "17.7 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "169 mm",
            "QuartzSizeY": "20 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "270.7 mm",
            "SetCenterPositionInZ": "1923.94 mm",
        },
    ),
    2: (
        "Ring 2",
        {
            "LightGuideLowerConeBackAngle": "22 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "75 mm",
            "LightGuideMiddleBox": "400 mm",
            "LightGuideUpperInterface": "205 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "18.7 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "179 mm",
            "QuartzSizeY": "60 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "292.8 mm",
            "SetCenterPositionInZ": "1645.6 mm",
        },
    ),
    3: (
        "Ring 3",
        {
            "LightGuideLowerConeBackAngle": "22 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "75 mm",
            "LightGuideMiddleBox": "300 mm",
            "LightGuideUpperInterface": "259 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "19.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "190 mm",
            "QuartzSizeY": "60 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "329.8 mm",
            "SetCenterPositionInZ": "1371.51 mm",
        },
    ),
    4: (
        "Ring 4",
        {
            "LightGuideLowerConeBackAngle": "22 deg",
            "LightGuideLowerConeFrontAngle": "17 deg",
            "LightGuideLowerInterface": "75 mm",
            "LightGuideMiddleBox": "200 mm",
            "LightGuideUpperInterface": "253 mm",
            "LightGuideQuartzToPMTOffset": "3 mm",
            "LightGuideQuartzInterfaceOpeningX": "22.1 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "213 mm",
            "QuartzSizeY": "120 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "366.9 mm",
            "SetCenterPositionInZ": "1092.08 mm",
        },
    ),
    5: (
        "Ring 5 FF",
        {
            "LightGuideLowerConeBackAngle": "19 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "90 mm",
            "LightGuideMiddleBox": "0.001 mm",
            "LightGuideUpperInterface": "329.5 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "8.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.4 cm",
            "QuartzSizeZ": "17 mm",
            "QuartzSizeX": "80 mm",
            "QuartzSizeY": "140 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "435.3 mm",
            "SetCenterPositionInZ": "651.64 mm",
        },
    ),
    6: (
        "Ring 5 BF1",
        {
            "LightGuideLowerConeBackAngle": "19 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "90 mm",
            "LightGuideMiddleBox": "0.001 mm",
            "LightGuideUpperInterface": "329.5 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "8.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.4 cm",
            "QuartzSizeZ": "17 mm",
            "QuartzSizeX": "80 mm",
            "QuartzSizeY": "140 mm",
            "SetCenterPositionInX": "-86.7 mm",
            "SetCenterPositionInY": "427.4 mm",
            "SetCenterPositionInZ": "802.47 mm",
        },
    ),
    7: (
        "Ring 5 BF2",
        {
            "LightGuideLowerConeBackAngle": "19 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "90 mm",
            "LightGuideMiddleBox": "0.001 mm",
            "LightGuideUpperInterface": "329.5 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "LightGuideQuartzInterfaceOpeningX": "8.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.4 cm",
            "QuartzSizeZ": "17 mm",
            "QuartzSizeX": "80 mm",
            "QuartzSizeY": "140 mm",
            "SetCenterPositionInX": "86.7 mm",
            "SetCenterPositionInY": "427.4 mm",
            "SetCenterPositionInZ": "802.47 mm",
        },
    ),
    8: (
        "Ring 6",
        {
            "LightGuideLowerConeBackAngle": "20 deg",
            "LightGuideLowerConeFrontAngle": "17 deg",
            "LightGuideLowerInterface": "83 mm",
            "LightGuideMiddleBox": "90 mm",
            "LightGuideUpperInterface": "163 mm",
            "LightGuideQuartzToPMTOffset": "0 mm",
            "LightGuideQuartzInterfaceOpeningX": "26.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "260 mm",
            "QuartzSizeY": "100 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "517 mm",
            "SetCenterPositionInZ": "501.78 mm",
        },
    ),
}

text_root = []
os.makedirs(datadir, exist_ok=True)
if Detector not in det_configs:
    raise ValueError(f"Unknown Detector value: {Detector}")

label, det_params = det_configs[Detector]
main_det_lines = [
    f"/MainDet/{key} {value}" if value else f"/MainDet/{key}"
    for key, value in list(det_params.items()) + common_geometric_commands
]

for hr in np.arange(hr_start, hr_stop + hr_step, hr_step):
    for id in np.arange(ID_start, ID_stop + ID_step, ID_step):
        for cutx in np.arange(cutx_start, cutx_stop + cutx_step, cutx_step):
            for cuty in np.arange(cuty_start, cuty_stop + cuty_step, cuty_step):
                RndSeed1 = random.randrange(300000, 600000)
                RndSeed2 = random.randrange(600001, 900000)
                FileIDString = f"_hR{hr}_cutx{round(cutx,2)}_cuty{round(cuty,2)}_tilt{round(beam_controls['tilt'],2)}_det{Detector}_data{data}"
                lines = [
                    f"#------------------#{label} commands --------------------#",
                    "",
                    *main_det_lines,
                    "",
                    "#------------------#Beam commands --------------------#",
                    "",
                    f"/Generator/PrimaryParticle {beam_controls['Particle']}",
                    f"/Generator/EventShift {beam_controls['shift']} mm",
                    f"/Generator/BeamEnergy {beam_controls['Energy']}",
                    f"/Generator/BeamEnergyCut {beam_controls['EnergyCut']}",
                    f"/Generator/BeamSolidAngle {beam_controls['sa']} degree",
                    f"/Generator/BeamTiltAngle {beam_controls['tilt']} degree",
                    f"/Generator/BeamTiltDirection {beam_controls['tilt_dir']} degree",
                    f"/Generator/EventShift {beam_controls['shift']} mm",
                    f"/Generator/SegmentHitPosX {cutx} mm",
                    f"/Generator/SegmentHitPosY {cuty} mm",
                    f"/Generator/EventHitRegion {hr}",
                    "",
                    "#------------------#General commands --------------------#",
                    "",
                    f"/Storage/DetectorFocus {data}",
                    f"/RunAction/SetID {id}",
                    f"/RunAction/SetOutputName {FileIDString}",
                    f"/random/setSeeds {RndSeed1} {RndSeed2}",
                    "/vis/disable",
                    f"/run/beamOn {beam_controls['NumEvents']}",
                ]
                text = "\n".join(lines) + "\n"
                text_root.append(f"rootfiles/{FileIDString}_000{id}.root")
                FileName = f"{OutputFilePrefix}{FileIDString}_ID{id}.mac"
                with open(os.path.join(datadir, FileName), "w") as fout:
                    fout.write(text)
                runscript += f"./MOLLEROpt {datadir}{FileName} > {datadir}{OutputFilePrefix}{FileIDString}.out & \n"

with open("StartRuns", "w") as scfile:
    scfile.write(runscript)
with open("files.dat", "w") as files_dat:
    files_dat.write("\n".join(text_root) + "\n")

            
