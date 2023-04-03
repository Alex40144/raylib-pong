cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_STANDARD 17)

project(pong)
add_executable(${PROJECT_NAME}  main.cpp game.cpp Ball.cpp Paddle.cpp raylibWrapper.cpp vec2.h settings.h)

if (NOT TARGET raylib)
  find_package(raylib 2.5.0 REQUIRED)
endif()
target_link_libraries(${PROJECT_NAME} raylib)
