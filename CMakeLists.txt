cmake_minimum_required(VERSION 3.16)
project(
  Dusk
  VERSION 0.6
  LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

set(PROJECT_SOURCES
    src/BlackOverlay.cpp
    src/BlackOverlay.h
    src/CheckBox.cpp
    src/CheckBox.h
    src/Dusk.cpp
    src/Dusk.h
    src/Dusk.ui
    res/dusk.qrc
    src/IdentityOverlay.cpp
    src/IdentityOverlay.h
    src/Overlay.cpp
    src/Overlay.h
    src/version.hpp
    src/main.cpp)

set(WINDOWS_RESOURCES "${CMAKE_CURRENT_SOURCE_DIR}/res/dusk.rc")

qt_add_executable(Dusk WIN32 ${PROJECT_SOURCES} ${WINDOWS_RESOURCES})

target_link_libraries(Dusk PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/version.hpp.in
               ${CMAKE_CURRENT_SOURCE_DIR}/src/version.hpp @ONLY)

install(
  TARGETS Dusk
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
