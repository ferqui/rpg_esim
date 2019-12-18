#!/bin/bash
set -e

source "/ros_entrypoint.sh"

cd /sim_ws/
catkin build esim_ros
alias ssim='source /setupeventsim.sh'
ssim
exec "$@"