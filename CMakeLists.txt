cmake_minimum_required(VERSION 3.10)
project(CameraRecorder)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)

add_executable(camera_recorder src/main.cpp)
target_link_libraries(camera_recorder ${OpenCV_LIBS})
