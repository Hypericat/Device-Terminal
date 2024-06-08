//
// Created by Hypericats on 6/8/2024.
//

#include "CustomLabel.hpp"

CustomLabel::CustomLabel(int lineSpacing) : lineSpacing(lineSpacing){

}

void CustomLabel::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    QRect rect = contentsRect();

    QStringList lines = text().split('\n');
    int lineHeight = QFontMetrics(font()).height() + lineSpacing;

    for (const QString& line : lines) {
        painter.drawText(rect, Qt::AlignTop | Qt::TextWordWrap, line);
        rect.adjust(0, lineHeight, 0, 0);
    }
}

void CustomLabel::setLineSpacing(int lineSpacing) {
    this->lineSpacing = lineSpacing;
}

int CustomLabel::getLineSpacing() {
    return lineSpacing;
}
