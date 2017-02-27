#! /bin/bash -

ROOT_DIR=/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/CrackingTheCodingInterview/Cards
g++ -o bin/main/main src/main/C++/*.cpp src/main/main.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include
g++ -o bin/test/test src/test/C++/*.cpp src/main/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include -lgtest -lgmock

exit 0