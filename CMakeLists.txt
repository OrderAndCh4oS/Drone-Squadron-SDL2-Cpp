cmake_minimum_required(VERSION 3.9)
project(SDLTest)

set(CMAKE_CXX_STANDARD 11)

# Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDLTest_SOURCE_DIR}/cmake")
# Set an output directory for our binaries
set(BIN_DIR ${SDLTest_SOURCE_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc
# Also set debug/optimization flags depending on the build type. IDE users choose this when
# selecting the build mode in their IDE
if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_executable(SDLTest src/main.cpp src/main.h src/utilities/Logger.cpp src/utilities/Logger.h src/graphics/Texture.cpp src/graphics/Texture.h src/sdl_utilities/Deinit.cpp src/sdl_utilities/Deinit.h src/sdl_utilities/Init.cpp src/sdl_utilities/Init.h src/constants.h src/Game.cpp src/Game.h src/graphics/Resource.cpp src/graphics/Resource.h src/constants.cpp src/utilities/DeltaTime.cpp src/utilities/DeltaTime.h src/geometry/Vector.cpp src/geometry/Vector.h src/geometry/Point.cpp src/geometry/Point.h src/graphics/GameObject.cpp src/graphics/GameObject.h src/graphics/Particle.cpp src/graphics/Particle.h src/graphics/Drone.cpp src/graphics/Drone.h)

INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES})