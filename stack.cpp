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
            delete ptr->block;
            delete ptr->db;
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
        cout<<"capacity: "<<capacity<<endl;
        Node* temp = tail;
        tail = tail->prev;
        delete temp->db;
        delete temp;
        size--;
    }

    // create and setup new node 
    Node *newNode = new Node;
    newNode->block = b;

    // deep copy so that changes in main dashboard not reflected in dashboards from previous states
    newNode->db = new Dashboard(d->get_distance(), d->get_x(), d->get_y(), d->get_mode());
    newNode->db->set_key(d->get_key());
    newNode->db->set_moves(d->get_moves());
    newNode->db->set_score(d->get_score());
    newNode->db->set_undoes(d->get_undoes());

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
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    size++;
}

bool Stack::pop()
{
    // check if stack empty
    if (size == 1) 
    {
        cout<<"Stack Empty"<<endl;
        return false;
    }

    // remove the last added node/move
    Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;
    else
        cout<<"HEAD NULL"<<endl;

    delete temp->db;
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

void Stack::display()
{
    for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        clear();
        ptr->db->display();
        refresh();
        getch();
    }
}