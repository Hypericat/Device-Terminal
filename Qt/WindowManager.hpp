//
// Created by Hypericats on 6/7/2024.
//

#ifndef CMD_WINDOWMANAGER_HPP
#define CMD_WINDOWMANAGER_HPP


#include <QApplication>
#include <QLabel>
#include <string>
#include "Utils/Vector2i.hpp"

class WindowManager {
public:
    WindowManager(int &argc, char **argv);

    void initWindow();
    void setWindowTitle(std::string windowTitle);
    void resizeX(int sizeX);
    void resizeY(int sizeY);
    void resize(int sizeX, int sizeY);
    void toggleVisibility();
    void show();
    void hide();
    void exec();
    bool getVisibility();
    int getSizeX();
    int getSizeY();
    Vector2i getSize();
    std::string getWindowTitle();
private:
    QApplication application;
    QLabel label;
};


#endif //CMD_WINDOWMANAGER_HPP
