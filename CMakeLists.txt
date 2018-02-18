cmake_minimum_required(VERSION 3.6)
project(Lissajous)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib/x64)

set(SOURCE_FILES src/main.cpp src/Screen.cpp src/Screen.h src/ConsoleMenu.cpp src/ConsoleMenu.h src/Curve.cpp src/Curve.h src/EventHandler.cpp src/EventHandler.h)
add_executable(Lissajous ${SOURCE_FILES})
target_link_libraries(Lissajous SDL2main SDL2)