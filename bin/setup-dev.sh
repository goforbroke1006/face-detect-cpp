#!/usr/bin/env bash


# CentOS
if [ -f /etc/redhat-release ]; then
    sudo yum install -y cmake
fi


# Ubuntu
if [ -f /etc/lsb-release ]; then
    sudo apt-get install -y bzip2

    sudo apt-get install -y build-essential cmake pkg-config
    sudo apt-get install -y libx11-dev libatlas-base-dev
    sudo apt-get install -y libgtk-3-dev libboost-python-dev
fi


# Download and prepare predictor
wget http://dlib.net/files/shape_predictor_68_face_landmarks.dat.bz2
bzip2 -d shape_predictor_68_face_landmarks.dat.bz2


# Install DLIB
cd ~/

wget http://dlib.net/files/dlib-19.6.tar.bz2
tar xvf dlib-19.6.tar.bz2
rm -f dlib-19.6.tar.bz2

mv dlib-19.6/ dlib/ && cd dlib/
mkdir build && cd build

cmake ..
cmake --build . --config Release
sudo make install
sudo ldconfig
cd ..