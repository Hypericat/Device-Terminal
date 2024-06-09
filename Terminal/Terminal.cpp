//
// Created by Hypericats on 6/8/2024.
//

#include "Terminal.hpp"


Terminal::Terminal(WindowManager &window) : window(window) {
    window.setStackReturnMethod([this](std::string stackLine) { stackReturn(std::move(stackLine)); });
    window.path = this->path;
    initCommands();
}

void Terminal::stackReturn(std::string stackLine) {
    //keep the case on purpose
    stackLine = stackLine.substr(window.getPointerString().size());
    std::vector<std::string> commandText = Util::splitString(stackLine, ' ');
    if (!commandMap.contains(commandText[0])) return;
    Command *cmd = commandMap.find(commandText[0])->second;
    cmd->execute(commandText, path, window);
}

void Terminal::initCommands() {
    addCommand(new CommandLS());
    addCommand(new CommandClear());
    addCommand(new CommandLoop([this](std::string str) { stackReturn(std::move(str)); }));
}

void Terminal::addCommand(Command* cmd) {
    for (std::string str : cmd->getStartCmd()) {
        commandMap.insert({str, cmd});
    }
}
