cmake_minimum_required(VERSION 3.14)
project(irulan)
set(CMAKE_CXX_STANDARD 17)

set(INCLUDES
        include/
        include/irulan
        include/irulan_e
        include/KHR
        include/glad
        include/SDL2
        )

set(SOURCES
        src/glad/glad.c

        src/irulan/Math/Matrix.cpp
        src/irulan/Math/Quaternion.cpp
        src/irulan/Math/Vector3.cpp

        src/irulan/Graph/VertexArray.cpp
        src/irulan/Graph/VertexBuffer.cpp
        src/irulan/Graph/Renderer.cpp
        src/irulan/Graph/Shader.cpp
        src/irulan/Graph/Texture.cpp
        src/irulan/Graph/Texture2D.cpp

        src/irulan/Misc/Timer.cpp

        src/irulan/App.cpp

        src/irulan_e/Graph2D/Text.cpp
        src/irulan_e/Graph2D/BitmapFont.cpp
        src/irulan_e/Graph2D/Sprite.cpp
        )

include_directories(${INCLUDES})
add_library(irulan ${SOURCES})

add_subdirectory(test)