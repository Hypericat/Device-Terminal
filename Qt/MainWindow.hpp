//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_MAINWINDOW_HPP
#define CMD_MAINWINDOW_HPP


#include <QMainWindow>
#include <QResizeEvent>
#include <QDebug>
#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {}
    void addResizeCallback(const std::function<void(QResizeEvent*)>& callback);
    void addKeyPressCallback(const std::function<void(QKeyEvent*)>& callback);
    std::function<void(std::string str, QColor color)> addTextMethod;
protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

private:
    std::vector<std::function<void(QResizeEvent*)>> resizeCallbacks;
    std::vector<std::function<void(QKeyEvent*)>> keyCallbacks;
};


#endif //CMD_MAINWINDOW_HPP
