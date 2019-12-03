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

        src/irulan/Graph/VertexArray.cpp
        src/irulan/Graph/VertexBuffer.cpp
        src/irulan/Graph/Shader.cpp
        src/irulan/Graph/Texture2D.cpp
        src/irulan/Graph/2D/Font/BitmapFont.cpp
        src/irulan/Graph/2D/Font/Text.cpp
        src/irulan/Graph/Render/RenderTarget.cpp
        src/irulan/Graph/2D/Quads.cpp
        src/irulan/Graph/3D/Mesh/MeshData.cpp

        src/irulan/System/Resources/Resource.cpp
        src/irulan/System/Resources/ResourceManager.cpp
        src/irulan/System/OpenGL/Debug.cpp
        src/irulan/System/OpenGL/GLTraits.cpp
        src/irulan/System/Resources/Loaders/MeshLoader.cpp
        src/irulan/System/Memory/BufferAllocator.cpp
        src/irulan/System/Memory/Buffer.cpp
        src/irulan/System/App.cpp

        src/irulan/Misc/Timer.cpp

        )

include_directories(${INCLUDES})
add_library(irulan ${SOURCES})

add_subdirectory(test)