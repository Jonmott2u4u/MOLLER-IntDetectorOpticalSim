import os
import random
import numpy as np

# This script produces a series of G4 macros that vary a specified set of simulation parameters that are of relevance to the MOLLER detector design.
# At the time of making this script, the geometric parameters for the rings have been decided. The scannable parameters listed are connected to beam controls.

runscript = "#!/bin/bash\n\n"
datadir = "MacroFolder/"
OutputFilePrefix = "MOLLEROpt_Scan"
Particle = 1
Energy = 8000
EnergyCut = 0
NumEvents = [10000] * 9

hr_start, hr_stop, hr_step = 8, 8, 1
cut_start, cut_stop, cut_step = 0, 0, 1
sa_start, sa_stop, sa_step = 0, 0, 5
ID_start, ID_stop, ID_step = 1, 1, 1
det_start, det_stop, det_step = 1, 6, 1

# The detector configurations are defined once and reused for every macro.
det_configs = {
    1: (
        "Ring 1",
        {
            "LightGuideLowerConeBackAngle": "22 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "75 mm",
            "LightGuideMiddleBox": "400 mm",
            "LightGuideUpperInterface": "251 mm",
            "LightGuideQuartzInterfaceOpeningX": "17.7 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm ",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "169 mm",
            "QuartzSizeY": "30 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
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
            "LightGuideQuartzInterfaceOpeningX": "18.7 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm ",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "179 mm",
            "QuartzSizeY": "60 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
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
            "LightGuideQuartzInterfaceOpeningX": "19.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm ",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "190 mm",
            "QuartzSizeY": "60 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
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
            "LightGuideQuartzInterfaceOpeningX": "22.1 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm ",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "213 mm",
            "QuartzSizeY": "120 mm",
            "LightGuideQuartzToPMTOffset": "3 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
        },
    ),
    5: (
        "Ring 5 BF",
        {
            "LightGuideLowerConeBackAngle": "19 deg",
            "LightGuideLowerConeFrontAngle": "18 deg",
            "LightGuideLowerInterface": "90 mm",
            "LightGuideMiddleBox": "0.001 mm",
            "LightGuideUpperInterface": "329.5 mm",
            "LightGuideQuartzInterfaceOpeningX": "8.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.4 cm ",
            "QuartzSizeZ": "17 mm",
            "QuartzSizeX": "80 mm",
            "QuartzSizeY": "140 mm",
            "LightGuideQuartzToPMTOffset": "-2 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
        },
    ),
    6: (
        "Ring 6",
        {
            "LightGuideLowerConeBackAngle": "20 deg",
            "LightGuideLowerConeFrontAngle": "17 deg",
            "LightGuideLowerInterface": "83 mm",
            "LightGuideMiddleBox": "90 mm",
            "LightGuideUpperInterface": "163 mm",
            "LightGuideQuartzInterfaceOpeningX": "26.8 cm",
            "LightGuideQuartzInterfaceOpeningZ": "2.7 cm ",
            "QuartzSizeZ": "20 mm",
            "QuartzSizeX": "260 mm",
            "QuartzSizeY": "100 mm",
            "LightGuideQuartzToPMTOffset": "0 mm",
            "SetCenterPositionInX": "0 mm",
            "SetCenterPositionInY": "0 mm",
            "SetCenterPositionInZ": "0 mm",
        },
    ),
}

text_root = []
os.makedirs(datadir, exist_ok=True)
for hr in np.arange(hr_start, hr_stop + hr_step, hr_step):
    for sa in np.arange(sa_start, sa_stop + sa_step, sa_step):
        for id in np.arange(ID_start, ID_stop + ID_step, ID_step):
            for det in np.arange(det_start, det_stop + det_step, det_step):
                if det not in det_configs:
                    continue
                for cut in np.arange(cut_start, cut_stop + cut_step, cut_step):
                    RndSeed1 = random.randrange(300000, 600000)
                    RndSeed2 = random.randrange(600001, 900000)
                    FileIDString = f"_sa{sa}_hR{hr}_det{det}_cut{cut}"
                    label, params = det_configs[det]
                    lines = [f"#------------------#{label} Geometry --------------------#", ""]
                    lines += [f"/Det/{key} {value}" for key, value in params.items()]
                    lines += ["", *[
                        "/Det/QuartzRotX -3 deg",
                        "/Det/PolarRotation 3 deg",
                        "/Det/QuartzBevelSize 0.5 mm",
                        "/Det/LightGuidePMTInterfaceOpeningX 7.0 cm",
                        "/Det/LightGuidePMTInterfaceOpeningZ 7.0 cm",
                        "/Det/UpdateGeometry",
                        "",
                        f"/Generator/PrimaryParticle {Particle}",
                        f"/Generator/EventHitRegion {hr}",
                        f"/Generator/QuartzHitRegion {cut}",
                        f"/Generator/BeamEnergy {Energy}",
                        f"/Generator/BeamEnergyCut {EnergyCut}",
                        f"/Generator/BeamSolidAngle {sa}",
                        f"/RunAction/SetID {id}",
                        f"/RunAction/SetOutputName {FileIDString}",
                        f"/random/setSeeds {RndSeed1} {RndSeed2}",
                        "/vis/disable",
                        f"/run/beamOn {NumEvents[int(hr) - 1]}",
                    ]]
                    text = "\n".join(lines) + "\n"
                    text_root.append(f"rootfiles/{FileIDString}_000{id}.root")
                    file_name = f"{OutputFilePrefix}{FileIDString}_ID{id}.mac"
                    with open(os.path.join(datadir, file_name), "w") as fout:
                        fout.write(text)
                    runscript += f"./MOLLEROpt {datadir}{file_name} > {datadir}{OutputFilePrefix}{FileIDString}.out & \n"

with open("StartRuns", "w") as scfile:
    scfile.write(runscript)
with open("files.dat", "w") as files_dat:
    files_dat.write("\n".join(text_root) + "\n")
