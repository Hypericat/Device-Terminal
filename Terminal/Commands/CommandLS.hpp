//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_COMMANDLS_HPP
#define CMD_COMMANDLS_HPP

#include "Command.hpp"
#include "Utils/FileUtils.hpp"

class CommandLS : public Command {
    void execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) override;
    std::vector<std::string> getStartCmd() override;
};


#endif //CMD_COMMANDLS_HPP
