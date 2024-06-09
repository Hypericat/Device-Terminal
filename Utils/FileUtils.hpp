//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_FILEUTILS_HPP
#define CMD_FILEUTILS_HPP

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <vector>
#include <Windows.h>

class FileUtils {
public:
    static std::string getClipboardText();
    static void listFiles(const std::string& path, std::vector<std::string>& v);
    static void listDirs(const std::string& path, std::vector<std::string>& v);
};


#endif //CMD_FILEUTILS_HPP
