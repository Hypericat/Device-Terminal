#include <iostream>
#include <thread>
#include "Qt/WindowManager.hpp"
#include "Terminal/Terminal.hpp"

int main(int argc, char *argv[]) {
    WindowManager windowManager(argc, argv);
    windowManager.initWindow();
    Terminal terminal(windowManager);
    windowManager.exec();
    return 0;
}
//todo
//loop execute file command
//loop command


//remember
//cout crashes in relase mode