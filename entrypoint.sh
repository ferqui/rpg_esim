#!/bin/bash
set -e

source "/ros_entrypoint.sh"
source "/setupeventsim.sh"

exec "$@"