#!/bin/sh -x

git clone https://github.com/Oblomov/clinfo
cd clinfo
make
sudo cp clinfo /usr/local/bin
