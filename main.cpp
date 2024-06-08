#include <iostream>
#include <thread>
#include "Qt/WindowManager.hpp"
#include "Terminal/Terminal.hpp"

void runTerminal(Terminal terminal)
{
    terminal.run();
}

int main(int argc, char *argv[]) {
    WindowManager windowManager(argc, argv);
    windowManager.initWindow();
    Terminal terminal(windowManager);
    std::thread *terminalThread = new std::thread(runTerminal, terminal);
    try {
        windowManager.exec();
    } catch(const std::system_error&) {
        std::cout << "Exiting program!" << std::endl;
        delete terminalThread;
        return 0;
    }

    terminalThread->join();
    return 0;
}
//todo
//loop execute file command
//loop command
//high cpu usage
//long time to close