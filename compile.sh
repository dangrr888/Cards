#! /bin/bash -

ROOT_DIR=${PWD}

g++ -o bin/test/test src/test/C++/*.cpp src/main/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include -lgtest -lgmock
g++ -o bin/main/main src/main/C++/*.cpp src/spiketest/C++/main.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include

exit $?