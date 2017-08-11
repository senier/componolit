#!/bin/bash -ev

echo "Start $(date)"
echo "Args: $*"
echo "Uname: $(uname -a)"
cat /proc/cpuinfo
echo "End $(date)"
