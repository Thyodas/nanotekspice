cmake_minimum_required(VERSION 3.17)

project(NanoTekSpice)

set(SRCS
    src/main.cpp
    src/Components/AComponent.cpp
    src/Components/Input/InputComponent.cpp
    src/Components/True/TrueComponent.cpp
    src/Components/False/FalseComponent.cpp
    src/Components/Output/OutputComponent.cpp
    src/Components/Clock/ClockComponent.cpp
    src/Components/And/AndComponent.cpp
    src/Components/Not/NotComponent.cpp
    src/Components/Or/OrComponent.cpp
    src/Components/Xor/XorComponent.cpp
    src/Circuit.cpp
    )

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++20")

include_directories(include)

add_executable(nanotekspice ${SRCS} ${HEADERS})
