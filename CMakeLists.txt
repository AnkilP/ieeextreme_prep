cmake_minimum_required(VERSION 3.12)
project(ieeextreme_prep)

set(CMAKE_CXX_STANDARD 14)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(ieeextreme_prep tabu_search.cpp)

target_link_libraries(ieeextreme_prep Eigen3::Eigen)