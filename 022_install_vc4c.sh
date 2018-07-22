#!/bin/sh -x
R=v0.4-2
U=https://github.com/thortex/rpi3-vc4cl/releases/download/
F=vc4c_${R}-1_armhf.deb
wget -c $U$R/$F
sudo dpkg -i $F
