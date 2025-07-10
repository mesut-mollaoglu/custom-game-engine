cmake_minimum_required(VERSION 3.5.0)

project("Project" LANGUAGES C CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_HOME_DIRECTORY}/modules/")

find_package(GLFW3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(ASSIMP REQUIRED)

include_directories(SYSTEM "${CMAKE_HOME_DIRECTORY}/include")
link_directories("${CMAKE_HOME_DIRECTORY}/lib")

add_executable(main "${CMAKE_HOME_DIRECTORY}/example.cpp" "${CMAKE_HOME_DIRECTORY}/src/glad.c")

target_link_libraries(main "glfw3dll" "assimp")