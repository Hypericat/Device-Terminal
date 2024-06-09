//
// Created by Hypericats on 6/8/2024.
//

#include "CommandLS.hpp"

void CommandLS::execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) {
    std::vector<std::string> files;
    FileUtils::listFiles(path, files);

    std::vector<std::string> dirs;
    FileUtils::listDirs(path, dirs);
    for (std::string &dir : dirs) {
        windowManager.addText(dir, QColor::fromRgb(100, 255, 100));
    }
    for (std::string &file : files) {
        windowManager.addText(file, QColor::fromRgb(100, 100, 255));
    }

}

std::vector<std::string> CommandLS::getStartCmd() {
    return {"ls", "dir", "list"};
}
