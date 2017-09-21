#!/usr/bin/env bash

cd ~/

wget http://dlib.net/files/dlib-19.6.tar.bz2
tar xvf dlib-19.6.tar.bz2
rm -f dlib-19.6.tar.bz2

cd dlib-19.6/
mkdir build
cd build

cmake ..
cmake --build . --config Release
sudo make install
sudo ldconfig
cd ..