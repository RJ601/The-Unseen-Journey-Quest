#ifndef OBJECTS_H
#define OBJECTS_H

#include "point.h"
#include <iostream>
#include <curses.h>

using namespace std;


// for coins and bombs - singly linked list
class Objects
{
    class Node: public Point
    {
    public:
        char obj;
        Node *next;
    };

    Node *head;

public:
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