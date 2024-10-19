#ifndef BLOCK_H
#define BLOCK_H

#include "point.h"
#include <curses.h>

using namespace std;

// represents a block on the grid, implemented using 4d linked list
class Block: public Point
{
    // should we have a character object of each block or a node for each block 
    char character; // character on the block - assigned during maze formation, after coins and bombs have been initialized
    int size;
    Block *up;
    Block *down;
    Block *left;
    Block *right;

public:
    Block();
    Block(int x, int y, char obj = '-', Block *u = NULL, Block *d = NULL, Block *l = NULL, Block *r = NULL);

    void set_up(Block *u);
    void set_down(Block *d);
    void set_left(Block *l);
    void set_right(Block *r);
    void set_size(int s);
    void set_char(char obj);

    Block* get_up() const;
    Block* get_down() const;
    Block* get_left() const;
    Block* get_right() const;
    int get_size() const;
    char get_char() const;

    void display_block();
};


#endif