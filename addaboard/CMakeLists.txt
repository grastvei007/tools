cmake_minimum_required(VERSION 3.16)
project(addaboard_test)

set_target_properties(PROPERTIES DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}")

include_directories($ENV{JUNE_ROOT})
link_directories(${CMAKE_BINARY_DIR}/$<CONFIG>/lib)

include(CheckIncludeFile)
CHECK_INCLUDE_FILE(/opt/vc/include/bcm_host.h BCMHOST)

if(BCMHOST)
    add_definitions(-DRASPBERRY_PI)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR "YES")
set(CMAKE_AUTOMOC "YES")
set(CMAKE_AUTOUIC "YES")

find_package(Qt6 COMPONENTS WebSockets REQUIRED)
find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Gui REQUIRED)
find_package(Qt6 COMPONENTS Core REQUIRED)
find_package(Qt6 COMPONENTS HttpServer REQUIRED)
find_package(Qt6 COMPONENTS Network REQUIRED)

qt_add_executable(addaboard_test
    src/main.cpp
    src/ADS1256.cpp
    src/ADS1256.h
    src/Debug.h
    src/DEV_Config.cpp
    src/DEV_Config.h
    src/app.h src/app.cpp

)


target_link_libraries(addaboard_test PRIVATE Qt6::WebSockets
    Qt6::Widgets
    Qt6::Gui
    Qt6::Core
    Qt6::HttpServer
    Qt6::Network)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message("Debug mode")
    target_link_libraries(addaboard_test PRIVATE tagsystemd)
    target_link_libraries(addaboard_test PRIVATE cored)
    target_link_libraries(addaboard_test PRIVATE pluginCored)
else()
    message("Release mode")
    target_link_libraries(addaboard_test PRIVATE tagsystem)
    target_link_libraries(addaboard_test PRIVATE core)
    target_link_libraries(addaboard_test PRIVATE pluginCore)
    if(BCMHOST)
        target_link_libraries(addaboard wiringPi)
    endif()
endif()

target_include_directories(addaboard_test INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(addaboard_test
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/lib
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/$<CONFIG>/bin
)


