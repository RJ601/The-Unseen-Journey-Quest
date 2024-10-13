#include <iostream>
#include "point.h"

using namespace std;

// represents a block on the grid, implemented using 4d linked list
class Block: public Point
{
    int size;
    Block *up;
    Block *down;
    Block *left;
    Block *right;

public:
    Block();
    Block(float x, float y, char obj = '\0', Block *u = NULL, Block *d = NULL, Block *l = NULL, Block *r = NULL);

    void set_up(Block *u);
    void set_down(Block *d);
    void set_left(Block *l);
    void set_right(Block *r);
    void set_size(int s);

    Block* get_up() const;
    Block* get_down() const;
    Block* get_left() const;
    Block* get_right() const;
    int get_size() const;

    void display_block();
};


