//
// Created by Hypericats on 6/8/2024.
//

#include "CommandLoop.hpp"

void CommandLoop::execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) {
    if (commandText.size() < 3) {
        windowManager.addText("Failed to loop, missing arguments!", Qt::red);
        return;
    }
    int loopCount = 0;
    try {
    loopCount = std::stoi(commandText[1]);
    } catch (std::exception ex) {
        windowManager.addText("Failed to find loop count, invalid number!", Qt::red);
        return;
    }
    std::string str(windowManager.getPointerString());
    for (int i = 2; i < commandText.size(); i++) {
        str += commandText.at(i);
        str += " ";
    }
    str.pop_back();
    for (int i = 0; i < loopCount; i++) {
        callback(str);
    }

}

std::vector<std::string> CommandLoop::getStartCmd() {
    return {"loop"};
}

CommandLoop::CommandLoop(std::function<void(std::string)> loopCallback) {
    this->callback = std::move(loopCallback);
}
