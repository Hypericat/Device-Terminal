//
// Created by Hypericats on 6/8/2024.
//

#include "CustomTextEdit.hpp"

CustomTextEdit::CustomTextEdit(int lineSpacing) : lineSpacing(lineSpacing), keyCallback() {

}

void CustomTextEdit::paintEvent(QPaintEvent *event) {
    QTextEdit::paintEvent(event);
}

void CustomTextEdit::setLineSpacing(int lineSpacing) {
    this->lineSpacing = lineSpacing;
}

int CustomTextEdit::getLineSpacing() {
    return lineSpacing;
}

void CustomTextEdit::keyPressEvent(QKeyEvent *event) {
    keyCallback(event);
}

void CustomTextEdit::setKeyPressCallback(const std::function<void(QKeyEvent *)> &callback) {
    keyCallback = callback;
}
