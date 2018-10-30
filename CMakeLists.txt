cmake_minimum_required(VERSION 3.10)
enable_testing()
# project
project("xorshit_test")
# option
add_definitions(
        -std=c++17
        -Wall
        -Wextra)
# show Setting
message("C Compiler ID: " ${CMAKE_C_COMPILER_ID})
message("CXX Compiler ID: " ${CMAKE_CXX_COMPILER_ID})
message("CMake System Name: " ${CMAKE_SYSTEM_NAME})
# gtest
find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest)
message("gtest c-flags: " ${GTEST_CFLAGS})
message("gtest ld-flags: " ${GTEST_LDFLAGS})
# include directory
include_directories(
        ${Boost_INCLUDE_DIR}
        ${CMAKE_HOME_DIRECTORY}/include)
# unittest
add_executable(
        unittest
        test/main.cpp)
target_link_libraries(
        unittest
        ${GTEST_LDFLAGS})
target_compile_options(
        unittest
        PUBLIC
        ${GTEST_CFLAGS})
# execute test
add_test(
        NAME unittest
        COMMAND unittest)
