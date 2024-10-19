#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <curses.h>

class Menu // options to restart, resume, select level
{
    char mode;
    int choice;
public:
    Menu();
    void display();
    int select_level();
};

#endif