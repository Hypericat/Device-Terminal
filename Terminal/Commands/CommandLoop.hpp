//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_COMMANDLOOP_HPP
#define CMD_COMMANDLOOP_HPP

#include "Command.hpp"
#include "Utils/FileUtils.hpp"

class CommandLoop : public Command {
public:
    CommandLoop(std::function<void(std::string)> loopCallback);
    void execute(std::vector<std::string> &commandText, const std::string &path, WindowManager &windowManager) override;
    std::vector<std::string> getStartCmd() override;
private:
    std::function<void(std::string)> callback;
};


#endif //CMD_COMMANDLOOP_HPP
