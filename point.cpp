#include "point.h"

Point::Point()
{
    x_coordinate = 0;
    y_coordinate = 0;
}

Point::Point(int x, int y)
{
    x_coordinate = x;
    y_coordinate = y;
}

void Point::set_x(int x)
{
    x_coordinate = x;
}

void Point::set_y(int y)
{
    y_coordinate = y;
}


int Point::get_x() const
{
    return x_coordinate;
}

int Point::get_y() const
{
    return y_coordinate;
}
