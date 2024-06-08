//
// Created by Hypericats on 6/7/2024.
//

#include "Vector2i.hpp"

int Vector2i::getX() const {
    return x;
}

int Vector2i::getY() const {
    return y;
}

void Vector2i::setX(int x) {
    Vector2i::x = x;
}

void Vector2i::setY(int y) {
    Vector2i::y = y;
}

Vector2i::Vector2i(int xVal, int yVal) : x(xVal), y(yVal) {

}

Vector2i::Vector2i(QSize Qsize) : x(Qsize.width()), y(Qsize.height()) {

}
