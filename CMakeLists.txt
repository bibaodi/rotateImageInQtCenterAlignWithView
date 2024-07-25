cmake_minimum_required(VERSION 3.16)

project(240725-image-rotate VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

set(targetApp "app240725-image-rotate")
qt_add_executable(${targetApp}
    main.cpp
    imageitem.cpp
    imageitem.h
)

qt_add_qml_module(${targetApp}
    URI 240725-image-rotate
    VERSION 1.0
    QML_FILES main.qml
)

qt_add_resources(${targetApp} "app_images"
    PREFIX "/"
    FILES "imgs/duck.jpeg"
)

set_target_properties(${targetApp} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(${targetApp}
    PRIVATE Qt6::Quick)

install(TARGETS ${targetApp}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
