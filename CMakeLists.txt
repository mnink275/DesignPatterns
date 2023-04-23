cmake_minimum_required(VERSION 3.15)

project(DesignPatterns LANGUAGES CXX)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

    if(CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DesignPatterns)
    endif()
endif()

include(FetchContent)

include_directories(
    ${PROJECT_SOURCE_DIR}/src
    ${PROJECT_SOURCE_DIR}/include 
)

file(GLOB allSrcs
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
    "${PROJECT_SOURCE_DIR}/include/*.h"
)

add_executable(DesignPatterns ${allSrcs})
target_include_directories(DesignPatterns PRIVATE ${PROJECT_SOURCE_DIR}/include/Composite)
target_include_directories(DesignPatterns PRIVATE ${PROJECT_SOURCE_DIR}/include/Strategy)
target_compile_options(DesignPatterns PRIVATE "-Wall")

if(BUILD_TESTING)
  add_subdirectory(gtests)
endif()