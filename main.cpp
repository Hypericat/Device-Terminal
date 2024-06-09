#include <iostream>
#include <thread>
#include "Qt/WindowManager.hpp"
#include "Terminal/Terminal.hpp"

int main(int argc, char *argv[]) {
    WindowManager windowManager(argc, argv);
    Terminal terminal(windowManager);
    windowManager.initWindow();
    windowManager.exec();
    return 0;
}
//todo


//remember
//cout crashes in release mode