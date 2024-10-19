#ifndef STACK_H
#define STACK_H

#include "dashboard.h"
#include "block.h"

// Stack (LIFO) for undoes - implemented through singly linked list 
class Stack
{
    class Node
    {
    public:
        // each node in the list has player's dashboard and player's block at that state 
        Dashboard *db;
        Block *block;
        Node* next;
        Node *prev;
    };

    // head would point at last move made
    Node *head;
    Node *tail;

    // limited capacity - as limited undoes
    int capacity;

    // number of items currently in stack
    int size;

public:
    Stack(int c);
    ~Stack();

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