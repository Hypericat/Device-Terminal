//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_CUSTOMTEXTEDIT_HPP
#define CMD_CUSTOMTEXTEDIT_HPP

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QPainter>

class CustomTextEdit : public QTextEdit {
public:
    CustomTextEdit(int lineSpacing);
    void setLineSpacing(int lineSpacing);
    int getLineSpacing();
    void setKeyPressCallback(const std::function<void(QKeyEvent*)>& callback);

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    int lineSpacing;
    std::function<void(QKeyEvent*)> keyCallback;
};


#endif //CMD_CUSTOMTEXTEDIT_HPP
