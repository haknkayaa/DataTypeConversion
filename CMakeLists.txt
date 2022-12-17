cmake_minimum_required(VERSION 3.10)

project(qtProject)

if(WIN32)
    message("OS: ${CMAKE_SYSTEM_NAME}")
    set(QT_DIR "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins\\platforms")
    set(QT_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins")
else()
    message("OS: ${CMAKE_SYSTEM_NAME}")
    set(QT_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins/platforms")
    set(QT_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins")
endif()

set(QT_DEBUG_PLUGINS 1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCE_FILES "src/*.cpp")
file(GLOB HEADER_FILES "src/*.h")
file(GLOB UI_FILES "src/*.ui")
file(GLOB RESOURCE_FILES "resource/*.qrc")
file(GLOB QML_FILES "qml/*.qml")

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_DIR})

find_package(Qt5 COMPONENTS
        Core
        Quick
        Widgets
        Gui
        REQUIRED)

add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        ${HEADER_FILES}
        ${RESOURCE_FILES}
        ${QML_FILES}
        ${UI_FILES}
        )

target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )
