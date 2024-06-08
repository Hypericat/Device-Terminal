//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_TERMINAL_HPP
#define CMD_TERMINAL_HPP

#include <iostream>
#include "Qt/WindowManager.hpp"

class Terminal {
public:
    Terminal(WindowManager &window);
    void run();
private:
    WindowManager &window;
    void executeUpdate(std::string windowUpdate);
};


#endif //CMD_TERMINAL_HPP
