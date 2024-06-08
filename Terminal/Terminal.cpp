//
// Created by Hypericats on 6/8/2024.
//

#include "Terminal.hpp"

Terminal::Terminal(WindowManager &window) : window(window) {

}

void Terminal::run() {
    window.addText("Lorem Ipsum");
    window.addText("Lorem Ipsum");
    window.addText("Lorem Ipsum");
    window.addText("Lorem Ipsum");
    window.addText("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum");
    while (true) {
       executeUpdate(window.getUpdateStack());
    }
}

void Terminal::executeUpdate(std::string windowUpdate) {
    if (windowUpdate.empty()) return;
}
