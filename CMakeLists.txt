cmake_minimum_required(VERSION 3.16)
project(tools)

set(MIN_QT_VERSION 6.9)

if(NOT CMAKE_DEBUG_POSTFIX)
  set(CMAKE_DEBUG_POSTFIX d)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

qt_standard_project_setup()

#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(tag)

add_dependencies(tag tagsystem)
