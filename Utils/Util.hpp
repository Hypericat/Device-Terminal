//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_UTIL_HPP
#define CMD_UTIL_HPP


#include <string>
#include <vector>
#include <iostream>

class Util {
public:
    static std::vector<std::string> splitString(const std::string& str, const char& regex);
    static int indexOf(std::string str, std::vector<std::string>);
    static void printVec(std::vector<std::string> vec);
    static void toLowerCase(std::string &string);
};


#endif //CMD_UTIL_HPP
