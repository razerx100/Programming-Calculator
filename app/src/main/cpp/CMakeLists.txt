cmake_minimum_required(VERSION 3.10.2)

project("ProgrammingCalculator")

add_library(cppSource SHARED main.cpp )

find_library(log-lib log )

target_link_libraries(cppSource ${log-lib})