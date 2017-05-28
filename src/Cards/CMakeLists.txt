project(Cards)

file (GLOB CARDS_HEADER_FILES ${CARDS_HEADER_DIR}/*.h)
file (GLOB CARDS_IMPL_FILES lib/main/*.cpp)

include_directories (${BOOST_INCLUDE_DIRS})
include_directories (${CARDS_HEADER_DIR})

add_library(${PROJECT_NAME}
  ${BOOST_INCLUDE_DIRS}
  ${CARDS_HEADER_FILES}
  ${CARDS_IMPL_FILES}
)

install(
    TARGETS     ${PROJECT_NAME}
    DESTINATION lib
)
