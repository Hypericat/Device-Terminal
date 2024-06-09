//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_COMMAND_HPP
#define CMD_COMMAND_HPP

#include <vector>
#include <string>
#include "Qt/WindowManager.hpp"

class Command {
public:
    Command();
    virtual void execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) {};
    virtual std::vector<std::string> getStartCmd() { return {}; };

private:

};


#endif //CMD_COMMAND_HPP
