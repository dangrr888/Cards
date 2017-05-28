project(BlackJack)

file (GLOB BLACKJACK_HEADER_FILES ${BLACKJACK_HEADER_DIR}/*.h)
file (GLOB BLACKJACK_IMPL_FILES lib/main/*.cpp)

include_directories (${BOOST_INCLUDE_DIRS})
include_directories (${CARDS_HEADER_DIR})
include_directories (${BLACKJACK_HEADER_DIR})

add_library(${PROJECT_NAME}
  ${BOOST_INCLUDE_DIRS}
  ${CARDS_HEADER_FILES}
  ${BLACKJACK_HEADER_FILES}
  ${BLACKJACK_IMPL_FILES}
)

target_link_libraries(${PROJECT_NAME}
  Cards
)

install(
    TARGETS     ${PROJECT_NAME}
    DESTINATION lib
)
