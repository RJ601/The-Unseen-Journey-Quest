#ifndef MAZE_H
#define MAZE_H

#include "dashboard.h"
#include "block.h"
#include "objects.h"

// through linked list
// random points initialized in constructor for coins and bombs, door and key

class Maze
{
    Block *head; // list of blocks - address of head 
    Block *tail;
    Objects *coins; // list of coins - randomly generated x and y coordinates
    Objects *bombs; // list of bombs - randomly generated x and y coordinates
    Point *key;
    Point *door;
    int size; // size of maze
    char mode; // level

public:
    Maze(char m);

    ~Maze(); // deallocate memory for blocks

    void set_head(Block *b);
    void set_coins(Objects *c);
    void set_bombs(Objects *b);
    void set_key(int x, int y);
    void set_door(int x, int y);

    Block* get_head() const;
    Objects* get_coins() const;
    Objects* get_bombs() const;
    Point* get_key() const;
    Point* get_door() const;

    void insert(int x, int y, char obj = '-');

    // display maze
    void display();
};

#endif