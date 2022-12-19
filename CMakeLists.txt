cmake_minimum_required(VERSION 2.8)
project(LogicSim)


file( GLOB_RECURSE  HELLO_SOURCES   src/*.cpp)
file( GLOB_RECURSE  HELLO_HEADERS   include/*.h)

message("les fichiers .cpp:" ${HELLO_SOURCES})
message("les fichiers .h:" ${HELLO_HEADERS})

include_directories( include)
add_library(logicsimlib SHARED ${HELLO_SOURCES})
add_executable(LOGIC apps/main.cpp)
target_link_libraries(LOGIC logicsimlib)

