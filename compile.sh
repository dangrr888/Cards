#! /bin/bash

using_imac=0

if [ $using_imac -eq 0 ]
then
    g++ -o bin/main/main src/main/*.cpp --std=c++14 -I/usr/local/boost_installed/include
    g++ -o bin/test/test src/test/*.cpp --std=c++14 -I/usr/local/boost_installed/include -I/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/googletest/googletest -I/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/googletest/googlemock
else
    g++ -o bin/main/main src/main/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/
    g++ -o bin/test/test src/test/*.cpp --std=c++14 -I/Developer/Applications/boost_1_62_0/ -I/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/googletest/googletest -I/Users/danielcumberbatch/Documents/SoftwareEngineeringPlaypen/googletest/googlemock
fi

exit $?