//
// Created by Hypericats on 6/8/2024.
//

#ifndef CMD_CUSTOMLABEL_HPP
#define CMD_CUSTOMLABEL_HPP

#include <QApplication>
#include <QLabel>
#include <QPainter>

class CustomLabel : public QLabel {
public:
    CustomLabel(int lineSpacing);
    void setLineSpacing(int lineSpacing);
    int getLineSpacing();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    int lineSpacing;
};


#endif //CMD_CUSTOMLABEL_HPP
