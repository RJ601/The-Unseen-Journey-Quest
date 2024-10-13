#include <iostream>

class Point
{
protected:
    float x_coordinate;
    float y_coordinate;
    char object; // object at the point

public:
    Point();
    Point(float x, float y);
    void set_x(float x);
    void set_y(float y);
    void set_obj(char obj);
    float get_x() const;
    float get_y() const;
    char get_obj() const;
};