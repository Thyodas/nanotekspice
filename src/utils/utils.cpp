/*
** EPITECH PROJECT, 2022
** B-OOP-400-STG-4-1-tekspice-guillaume.hein
** File description:
** utils.cpp
*/

#include "utils.hpp"
#include <algorithm>
#include <cctype>
#include <locale>

std::string ntsUtils::rtrim(std::string s)
{
    const std::string WHITESPACE = " \t\f\v";
    std::size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string ntsUtils::ltrim(std::string s)
{
    const std::string WHITESPACE = " \t\f\v";
    std::size_t begin = s.find_first_not_of(WHITESPACE);
    return (begin == std::string::npos) ? "" : s.substr(begin, s.length());
}

std::string ntsUtils::trim(std::string s)
{
    return ltrim(rtrim(s));
}

std::ifstream ntsUtils::openFile(std::string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw nts::Error("ntsUtils: Failure to open file");
    return file;
}

std::string ntsUtils::clearComments(std::string line)
{
    std::istringstream iss(line);
    std::string lineCleared;
    std::getline(iss, lineCleared, '#');
    lineCleared = trim(lineCleared);
    return lineCleared;
}

std::vector<std::string> ntsUtils::split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        token = trim(token);
        if (token == "")
            continue;
        tokens.push_back(token);
    }
    return tokens;
}

void ntsUtils::parseChipsets(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    std::vector<std::string> results;
    nts::ComponentFactory factory;
    while (!file.eof()) {
        std::getline(file, line);
        results = ntsUtils::split(line, ' ');
        if (results.empty() || results[0][0] == '\n' || results[0][0] == '#')
            continue;
        std::string token2Cleared = clearComments(results[0]);
        if (token2Cleared.empty())
            throw nts::Error("nts: Missing links");
        if (token2Cleared == ".links:")
            break;
        if (results.size() < 2 || results[0].find(":") != std::string::npos || results[1].find(":") != std::string::npos)
            throw nts::Error("nts: Wrong chipset formatting");
        circuit->addComponent(results[0], results[1], &factory);
    }
}

std::tuple<std::string, std::size_t> ntsUtils::parseLink(std::string result)
{
    std::vector<std::string> tokens = ntsUtils::split(result, ':');
    if (tokens.size() != 2)
        throw nts::Error("nts: Missing links");
    std::string name = tokens[0];
    std::string linkCleared = clearComments(tokens[1]);
    if (linkCleared.empty())
        throw nts::Error("nts: Missing links");
    std::size_t link = std::stoi(linkCleared);
    return make_tuple(name, link);
}

void ntsUtils::parseLinks(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    std::vector<std::string> results;
    std::tuple<std::string, std::size_t> tokens;
    while (!file.eof()) {
        std::getline(file, line);
        results = ntsUtils::split(line, ' ');
        if (results.empty() || results[0][0] == '#' || results[0][0] == '\n')
            continue;
        if (results.size() < 2)
            throw nts::Error("nts: Wrong chipset formatting");
        tokens = ntsUtils::parseLink(results[0]);
        std::string name1 = std::get<0>(tokens);
        std::size_t link1 = std::get<1>(tokens);
        tokens = ntsUtils::parseLink(results[1]);
        std::string name2 = std::get<0>(tokens);
        std::size_t link2 = std::get<1>(tokens);
        circuit->setLinks(name1, link1, name2, link2);
    }
}

void ntsUtils::parseFile(std::ifstream& file, nts::Circuit *circuit)
{
    std::string line;
    while (!file.eof()) {
        std::getline(file, line);
        std::string lineCleared = clearComments(line);
        if (lineCleared == ".chipsets:") {
            parseChipsets(file, circuit);
            parseLinks(file, circuit);
            continue;
        }
        if (lineCleared.size() != 0 && lineCleared[0] != '#' && lineCleared[0] != '\n')
            throw nts::Error("nts: Wrong file formatting");
    }
}
