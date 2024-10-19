#ifndef STACK_H
#define STACK_H

#include "dashboard.h"
#include "block.h"

// implemented through list - LIFO
class Stack
{
    class Node
    {
        // each node in the list has player's dashboard and player's block at that state 
        Dashboard *db;
        Block block;
    };

    // head would point at last move made
    Node *head;

    // limited capacity - as limited undoes
    int capacity;

public:
    Stack();

    // push, pop
    void push(Dashboard *d, Block *b);
    void pop();

    void set_capacity(int c);

    int get_capacity() const;

    // get contents at top of stack
    Dashboard* get_db() const;
    Block* get_block() const;
};

#endif