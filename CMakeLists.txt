cmake_minimum_required(VERSION 4.3)
project(cs210_Assignment3)

set(CMAKE_CXX_STANDARD 20)

add_executable(cs210-uno main.cpp
        ArrayList.h
        Node.h
        LinkedList.h
        List.h
        Player.h
        Card.h
        Stack.h
)
