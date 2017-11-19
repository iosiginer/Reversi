cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h Cell.cpp Cell.h Coordinate.cpp Coordinate.h GameFlow.cpp GameFlow.h Player.h GameLogic.h Move.cpp Move.h ClassicLogic.cpp ClassicLogic.h BoardPrinter.h BoardConsolePrinter.cpp BoardConsolePrinter.h HumanConsolePlayer.cpp HumanConsolePlayer.h CellCounter.cpp CellCounter.h)
add_executable(Reversi ${SOURCE_FILES})