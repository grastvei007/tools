cmake_minimum_required(VERSION 3.16)
project(tag)

set_target_properties(PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}")

include_directories($ENV{JUNE_ROOT})
link_directories(${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

add_definitions(-DNO_GUI)

set(CMAKE_INCLUDE_CURRENT_DIR "YES")
set(CMAKE_AUTOMOC "YES")
set(CMAKE_AUTOUIC "YES")

find_package(Qt6 COMPONENTS WebSockets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS HttpServer REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

qt_add_executable(tag
    tag/main.cpp
    tag/app.h tag/app.cpp
)


target_link_libraries(tag PRIVATE Qt6::WebSockets
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::HttpServer
    Qt6::Network)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode")
    target_link_libraries(tag PRIVATE tagsystemd)
    target_link_libraries(tag PRIVATE cored)
else()
    message("Release mode")
    target_link_libraries(tag PRIVATE tagsystem)
    target_link_libraries(tag PRIVATE core)
endif()

target_include_directories(tag INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(tag
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin
)


