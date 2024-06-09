//
// Created by Hypericats on 6/7/2024.
//

#include "WindowManager.hpp"

WindowManager::WindowManager(int &argc, char **argv) : application(argc, argv), label(8), textStack(), mainWindow(), lastCurrentLine(getPointerString()) {

}

void WindowManager::initWindow() {
    setWindowTitle("Device Terminal");
    resize(700, 400);
    setBackgroundColor(0, 0, 0, 255);
    setFont("Cascadia Code", -1);
    label.setAlignment(Qt::AlignTop);
    label.setMinimumSize(1, 1);
    label.setMargin(5);
    setPointerString(">");
    mainWindow.setCentralWidget(&label);
    mainWindow.setMinimumSize(500, 250);
    initEvents();
    show();

    //fully constructed now
    label.setText(getPointerString().c_str());
}

std::string WindowManager::getPointerString() {
    return pointerString;
}

void WindowManager::setPointerString(std::string pointer) {
    pointerString = std::move(pointer);

    //this will remove whatever isn't the pointer string so gl ig
    currentLine = pointerString;
}

void WindowManager::setWindowTitle(const std::string& windowTitle) {
    mainWindow.setWindowTitle(windowTitle.c_str());
}

void WindowManager::resizeX(int sizeX) {
    mainWindow.resize(sizeX, label.size().height());
}

void WindowManager::resizeY(int sizeY) {
    mainWindow.resize(label.size().width(), sizeY);
}

void WindowManager::resize(int sizeX, int sizeY) {
    mainWindow.resize(sizeX, sizeY);
}

void WindowManager::toggleVisibility() {
    if (mainWindow.isVisible()) {
        hide();
        return;
    }
    show();
}

void WindowManager::show() {
    mainWindow.show();
}

void WindowManager::hide() {
    mainWindow.hide();
}

void WindowManager::exec() {
    //start the window
    QApplication::exec();
}

bool WindowManager::getVisibility() {
    return mainWindow.isVisible();
}

int WindowManager::getSizeX() {
    return mainWindow.size().width();
}

int WindowManager::getSizeY() {
    return mainWindow.size().height();
}

Vector2i WindowManager::getSize() {
    return Vector2i(mainWindow.size());
}

std::string WindowManager::getWindowTitle() {
    return mainWindow.windowTitle().toStdString();
}

void WindowManager::setBackgroundColor(int r, int g, int b, int a) {
    QPalette pal = QPalette();
    pal.setColor(QPalette::Window, QColor(r, g, b, a));


    mainWindow.setAutoFillBackground(true);
    mainWindow.setPalette(pal);
    mainWindow.show();
}

void WindowManager::setWindowIcon(std::string path) {
    QIcon icon(path.c_str());
    mainWindow.setWindowIcon(icon);
}

void WindowManager::updateText() {
    std::string labelText;
    for (std::string str : textStack) {
        getAlignmentText(str, labelText);
    }
    getAlignmentText(currentLine, labelText);
    label.setText(labelText.c_str());
}
void WindowManager::getAlignmentText(std::string str, std::string &labelText) {
    if (isSizeFit(str)) {
        labelText += str;
        labelText += '\n';
        return;
    }
    int lastSpaceIndex = -1;
    int lastStartIndex = 0;
    for (int i = 0; i <= str.length(); i++) {
        char c = i < str.length() ? str.at(i) : ' ';
        if (!isSizeFit(str.substr(lastStartIndex, i - lastStartIndex))) {
            if (lastSpaceIndex != -1) {
                labelText += str.substr(lastStartIndex, lastSpaceIndex - lastStartIndex) + '\n';
                lastStartIndex = lastSpaceIndex + 1;
                lastSpaceIndex = -1;
            } else {
                labelText += str.substr(lastStartIndex, i - lastStartIndex) + '\n';
                lastStartIndex = i;
            }
        }
        if (c == ' ') {
            lastSpaceIndex = i;
        }
    }
    if (lastStartIndex < str.length()) {
        labelText += str.substr(lastStartIndex) + '\n';
    }
}

void WindowManager::setStackReturnMethod(std::function<void(std::string stackLine)> method) {
    this->stackReturnMethod = std::move(method);
}

void WindowManager::setFont(const std::string& fontName, int size) {
    if (size == -1) size = 12;
    font = QFont(fontName.c_str());
    font.setStyleHint(QFont::Monospace);
    font.setPointSize(size);
    QApplication::setFont(font);
}

void WindowManager::addText(std::string text) {
    textStack.emplace_back(text);
    updateText();
}
void WindowManager::addText(std::string text, QColor color) {
    textStack.emplace_back(text);
    updateText();
}

int WindowManager::getTextSize(std::string text) {
    QString str(text.c_str());
    QFontMetrics fm(font);
    return fm.horizontalAdvance(str);
}

bool WindowManager::isSizeFit(std::string str) {
    int size = getTextSize(str);
    return (size < getSizeX());
}

void WindowManager::resizeEvent(QResizeEvent* event) {
    updateText();
}

void WindowManager::keyEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Backspace) {
        //don't erase the thingy character
        if (currentLine.size() < getPointerString().length() + 1) return;
        currentLine.pop_back();
        updateText();
        return;
    }
    //for some reason qt:Key_Enter is 16777221 but the actual enter key is 16777220
    if (event->key() == Qt::Key_Enter || event->key() == 16777220) {
        std::string line = currentLine;
        lastCurrentLine = getPointerString();
        textStack.emplace_back(currentLine);
        currentLine = getPointerString();
        updateText();
        lineReturnEvent(line);
        return;
    }
    //key v
    if (event->key() == 86 && event->text().toStdString() != "v" && event->text().toStdString() != "V") {
        currentLine += FileUtils::getClipboardText();
        updateText();
        return;
    }
    if (event->key() == Qt::Key_Up) {
        if (upIndex >= textStack.size()) return;
        if (upIndex == 0) {
            lastCurrentLine = currentLine;
        }
        upIndex ++;
        if (upIndex < 1) upIndex = 1;
        currentLine = textStack.at(textStack.size() - upIndex);
        updateText();
        return;
    }
    if (event->key() == Qt::Key_Down) {
        if (textStack.empty()) {
            return;
        }
        if (upIndex <= 1) {
            currentLine = lastCurrentLine;
            upIndex = 0;
            updateText();
            return;
        }
        upIndex --;
        currentLine = textStack.at(textStack.size() - upIndex);
        updateText();
        return;
    }
    currentLine += event->text().toStdString();
    updateText();
}

void WindowManager::initEvents() {
    mainWindow.addResizeCallback([this](QResizeEvent *event) { resizeEvent(event); });
    mainWindow.addKeyPressCallback([this](QKeyEvent *event) { keyEvent(event); });
}

void WindowManager::lineReturnEvent(std::string eventLine) {
    stackReturnMethod(std::move(eventLine));
}