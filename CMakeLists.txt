cmake_minimum_required(VERSION 3.0)
project(RTSPStreamViewer)

# Set the C++ standard you wish to use (you could use C++11 or above)
set(CMAKE_CXX_STANDARD 14)

# Find OpenCV package in the system
find_package(OpenCV REQUIRED)

# Include directories for OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Define the executable to be generated
add_executable(RTSPStreamViewer main.cpp)

# Link OpenCV libraries with the executable
target_link_libraries(RTSPStreamViewer ${OpenCV_LIBS})