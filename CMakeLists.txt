cmake_minimum_required(VERSION 3.5)
project(project_name)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/include)

link_directories(/usr/local/lib)

add_executable(project_name main.cpp)

target_link_libraries(project_name raylib) 
