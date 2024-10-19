#ifndef OBJECTS_H
#define OBJECTS_H

#include "point.h"
#include <curses.h>


// for coins and bombs
class Objects
{
public:
    class Node: public Point
    {
    public:
        char obj;
        Node *next;
    };

    Node *head;

    Objects();
    ~ Objects();
    
    // append
    void insert(int x, int y, char obj);

    // remove from list
    void remove(int x, int y);

    // check if any node in the list exists at the given points
    bool check(int x, int y);

    // display list - name of object and x and y coordinates
    void display(int x, int y);
};

#endif