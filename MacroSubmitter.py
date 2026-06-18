from pathlib import Path
import os
import shlex

workflow = os.environ.get("SWIF_WORKFLOW", "MOLLEROpt")
output_prefix = "MOLLEROpt_Scan"
macro_dir = Path("MacroFolder")
jobs_dir = Path("jobs")

tilt = 1.0
# Controls the tilt of the beam from the z-axis in degrees
data = 999
# Sets what data is stored in the rootfile

hr_start, hr_stop, hr_step = 2, 2, 1 
# 1 = tile center, 2 enables cutx & cuty, 3 is the Mainz BF segment scan (maybe defunct), 4 is a strip across the tile, 5 randomizes the beam tilt


cutx_start, cutx_stop, cutx_step = 85.0, 85.0, 5.0
# X moves across the width of the tiles (the long sides of R1->R4, R6), and 0 is the center. Units of mm

cuty_start, cuty_stop, cuty_step = 0.5, 0.5, 5.0
# Y moves the beam in the radial direction, starting at ~0.5 mm

ID_start, ID_stop, ID_step = 1, 2, 1
# Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)

det_start, det_stop, det_step = 1, 1, 1
# Sets which detector is being used


jobs_dir.mkdir(parents=True, exist_ok=True)


def frange(start, stop, step):
    current = start
    while current <= stop + 1e-12:
        yield round(current, 10)
        current += step


def write_job_script(script_path: Path, macro_path: Path) -> None:
    script_path.write_text(
        "#!/bin/bash\n"
        "echo \"Current working directory is $(pwd)\"\n"
        "source /etc/skel/.bashrc\n"
        "module reset\n"
        "module use /group/halla/modulefiles\n"
        "module load root/6.30.04 geant4/11.2.1\n"
        "export G4LEDATA=$GEANT4_DATA_DIR/G4EMLOW8.5\n"
        "env\n"
        "ldd ./MOLLEROpt\n"
        f"./MOLLEROpt {macro_path}\n"
    )
    script_path.chmod(0o755)


for hr in range(hr_start, hr_stop + hr_step, hr_step):
    for run_id in range(ID_start, ID_stop + ID_step, ID_step):
        for det in range(det_start, det_stop + det_step, det_step):
            for cutx in frange(cutx_start, cutx_stop, cutx_step):
                for cuty in frange(cuty_start, cuty_stop, cuty_step):
                    file_id = (
                        f"_hR{hr}_cutx{round(cutx, 2)}"
                        f"_cuty{round(cuty, 2)}_tilt{round(tilt, 2)}"
                        f"_det{det}_data{data}_ID{run_id}"
                    )
                    macro_path = macro_dir / f"{output_prefix}{file_id}.mac"
                    if not macro_path.exists():
                        continue

                    script_path = jobs_dir / f"{output_prefix}{file_id}.sh"
                    write_job_script(script_path, macro_path)

                    swif_command = [
                        "swif2",
                        "add-job",
                        workflow,
                        "-name",
                        f"{output_prefix}{file_id}",
                        "-time",
                        "24h",
                        "-ram",
                        "400M",
                        "-partition",
                        "production",
                        "-constraint",
                        "el9",
                        "-shell",
                        "/bin/bash",
                        "--",
                        str(script_path),
                    ]

                    print(" ".join(shlex.quote(arg) for arg in swif_command))
