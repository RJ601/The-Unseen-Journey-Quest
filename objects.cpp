#include "objects.h"

    Objects::Objects()
    {
        head = NULL;
    }
    Objects::~Objects()
    {
        if (head != NULL)
        {
            for (Node *ptr = head; ptr != NULL; ptr = head)
            {
                head = head->next;
                delete ptr;
            }
        }
    }
    
    // append
    void Objects::insert(int x, int y, char obj)
    {
        // setup new node
        Node *newNode = new Node;
        newNode->set_x(x);
        newNode->set_y(y);
        newNode->obj = obj;

        // cout<<"INSERTION"<<endl;
        // cout<<"X: "<<newNode->get_x()<<" Y: "<<newNode->get_y()<<" OBJ: "<<newNode->obj<<endl;

        // if list is empty
        if (head == NULL)
        {
            newNode->next == NULL;
        }
        else
        {
            newNode->next = head;
        }

        head = newNode;
    }

    // remove object with given coordinates from list
    void Objects::remove(int x, int y)
    {
        Node *prev = head;
        for (Node *ptr = head; ptr != NULL; prev = ptr, ptr = ptr->next)
        {
            if ((ptr->get_x() == x) && (ptr->get_y() == y))
            {
                prev->next = ptr->next;
                delete ptr;
            }
        }
    }

    // check if any node in the list exists at the given points
    bool Objects::check(int x, int y)
    {
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if ((ptr->get_x() == x) && (ptr->get_y() == y))
            {
                return true;
            }
        }
        //cout<<"Check Completed"<<endl;

        return false;
    }

    // display list - name of object and x and y coordinates
    void Objects::display(int x, int y)
    {
        clear();
        mvprintw(x, y, "Coins Collected:");

        x += 30;
        for (Node *ptr = head; ptr != NULL; ptr = ptr->next)
        {
            //cout<<ptr->get_x()<<endl;
            mvprintw(y, x, "(%i, %i)", ptr->get_x(), ptr->get_y());
            refresh();
            getch();
            x += 10;
        }
    }