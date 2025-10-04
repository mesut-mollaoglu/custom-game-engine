cmake_minimum_required(VERSION 3.5.0)

project("Project" LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_HOME_DIRECTORY}/modules/")

find_package(GLFW3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(ASSIMP REQUIRED)

#Search for C/C++ source files
file(GLOB CXX_SOURCE_FILES
"${CMAKE_HOME_DIRECTORY}/*.cpp"
"${CMAKE_HOME_DIRECTORY}/*.c"
"${CMAKE_HOME_DIRECTORY}/*.inl"
"${CMAKE_HOME_DIRECTORY}/*.tcc"
"${CMAKE_HOME_DIRECTORY}/src/*.cpp"
"${CMAKE_HOME_DIRECTORY}/src/*.c"
"${CMAKE_HOME_DIRECTORY}/src/*.inl"
"${CMAKE_HOME_DIRECTORY}/src/*.tcc")

include_directories(SYSTEM "${CMAKE_HOME_DIRECTORY}/include/external")
link_directories("${CMAKE_HOME_DIRECTORY}/lib")

add_executable(main ${CXX_SOURCE_FILES})

target_link_libraries(main "glfw3dll" "assimp")