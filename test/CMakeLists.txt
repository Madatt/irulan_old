cmake_minimum_required(VERSION 3.14)
project(irulan_test)

set(CMAKE_CXX_STANDARD 17)


include_directories(../include)
include_directories(${PROJECT_SOURCE_DIR})

if(WIN32)
    link_directories(lib)
endif()

add_executable(irulan_test main.cpp TestApp.cpp TestApp.h)

target_link_libraries(irulan_test ${PROJECT_SOURCE_DIR}/../cmake-build-debug/libirulan.a)

if(WIN32)
    target_link_libraries(irulan_test -lmingw32 -lSDL2main -lSDL2)
endif()

if(UNIX)
    target_link_libraries(irulan_test -ldl -lSDL2main -lSDL2)
endif()

