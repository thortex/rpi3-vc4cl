#!/bin/sh -x
R=v0.4-20190207
U=https://github.com/thortex/rpi3-vc4cl/releases/download/
F=vc4cl_${R}-1_armhf.deb
wget -c $U$R/$F
sudo dpkg -i $F
