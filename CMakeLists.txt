cmake_minimum_required(VERSION 3.17)

project(NanoTekSpice)

set(SRCS
    src/main.cpp
    src/Components/AComponent.cpp
    src/Components/Input/InputComponent.cpp
    src/Components/True/TrueComponent.cpp
    )

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++20")

include_directories(include)

add_executable(nanotekspice ${SRCS} ${HEADERS})
