from pathlib import Path
import os
import shlex
import sys

# Commands for using swif2
# swif2 create <workflow> : creates a workflow
# swif2 status <workflow> : Gives the status of your workflow
# swif2 run <workflow>    : Starts the jobs
# swif2 pause <workflow>  : Pauses the jobs
# For more details visit scicomp.jlab.org/docs/swif2

# If no workflow exists, run "swif2 create MOLLEROpt"
workflow = os.environ.get("SWIF_WORKFLOW", "MOLLEROpt")
output_prefix = "MOLLEROpt_Scan"
macro_dir = Path("MacroFolder")
jobs_dir = Path("jobs")
build_dir = Path(__file__).resolve().parent  # Build directory containing this script

tilt = 1.0
# Controls the tilt of the beam from the z-axis in degrees
data = 999
# Sets what data is stored in the rootfile

hr_start, hr_stop, hr_step = 2, 2, 1 
# 1 = tile center, 2 enables cutx & cuty, 3 is the Mainz BF segment scan (maybe defunct), 4 is a strip across the tile, 5 randomizes the beam tilt

cutx_start, cutx_stop, cutx_step = 0.0, 0.0, 5.0
# X moves across the width of the tiles (the long sides of R1->R4, R6), and 0 is the center. Units of mm

cuty_start, cuty_stop, cuty_step = 70.5, 70.5, 5.0
# Y moves the beam in the radial direction, starting at ~0.5 mm

ID_start, ID_stop, ID_step = 3, 3, 1
# Set this to distinguish identical runs (to prevent file overwrite issues when changing no other parameters)

det_start, det_stop, det_step = 5, 5, 1
# Sets which detector is being used


jobs_dir.mkdir(parents=True, exist_ok=True)


def frange(start, stop, step):
    current = start
    while current <= stop + 1e-12:
        yield round(current, 10)
        current += step


def write_job_script(script_path: Path, macro_path: Path, build_dir: Path) -> None:
    # Use absolute path for macro file
    macro_abs = macro_path.resolve()
    binary_abs = build_dir / "MOLLEROpt"
    
    script_path.write_text(
        "#!/bin/bash\n"
        "set -e\n"  # Exit on any error
        "set -u\n"  # Exit on undefined variable
        "set -o pipefail\n"  # Exit on pipe failure
        "\n"
        "echo \"Current working directory: $(pwd)\"\n"
        "echo \"Starting job at $(date)\"\n"
        "echo \"Hostname: $(hostname)\"\n"
        "\n"
        "# Verify binary and macro exist\n"
        f"echo \"Checking for binary at: {binary_abs}\"\n"
        f"if [ ! -f \"{binary_abs}\" ]; then\n"
        f"    echo \"ERROR: Binary not found at {binary_abs}\"\n"
        f"    exit 1\n"
        f"fi\n"
        f"echo \"Checking for macro at: {macro_abs}\"\n"
        f"if [ ! -f \"{macro_abs}\" ]; then\n"
        f"    echo \"ERROR: Macro not found at {macro_abs}\"\n"
        f"    exit 1\n"
        f"fi\n"
        "\n"
        f"# Run simulation\n"
        f"cd \"{build_dir}\"\n"
        "echo \"Working directory after cd: $(pwd)\"\n"
        f"echo \"Running MOLLEROpt with macro: {macro_abs}\"\n"
        f'"{binary_abs}" "{macro_abs}"\n'
        f"echo \"Job completed successfully at $(date)\"\n"
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
                        #sys.exit(f"ERROR: Macro file {macro_path} does not exist. Please run the macro generator first.")
                        continue

                    script_path = jobs_dir / f"{output_prefix}{file_id}.sh"
                    write_job_script(script_path, macro_path, build_dir)

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
