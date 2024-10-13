#include "point.h"

Point::Point()
{
    x_coordinate = 0;
    y_coordinate = 0;
}
Point::Point(float x, float y)
{
    x_coordinate = x;
    y_coordinate = y;
}

void Point::set_x(float x)
{
    x_coordinate = x;
}
void Point::set_y(float y)
{
    y_coordinate = y;
}
void Point::set_obj(char obj)
{
    object = obj;
}

float Point::get_x() const
{
    return x_coordinate;
}
float Point::get_y() const
{
    return y_coordinate;
}
char Point::get_obj() const
{
    return object;
}