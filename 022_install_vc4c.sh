#!/bin/sh -x
R=v0.4-3
D=20190206
U=https://github.com/thortex/rpi3-vc4cl/releases/download/
F=vc4c_${R}-${D}_armhf.deb
wget -c $U$R/$F
sudo dpkg -i $F
