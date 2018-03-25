cmake_minimum_required(VERSION 3.9)
project(DroneSquadron)

set(CMAKE_CXX_STANDARD 11)
#Use our modified FindSDL2* modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${DroneSquadron_SOURCE_DIR}/cmake")
set(BIN_DIR ${TwinklebearDevLessons_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Bump up warning levels appropriately for clang, gcc & msvc and build in debug mode
if (MSVC)
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else ()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif ()
else ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif ()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
include_directories(include)

find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIR})

add_executable(DroneSquadron src/main.cpp src/main.h src/utilities/Logger.cpp src/utilities/Logger.h src/graphics/Texture.cpp src/graphics/Texture.h src/sdl_utilities/Deinit.cpp src/sdl_utilities/Deinit.h src/sdl_utilities/Init.cpp src/sdl_utilities/Init.h src/constants.h src/Game.cpp src/Game.h src/graphics/Resource.cpp src/graphics/Resource.h src/constants.cpp src/utilities/DeltaTime.cpp src/utilities/DeltaTime.h src/geometry/Vector.cpp src/geometry/Vector.h src/geometry/Point.cpp src/geometry/Point.h src/graphics/GameObject.cpp src/graphics/GameObject.h src/graphics/Particle.cpp src/graphics/Particle.h src/graphics/Drone.cpp src/graphics/Drone.h src/geometry/Angle.cpp src/geometry/Angle.h src/ui/Panel.cpp src/ui/Panel.h src/ui/View.cpp src/ui/View.h src/ui/Button.cpp src/ui/Button.h src/buttons/TurnLeft.cpp src/buttons/TurnLeft.h src/buttons/TurnRight.cpp src/buttons/TurnRight.h src/utilities/FPS.cpp src/utilities/FPS.h src/utilities/Timer.cpp src/utilities/Timer.h)

target_link_libraries(DroneSquadron ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})

#add_subdirectory(src)

if (NOT ${PROJECT_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_BINARY_DIR})
    file(COPY "${PROJECT_SOURCE_DIR}/res" DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
endif()