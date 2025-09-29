//
// Created by Kovacs Dani on 29.09.2025.
//

#include "point.h"

#include <__math/roots.h>

Point::Point(int x, int y) {
    if (x >= 0 && x <= M && y >= 0 && y <= M) {
        this->x = x;
        this->y= y;
    }
    else {
        this->x = 0;
        this->y = 0;
    }
}

int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    double dx = this->x - point.x;
    double dy = this->y - point.y;

    return std::__math::sqrt(dx * dx + dy * dy);

}

