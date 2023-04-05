cmake_minimum_required(VERSION 3.19)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DesignPatterns)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include 
)

file(GLOB allSrcs
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/include/*.h"
)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(ProjectTests "build tests (or no)" ON)
    if (ProjectTests)
        add_library(example_tests ${allSrcs})
        enable_testing()
        add_subdirectory(gtests)
    endif()
endif()

add_executable(DesignPatterns ${allSrcs})
target_include_directories(DesignPatterns PRIVATE ${PROJECT_SOURCE_DIR}/include/Composite)
target_include_directories(DesignPatterns PRIVATE ${PROJECT_SOURCE_DIR}/include/Strategy)
target_compile_options(DesignPatterns PRIVATE "-Wall")