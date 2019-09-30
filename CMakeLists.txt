cmake_minimum_required(VERSION 3.12)
project(ieeextreme_prep)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(ieeextreme_prep spiralMatrix.cpp)

target_link_libraries(ieeextreme_prep Eigen3::Eigen)