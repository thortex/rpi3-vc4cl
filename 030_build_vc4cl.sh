#!/bin/sh -x
sudo apt-get install libncurses5-dev
(cd VC4CL && \
	cmake . && \
	make && \
	sudo checkinstall -D \
	     --install=yes \
	     --pkgname=vc4cl \
	     --pkgversion=0.4 \
	     --provides=vc4cl)


