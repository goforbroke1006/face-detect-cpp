#!/usr/bin/env bash

#mkdir -p build && cd build
#cmake ..
#cmake --build .

mkdir -p build && cd build
g++ -DDLIB_JPEG_SUPPORT -DDLIB_PNG_SUPPORT \
    -std=c++11 \
    -o face_detect_cpp_demo_1 \
    -lpthread -lX11 -ljpeg -lpng -lz \
    ~/dlib/dlib/all/source.cpp ./../demo-1.cpp


./face_detect_cpp_demo_1 ./../shape_predictor_68_face_landmarks.dat \
    ./../samples/images/1.jpg \
    ./../samples/images/2.jpg \
    ./../samples/images/3.jpg