cmake_minimum_required(VERSION 3.15)
project(min_swaps_to_make_palindrome)
set(CMAKE_CXX_STANDARD 17)

# to debug std::string type
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(min_swaps_to_make_palindrome main.cpp)
