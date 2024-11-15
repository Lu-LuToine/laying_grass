cmake_minimum_required(VERSION 3.29)
project(laying_grass)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(laying_grass main.cpp
        include/Player.h
        src/Player.cpp
        include/board/Board.h
        src/board/Board.cpp
        include/board/Cells.h
        src/board/Cells.cpp
        include/Game.h
        src/Game.cpp
        include/Tiles.h
        src/Tiles.cpp
        src/menu/menu.cpp
        src/Colors.cpp
        include/Colors.h
        include/menu.h
        include/Bonus.h
        src/Bonus.cpp)
