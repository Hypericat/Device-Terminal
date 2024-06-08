cmake_minimum_required(VERSION 3.29)
project(Cmd)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt-framework\\6.7.1\\mingw_64\\lib\\cmake\\")

find_package(Qt6Widgets REQUIRED)

set(SOURCE_FILES
        main.cpp
        Qt/WindowManager.cpp
        Qt/WindowManager.hpp
        Utils/Vector2i.cpp
        Utils/Vector2i.hpp
        Terminal/Terminal.cpp
        Terminal/Terminal.hpp
        Qt/MainWindow.cpp
        Qt/MainWindow.hpp
        Qt/CustomLabel.cpp
        Qt/CustomLabel.hpp
)

add_executable(Cmd WIN32 ${SOURCE_FILES})
target_link_libraries(Cmd Qt6::Widgets)