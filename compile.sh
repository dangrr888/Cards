#! /bin/bash

using_imac=0

if [ $using_imac -eq 0 ]
then
    g++ -o main *.cpp --std=c++14 -I/usr/local/boost_installed/include
else
    g++ -o main *.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/
fi

exit $?