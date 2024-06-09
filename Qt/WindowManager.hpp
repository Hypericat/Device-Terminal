//
// Created by Hypericats on 6/7/2024.
//

#ifndef CMD_WINDOWMANAGER_HPP
#define CMD_WINDOWMANAGER_HPP


#include <QApplication>
#include <QScrollBar>
#include <map>
#include <QPalette>
#include <QClipboard>
#include "MainWindow.hpp"
#include "CustomTextEdit.hpp"
#include "Utils/FileUtils.hpp"
#include <string>
#include <iostream>
#include <vector>
#include "Utils/Vector2i.hpp"

class WindowManager {
public:
    WindowManager(int &argc, char **argv);

    void initWindow();
    void setWindowTitle(const std::string& windowTitle);
    void resizeX(int sizeX);
    void resizeY(int sizeY);
    void resize(int sizeX, int sizeY);
    void toggleVisibility();
    void show();
    void hide();
    void exec();
    void addText(std::string text, QColor color);
    void setBackgroundColor(int r, int g, int b, int a);
    void clear();
    void setWindowIcon(std::string path);
    bool getVisibility();
    void updateText();
    bool isSizeFit(std::string str);
    void setFont(const std::string& fontName, int size);
    void moveCursorEnd();
    std::string getPointerString();
    int getSizeX();
    int getSizeY();
    Vector2i getSize();
    std::string getWindowTitle();
    std::string path;
    void setStackReturnMethod(std::function<void(std::string stackLine)> method);
    int getTextSize(std::string text);

private:
    void resizeEvent(QResizeEvent* event);
    void keyEvent(QKeyEvent* event);
    void initEvents();
    void lineReturnEvent(std::string eventLine);
    void getAlignmentText(std::string str, std::string &labelText);
    void setPointerString(std::string pointer);
    QApplication application;
    MainWindow mainWindow;
    CustomTextEdit textEdit;
    QFont font;
    std::string pointerString;
    std::string currentLine;
    std::vector<std::string> commandStack;
    std::vector<std::pair<std::string, QColor>> coloredTextStack;
    std::function<void(std::string stackLine)> stackReturnMethod;
    int upIndex = 0;
    std::string lastCurrentLine;
};


#endif //CMD_WINDOWMANAGER_HPP
