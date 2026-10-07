cmake_minimum_required(VERSION 4.3)

project(Uno_Turn_Order LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cs210-uno
        main.cpp
        ArrayList.h
        Node.h
        LinkedList.h
        List.h
        Player.h
        Card.h
        Stack.h
        StackList.h
)