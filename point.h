#include <iostream>

class Point
{
protected:
    int x_coordinate;
    int y_coordinate;

public:
    Point();
    Point(int x, int y);
    void set_x(int x);
    void set_y(int y);
    int get_x() const;
    int get_y() const;
};