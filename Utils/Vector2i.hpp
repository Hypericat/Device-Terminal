//
// Created by Hypericats on 6/7/2024.
//

#ifndef CMD_VECTOR2I_HPP
#define CMD_VECTOR2I_HPP
#include <QLabel>


class Vector2i {
public:
    Vector2i(int x, int y);
    Vector2i(QSize Qsize);

    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int y);

private:
    int x;
    int y;
};


#endif //CMD_VECTOR2I_HPP
