//
// Created by Hypericats on 6/7/2024.
//

#include "WindowManager.hpp"

WindowManager::WindowManager(int &argc, char **argv) : application(argc, argv), label() {

}

void WindowManager::initWindow() {
    setWindowTitle("Device Terminal");
    resize(700, 400);
    show();
    exec();
}

void WindowManager::setWindowTitle(std::string windowTitle) {
    label.setWindowTitle(windowTitle.c_str());
}

void WindowManager::resizeX(int sizeX) {
    label.resize(sizeX, label.size().height());
}

void WindowManager::resizeY(int sizeY) {
    label.resize(label.size().width(), sizeY);
}

void WindowManager::resize(int sizeX, int sizeY) {
    label.resize(sizeX, sizeY);
}

void WindowManager::toggleVisibility() {
    if (label.isVisible()) {
        hide();
        return;
    }
    show();
}

void WindowManager::show() {
    label.show();
}

void WindowManager::hide() {
    label.hide();
}

void WindowManager::exec() {
    QApplication::exec();
}

bool WindowManager::getVisibility() {
    return label.isVisible();
}

int WindowManager::getSizeX() {
    return label.size().width();
}

int WindowManager::getSizeY() {
    return label.size().height();
}

Vector2i WindowManager::getSize() {
    return Vector2i(label.size());
}

std::string WindowManager::getWindowTitle() {
    return label.windowTitle().toStdString();
}
