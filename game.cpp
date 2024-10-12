#include <iostream>

using namespace std;

// represents a block on the grid, implemented using 4d linked list
class Block
{
    float x_coordinate;
    float y_coordinate;
    Block *up;
    Block *down;
    Block *left;
    Block *right;
    char object; // object currently on that block

public:
    Block()
    {
        x_coordinate = 0;
        y_coordinate = 0;
        up = down = left = right = NULL;
        object = '\0'
    }
    Block(float x, float y, char obj = '\0', Block *u = NULL, Block *d = NULL, Block *l = NULL, Block *r = NULL)
    {
        x_coordinate = x;
        y_coordinate = y;
        up = u;
        down = d;
        left = l;
        right = r;
        object = obj;
    }

    void set_x(float x)
    {
        x_coordinate = x;
    }
    void set_y(float y)
    {
        y_coordinate = y;
    }
    void set_up(Block *u)
    {
        up = u;
    }
    void set_down(Block *d)
    {
        down = d;
    }
    void set_left(Block *l)
    {
        left = l;
    }
    void set_right(Block *r)
    {
        right = r;
    }

    float get_x() const
    {
        return x_coordinate;
    }
    float get_y() const
    {
        return y_coordinate;
    }
    Block* get_up() const
    {
        return up;
    }
    Block* get_down() const
    {
        return down;
    }
    Block* get_left() const
    {
        return left;
    }
    Block* get_right() const
    {
        return right;
    }
};


