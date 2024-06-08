//
// Created by Hypericats on 6/8/2024.
//

#include "MainWindow.hpp"

void MainWindow::addResizeCallback(const std::function<void(QResizeEvent *)>& callback) {
    resizeCallbacks.emplace_back(callback);
}

void MainWindow::addKeyPressCallback(const std::function<void(QKeyEvent *)> &callback) {
    keyCallbacks.emplace_back(callback);
}


void MainWindow::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);
    for (const std::function<void(QResizeEvent *)>& callback : resizeCallbacks) {
        callback(event);
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
    QWidget::keyPressEvent(event);
    for (const std::function<void(QKeyEvent *)>& callback : keyCallbacks) {
        callback(event);
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    throw std::system_error();
}
