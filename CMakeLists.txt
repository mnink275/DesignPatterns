cmake_minimum_required(VERSION 3.19)

project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

#add_library(header_lib STATIC ${PROJECT_SOURCE_DIR}/src/somecpp.cpp)

# target_include_directories(header_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(DesignPatterns
               "src/CompositePattern/BaseComponents.h"
               "src/CompositePattern/BaseCompositeComponents.h"
               "src/CompositePattern/Components.h"
               "main.cpp"
               )

if (CMAKE_GENERATOR MATCHES "Visual Studio 17 2022")
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT DesignPatterns)
endif()

# target_include_directories(DesignPatterns PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_compile_options(DesignPatterns PRIVATE "-Wall")
# target_link_libraries(UnorderedMap header_lib)