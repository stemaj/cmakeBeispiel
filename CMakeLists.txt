cmake_minimum_required(VERSION 3.0.0)
project(Example VERSION 0.1.0)

add_subdirectory (ExampleLib)
add_subdirectory (components/text)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt5 COMPONENTS Gui Widgets Core REQUIRED)

get_target_property(QtCore_location Qt5::Core LOCATION)
message("Plugin is at location ${QtCore_location}")

# Add executable called "helloDemo" that is built from the source files
# "demo.cxx" and "demo_b.cxx". The extensions are automatically found.
add_executable(Example src/main.cpp src/mainwindow.ui src/mainwindow.cpp)

target_include_directories (Example PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Link the executable to the Hello library. Since the Hello library has
# public include directories we will use those link directories when building
# helloDemo
# Link the target to the GTK+ libraries
target_link_libraries (Example LINK_PUBLIC ExampleLib Qt5::Widgets Qt5::Core)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#add_definitions("-std=c++11") 

foreach(plugin ${Qt5Network_PLUGINS})
  get_target_property(_loc ${plugin} LOCATION)
  message("Plugin ${plugin} is at location ${_loc}")
endforeach()

add_custom_command(
    TARGET Example POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:Qt5::Widgets>
        $<TARGET_FILE:Qt5::Core>
        $<TARGET_FILE:Qt5::Gui>
        $<TARGET_FILE_DIR:Example>
)