cmake_minimum_required(VERSION 3.10.2)

project("ProgrammingCalculator")

include_directories(header)

add_library(c-lib SHARED asciiInput.cpp binaryInput.cpp decimalInput.cpp helper.cpp)

find_library(log-lib log )

target_link_libraries(c-lib ${log-lib})
