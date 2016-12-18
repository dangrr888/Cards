#! /bin/bash

using_imac=0

if [ $using_imac -eq 0 ]
then
    g++ -o bin/main/main src/main/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/CrackingTheCodingInterview/Cards/src/main/include
    g++ -o bin/test/test src/test/C++/*.cpp --std=c++14 -I/usr/local/boost_installed/include -lgtest -lgmock
else
    g++ -o bin/main/main src/main/C++/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/ -I/Users/danielcumberbatch/Documents/SoftwareEngineering/Cards/src/main/include
    g++ -o bin/test/test src/test/C++/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/ -lgtest -lgmock
fi

exit $?