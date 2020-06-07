cmake_minimum_required(VERSION 3.15)
project(min_deletions_to_make_frequency_of_each_letter_unique)
set(CMAKE_CXX_STANDARD 17)

# to debug std::string type
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG")

add_executable(min_deletions_to_make_frequency_of_each_letter_unique main.cpp)
