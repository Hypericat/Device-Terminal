//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_TERMINAL_HPP
#define CMD_TERMINAL_HPP

#include <iostream>
#include <map>
#include <thread>
#include "Utils/Util.hpp"
#include "Qt/WindowManager.hpp"
#include "Commands/Command.hpp"
#include "Commands/CommandLS.hpp"
#include "Commands/CommandLoop.hpp"
#include "Commands/CommandClear.hpp"

class Terminal {

public:
    Terminal(WindowManager &window);

private:
    void stackReturn(std::string stackLine);
    void initCommands();
    void addCommand(Command* cmd);
    std::map<std::string, Command*> commandMap;
    WindowManager &window;
    std::string path = "C:/";
};


#endif //CMD_TERMINAL_HPP
