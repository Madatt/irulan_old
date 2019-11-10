cmake_minimum_required(VERSION 3.14)
project(irulan)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDES
        include/irulan
        )

set(SOURCES
        src/irulan/Math/Matrix.cpp
        src/irulan/Math/Quaternion.cpp
        src/irulan/Math/Vector3.cpp
        include/irulan/irulan.h)



include_directories(${INCLUDES})

add_library(irulan ${SOURCES})