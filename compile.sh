#! /bin/bash -

ROOT_DIR=${PWD}
BOOST_HEADERS_DIR=/usr/local/boost_installed/include
UTEST_BINARY_DIR=${ROOT_DIR}/bin/test
SPIKETEST_BINARY_DIR=${ROOT_DIR}/bin/spiketest
CARDS_HEADERS_DIR=${ROOT_DIR}/src/Cards/include/main
CARDS_IMPL_DIR=${ROOT_DIR}/src/Cards/lib/main
CARDS_UTEST_IMPL_DIR=${ROOT_DIR}/src/Cards/lib/test
CARDS_SPIKETEST_IMPL_DIR=${ROOT_DIR}/src/spiketests/Cards/test
BLACKJACK_HEADERS_DIR=${ROOT_DIR}/src/BlackJack/include/main
BLACKJACK_IMPL_DIR=${ROOT_DIR}/src/BlackJack/lib/main
BLACKJACK_UTEST_IMPL_DIR=${ROOT_DIR}/src/BlackJack/lib/test
BLACKJACK_SPIKETEST_IMPL_DIR=${ROOT_DIR}/src/spiketests/BlackJack/test

# Clean up #

if [ `find -E $UTEST_BINARY_DIR -iregex ".*" -type f -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${UTEST_BINARY_DIR}/*
fi

if [ `find -E ${SPIKETEST_BINARY_DIR} -iregex ".*" -type f -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${SPIKETEST_BINARY_DIR}/*
fi

if [ `find -E ${CARDS_IMPL_DIR} -iregex ".*.o" -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${CARDS_IMPL_DIR}/*.o
fi

if [ `find -E ${CARDS_UTEST_IMPL_DIR} -iregex ".*.o" -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${CARDS_UTEST_IMPL_DIR}/*.o
fi

if [ `find -E ${BLACKJACK_IMPL_DIR} -iregex ".*.o" -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${BLACKJACK_IMPL_DIR}/*.o
fi

if [ `find -E ${BLACKJACK_UTEST_IMPL_DIR} -iregex ".*.o" -maxdepth 1 | wc -l` -ne 0 ]
then
    rm ${BLACKJACK_UTEST_IMPL_DIR}/*.o
fi

# Compile sourcefiles #
cd ${CARDS_IMPL_DIR}
g++ -c ${CARDS_IMPL_DIR}/*.cpp --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR}

cd ${BLACKJACK_IMPL_DIR}
g++ -c ${BLACKJACK_IMPL_DIR}/*.cpp --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR} -I${BLACKJACK_HEADERS_DIR}

# Generate unit test binaries #
cd ${ROOT_DIR}
g++ -o ${UTEST_BINARY_DIR}/Cards ${CARDS_UTEST_IMPL_DIR}/*.cpp ${CARDS_IMPL_DIR}/*.o --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR} -lgtest -lgmock
g++ -o ${UTEST_BINARY_DIR}/BlackJack ${BLACKJACK_UTEST_IMPL_DIR}/*.cpp ${CARDS_IMPL_DIR}/*.o ${BLACKJACK_IMPL_DIR}/*.o --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR} -I${BLACKJACK_HEADERS_DIR} -lgtest -lgmock

# Generate integration test binaries #
cd ${ROOT_DIR}
g++ -o ${SPIKETEST_BINARY_DIR}/Cards ${CARDS_SPIKETEST_IMPL_DIR}/main.cpp ${CARDS_IMPL_DIR}/*.o --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR} -lgtest -lgmock
#g++ -o ${SPIKETEST_BINARY_DIR}/BlackJack ${BLACKJACK_SPIKETEST_IMPL_DIR}/main.cpp ${CARDS_IMPL_DIR}/*.o ${BLACKJACK_IMPL_DIR}/*.o --std=c++14 -I${BOOST_HEADERS_DIR} -I${CARDS_HEADERS_DIR} -I${BLACKJACK_HEADERS_DIR} -lgtest -lgmock

exit $?