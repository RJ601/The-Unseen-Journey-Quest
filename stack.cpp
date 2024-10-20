#include "stack.h"

Stack::Stack(int c)
{
    capacity = c;
    head = tail = NULL;
    size = 0;
}

// deallocate memory
Stack::~Stack()
{
    if (head != NULL)
    {
        for (Node *ptr = head; ptr != NULL; ptr = head)
        {
            head = head->next;
            delete ptr;
        }
        tail = NULL;
    }
}

// push, pop
void Stack::push(Dashboard *d, Block *b)
{
    // if stack full, remove the previous most move 
    if (size == capacity)
    {
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        size--;
    }

    // create and setup new node
    Node *newNode = new Node;
    newNode->block = b;
    newNode->db = d;

    // stack is empty
    if (head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
        tail = newNode;
    }

    // stack not empty
    else
    {
        newNode->next = head->next;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

bool Stack::pop()
{
    // check if stack empty
    if (size == 0)
    {
        return false;
    }

    // remove the last added node/move
    Node *temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
    size--;
    return true;
}

void Stack::set_capacity(int c)
{
    capacity = c;
}

int Stack::get_capacity() const
{
    return capacity;
}

// get contents at top of stack
Dashboard* Stack::get_db() const
{
    return head->db; // dashboard from last added move
}
Block* Stack::get_block() const
{
    return head->block; // block from last added move
}