#!/bin/bash -ev

curl -O -J -L https://sourceforge.net/projects/genode/files/genode-toolchain/17.05/genode-toolchain-17.05-x86_64.tar.xz
sudo tar -xf genode-toolchain-17.05-x86_64.tar.xz -C /

genode-x86-gcc --version

echo "Start $(date)"
echo "Args: $*"
echo "Uname: $(uname -a)"
cat /proc/cpuinfo
echo "End $(date)"
