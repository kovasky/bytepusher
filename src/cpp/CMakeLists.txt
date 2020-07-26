cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_FLAGS "-Wall")

add_executable(bytepusher src/cpp/cpu.cpp src/cpp/display.cpp src/cpp/main.cpp)

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

target_include_directories(bytepusher PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(bytepusher ${SDL2_LIBRARIES})
