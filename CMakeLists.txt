cmake_minimum_required(VERSION 3.20)

project(tic-tac-toe_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
  src/vector_t.cc
)

add_executable(tic-tac-toe ${SOURCES})