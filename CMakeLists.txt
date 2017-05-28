##
# Require CMAKE 3.7.1 at least
##
cmake_minimum_required (VERSION 3.7.1 FATAL_ERROR)

###############################################################################
#                                                                             #
#                           COMPILER FLAGS                                    #
#                                                                             #
###############################################################################

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++11")

###############################################################################
#                                                                             #
#                           THIRD PARTY RESOURCES                             #
#                                                                             #
###############################################################################

set(BOOST_INCLUDE_DIRS
    "/usr/local/boost_installed/include"
    CACHE
    PATH
    "The path to the Boost header files."
)

################################################################################
#                                                                              #
#                              PROJECT VARIABLES                               #
#                                                                              #
################################################################################

project(CardGames CXX)

set (CARDGAMES_VERSION_MAJOR 1)
set (CARDGAMES_VERSION_MINOR 0)

################################################################################
#                                                                              #
#                              SUB PROJECTS                                    #
#                                                                              #
################################################################################

set(CARDS_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/src/Cards/include/main
)

set(BLACKJACK_HEADER_DIR
    ${PROJECT_SOURCE_DIR}/src/BlackJack/include/main
)

include_directories (${CARDS_HEADER_DIR})
include_directories (${BLACKJACK_HEADER_DIR})

add_subdirectory (${PROJECT_SOURCE_DIR}/src/Cards)
add_subdirectory (${PROJECT_SOURCE_DIR}/src/BlackJack)

################################################################################
#                                                                              #
#                              CONFIGURE TARGET                                #
#                                                                              #
################################################################################

add_library(${PROJECT_NAME} SHARED)
set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES
  LINKER_LANGUAGE CXX
)
target_link_libraries(${PROJECT_NAME}
  LINK_PUBLIC Cards
  LINK_PUBLIC BlackJack
)

################################################################################
#                                                                              #
#                              CUSTOM OPTIONS                                  #
#                                                                              #
################################################################################

################################################################################
#                                                                              #
#                              CONFIGURE TEMPLATES                             #
#                                                                              #
################################################################################

###############################################################################
#                                                                             #
#                           GENERATE DOCUMENTATION                            #
#                                                                             #
###############################################################################

# Add a target to generate API documentation with Doxygen
find_package(Doxygen)

if(DOXYGEN_FOUND)
  configure_file(
      ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
      ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY
  )

  add_custom_target(doc
                    ${DOXYGEN_EXECUTABLE} "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile"
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
                    COMMENT "Generating API documentation with Doxygen"
                    VERBATIM
  )
endif()

################################################################################
#                                                                              #
#                              INSTALLATION RULES                              #
#                                                                              #
################################################################################

# Install all Cards includes #
install(
  DIRECTORY ${CARDS_HEADER_DIR}
  DESTINATION include
)

# Install all BlackJack includes #
install(
  DIRECTORY ${BLACKJACK_HEADER_DIR}
  DESTINATION include
)

# Install target library #
install(
  TARGETS ${PROJECT_NAME}
  DESTINATION lib
)

# Install documentation #
if(EXISTS ${PROJECT_BINARY_DIR}/doc)
  install(
    DIRECTORY ${CMAKE_BINARY_DIR}/doc
    DESTINATION doc
  )
endif()

################################################################################
#                                                                              #
#                              CPACK & PUBLISHING                              #
#                                                                              #
################################################################################

# Build a CPack driven installer package
include (InstallRequiredSystemLibraries)

set (CPACK_RESOURCE_FILE_LICENSE
     "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE"
)

set (CPACK_PACKAGE_VERSION_MAJOR
     "${CARDGAMES_VERSION_MAJOR}"
)

set (CPACK_PACKAGE_VERSION_MINOR
     "${CARDGAMES_VERSION_MINOR}"
)

include (CPack)
