﻿# CMakeList.txt : CMake project for Project_adi_gutman_leon_markovich, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.15)

project (Project_adi_gutman_leon_markovich)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options (/permissive-)
endif ()

add_executable (Project_adi_gutman_leon_markovich "")

add_subdirectory (include)
add_subdirectory (src)
add_subdirectory (resources)
add_subdirectory (sounds_Of_Objects)


configure_file (C:/SFML/SFML-2.5.1/bin/openal32.dll ${CMAKE_BINARY_DIR} COPYONLY)

set (SFML_STATIC_LIBRARIES TRUE)
set (SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package (SFML 2.5 COMPONENTS graphics REQUIRED)
find_package (SFML 2.5 COMPONENTS audio REQUIRED)

set_target_properties (sfml-main sfml-system sfml-window sfml-graphics sfml-audio sfml-network PROPERTIES MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)

target_link_libraries (Project_adi_gutman_leon_markovich sfml-graphics sfml-main)
target_link_libraries (Project_adi_gutman_leon_markovich sfml-audio sfml-main)

