//
// Created by Hypericats on 6/7/2024.
//

#ifndef CMD_WINDOWMANAGER_HPP
#define CMD_WINDOWMANAGER_HPP


#include <QApplication>
#include <QLabel>
#include "MainWindow.hpp"
#include "CustomLabel.hpp"
#include <string>
#include <iostream>
#include <vector>
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
    void addText(std::string text);
    void setBackgroundColor(int r, int g, int b, int a);
    void setWindowIcon(std::string path);
    bool getVisibility();
    void updateText();
    bool isSizeFit(std::string str);
    void setFont(const std::string& fontName, int size);
    int getSizeX();
    int getSizeY();
    Vector2i getSize();
    std::string getWindowTitle();
    std::string getUpdateStack();
    int getTextSize(std::string text);

private:
    void resizeEvent(QResizeEvent* event);
    void keyEvent(QKeyEvent* event);
    void initEvents();
    void getAlignmentText(std::string str, std::string &labelText);
    QApplication application;
    MainWindow mainWindow;
    CustomLabel label;
    QFont font;
    std::string currentLine;
    std::vector<std::string> updateStack;
    std::vector<std::string> textStack;
};


#endif //CMD_WINDOWMANAGER_HPP
