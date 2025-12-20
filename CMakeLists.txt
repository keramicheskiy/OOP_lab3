cmake_minimum_required(VERSION 3.10)
project(Figures)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)
enable_testing()
include(GoogleTest)

find_package(fmt REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(MAIN_SOURCE main.cpp)

set(TEST_SOURCE tests.cpp)

set(LIB_SOURCES
    source/figure.cpp
    source/point.cpp
    source/rectangle.cpp
    source/rhombus.cpp
    source/trapezoid.cpp
    source/figurearray.cpp
    source/pointarray.cpp
    source/pointpairarray.cpp
)

add_library(figures STATIC ${LIB_SOURCES})
target_include_directories(figures PUBLIC include)

add_executable(main ${MAIN_SOURCE} ${LIB_SOURCES})
target_link_libraries(main PRIVATE figures fmt::fmt)

add_executable(tests ${TEST_SOURCE} ${LIB_SOURCES})
target_link_libraries(tests PUBLIC figures gtest_main fmt::fmt)

gtest_discover_tests(tests)
