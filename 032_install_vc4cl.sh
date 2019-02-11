#!/bin/sh -x
D=0.4-20190207
R=v0.4-3
U=https://github.com/thortex/rpi3-vc4cl/releases/download/
F=vc4cl_${D}_armhf.deb
wget -c $U$R/$F
sudo dpkg -i $F
