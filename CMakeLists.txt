cmake_minimum_required(VERSION 3.17)

project(NanoTekSpice)

set(SRCS
    src/main.cpp
    src/Components/AComponent.cpp
    src/Components/Special/Input/InputComponent.cpp
    src/Components/Special/True/TrueComponent.cpp
    src/Components/Special/False/FalseComponent.cpp
    src/Components/Special/Output/OutputComponent.cpp
    src/Components/Special/Clock/ClockComponent.cpp
    src/Components/Elementary/And/AndComponent.cpp
    src/Components/Elementary/Not/NotComponent.cpp
    src/Components/Elementary/Or/OrComponent.cpp
    src/Components/Elementary/Xor/XorComponent.cpp
    src/Components/Elementary/Nor/NorComponent.cpp
    src/Components/Elementary/Nand/NandComponent.cpp
    src/Components/Elementary/Nand3/Nand3Component.cpp
    src/Components/Gate/4001/Chip4001Component.cpp
    src/Components/Gate/4011/Chip4011Component.cpp
    src/Components/Gate/4030/Chip4030Component.cpp
    src/Components/Gate/4071/Chip4071Component.cpp
    src/Components/Gate/4081/Chip4081Component.cpp
    src/Components/Gate/4069/Chip4069Component.cpp
    src/Circuit.hpp
    src/Components/Advanced/HalfAdder/HalfAdderComponent.cpp
    src/Components/Advanced/Adder/AdderComponent.cpp
    src/Components/Advanced/4008/Chip4008Component.cpp
    src/Components/Advanced/Logger/LoggerComponent.cpp
    src/Components/Advanced/DFlipFlop/DFlipFlopComponent.cpp
    src/Components/Advanced/SRFlipFlop/SRFlipFlopComponent.cpp
    src/Components/Advanced/4013/Chip4013Component.cpp
    src/Components/Advanced/4017/Chip4017Component.cpp
    src/Components/Advanced/4514/Chip4514Component.cpp
    src/Components/ComponentFactory.cpp
    src/Circuit.cpp
    src/utils/utils.cpp
    )

set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++20")

include_directories(include)

add_executable(nanotekspice ${SRCS} ${HEADERS})
