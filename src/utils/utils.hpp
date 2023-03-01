/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** utils.hpp
*/

#pragma once

#include "../Circuit.hpp"
#include "../Components/ComponentFactory.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>

namespace ntsUtils {
    std::ifstream openFile(std::string filename);
    std::vector<std::string> split(const std::string &s, char delimiter);
    void parseChipsets(std::ifstream& file, nts::Circuit *circuit);
    std::tuple<std::string, std::size_t> parseLink(std::string token);
    void parseLinks(std::ifstream& file, nts::Circuit *circuit);
    void parseFile(std::ifstream& file, nts::Circuit *circuit);
    std::string rtrim(std::string s);
    std::string ltrim(std::string s);
    std::string trim(std::string s);
    std::string clearComments(std::string line);
};
