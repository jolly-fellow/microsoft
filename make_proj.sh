#!/bin/bash
# ------------------------------------------------------
# make new project
# ------------------------------------------------------


if [ ! -d $1 ]; then
  mkdir $1
fi

cp ./LICENSE ./$1/
cp ./README.md ./$1/
cp ./main.cpp ./$1/
cp ./.gitignore ./$1/

cd $1

echo "cmake_minimum_required(VERSION 3.15)" > CMakeLists.txt
echo "project($1)" >> CMakeLists.txt

echo "set(CMAKE_CXX_STANDARD 17)" >> CMakeLists.txt

echo "add_executable($1 main.cpp)" >> CMakeLists.txt