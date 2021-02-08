cmake_minimum_required(VERSION 3.10.2)

project("ProgrammingCalculator")

include_directories(Calculator)

file(GLOB SRC Calculator/*.cpp)

add_library(c-lib SHARED javaWrapper.cpp ${SRC})

find_library(log-lib log )

target_link_libraries(c-lib ${log-lib})
