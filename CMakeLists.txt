cmake_minimum_required(VERSION 2.8)
project(face_detect_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES demo-2.cpp)
add_executable(face_detect_cpp ${SOURCE_FILES})

#target_link_libraries(dlib)
find_package(dlib REQUIRED)
target_link_libraries(${PROJECT_NAME} ${dlib_LIBS})