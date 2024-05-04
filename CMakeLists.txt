cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(ChessBot)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
set(SFML_DIR "C:/SFML/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)
add_executable(ChessBot main.cpp
        ChessWindow/Window.cpp
        ChessWindow/Window.h
        Pieces/BitBoard.cpp
        Pieces/BitBoard.h
        Pieces/Pieces.cpp
        Pieces/Pieces.h
        main.cpp
        ChessWindow/Window.h
        ChessWindow/Window.cpp
        Pieces/Pieces.cpp
        Pieces/Pieces.h
        ChessWindow/Window.cpp
        Pieces/Pieces.cpp)
target_link_libraries(ChessBot sfml-system sfml-window sfml-graphics sfml-audio)