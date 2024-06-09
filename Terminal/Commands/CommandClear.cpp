//
// Created by Hypericats on 6/8/2024.
//

#include "CommandClear.hpp"

void
CommandClear::execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) {
    windowManager.clear();
}

std::vector<std::string> CommandClear::getStartCmd() {
    return {"clear", "cls", "cl"};
}
