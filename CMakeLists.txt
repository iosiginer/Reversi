cmake_minimum_required(VERSION 3.8)
project(Reversi)

add_subdirectory(gtest_src/googletest)
include_directories(src)
include_directories(include)
include_directories(gtest_src/googletest/include)
include_directories(gtest_src/googlemock/include)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES
        main.cpp
        Board.cpp
        Board.h
        Cell.cpp
        Cell.h
        Coordinate.cpp
        Coordinate.h
        GameFlow.cpp
        GameFlow.h
        Player.h
        GameLogic.h
        Move.cpp
        Move.h
        ClassicLogic.cpp
        ClassicLogic.h
        Printer.h
        ConsolePrinter.cpp
        ConsolePrinter.h
        HumanPlayer.cpp
        HumanPlayer.h
        CellCounter.cpp
        CellCounter.h
        AIPlayer.cpp
        AIPlayer.h
        Cloneable.h
        Menu.h
        Menu.cpp
        TurnManager.cpp
        TurnManager.h
        Color.h
        )

set(TEST_FILES
        tests/aIPlayer_test.cpp
        tests/AIPlayerTest.h
        tests/BoardTest.h
        tests/board_test.cpp
        tests/classic_logic_test.cpp
        tests/ClassicLogicTest.h
        tests/coordinate_test.cpp)
add_executable(Reversi ${SOURCE_FILES} ${TEST_FILES})
target_link_libraries(Reversi gtest gtest_main)