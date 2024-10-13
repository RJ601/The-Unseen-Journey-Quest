#include <iostream>

class Menu // options to restart, resume, select level
{
    char level;
    int choice;
public:
    Menu();
    void display_menu();
    void select_level();
    bool restart(); // reset all values on dashboard and maze - recreate object for maze and player
};