cmake_minimum_required(VERSION 3.19)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DesignPatterns)
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/src 
)

file(GLOB all_srcs
    "main.cpp"
    "src/Composite/BaseComponents.h"
    "src/Composite/BaseCompositeComponents.h"
    "src/Composite/Components.h"
    "src/Strategy/Context.h"
    "src/Strategy/Strategy.h")

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    option(ProjectTests "build tests (or no)" ON)
    if (ProjectTests)
        add_library(example_tests ${all_srcs})
        enable_testing()
        add_subdirectory(gtests)
    endif()
endif()

add_executable(DesignPatterns ${all_srcs})

target_compile_options(DesignPatterns PRIVATE "-Wall")