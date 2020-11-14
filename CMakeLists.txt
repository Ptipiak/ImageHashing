cmake_minimum_required(VERSION 3.5)

# If the version isn't here, then fallback on whatever you'll find
if(${CMAKE_VERSION} VERSION_LESS 3.5)
	cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

project(ImageHashing VERSION 1.1 DESCRIPTION "A image hashing command line tool" LANGUAGES CXX)

set(SOFTWARE_DIR ${CMAKE_CURRENT_LIST_DIR}/software)
set(INTERFACE_DIR ${CMAKE_CURRENT_LIST_DIR}/interface)
add_subdirectory(${SOFTWARE_DIR})
add_subdirectory(${INTERFACE_DIR})
