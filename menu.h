#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <curses.h>

class Menu // options to restart, resume, select level
{
    char mode;
    char choice;
public:
    Menu();
    void display();
    char select_level();
};

#endif