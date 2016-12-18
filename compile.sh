#! /bin/bash

using_imac=0
ROOT_DIR=/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/CrackingTheCodingInterview/Cards

if [ $using_imac -eq 0 ]
then
    g++ -o bin/test/test src/main/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include
    g++ -o bin/test/test src/test/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I$ROOT_DIR/src/main/include -lgtest -lgmock
else
    g++ -o bin/test/test src/main/C++/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/ -I$ROOT_DIR/src/main/include
    g++ -o bin/test/test src/test/C++/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/ -I$ROOT_DIR/src/main/include -lgtest -lgmock
fi

exit $?