#include "menu.h"

using namespace std;

Menu::Menu()
{
    mode = 'E';
    choice = '/0';
}

void Menu::display()
{
    mvprintw(0, 0, "Select an option:");
    mvprintw(0, 20, "1) Resume");
    mvprintw(0, 30, "2) Restart");
    mvprintw(0, 40, "3) Modes");
}

char Menu::select_level()
{
    mvprintw(0, 0, "Select an option:");
    mvprintw(0, 20, "1) Easy");
    mvprintw(0, 30, "2) Medium");
    mvprintw(0, 40, "3) Hard");  

    refresh();  

    choice = getch();
    switch(choice)
    {
        case '1':
            return 'E';
        case '2':
            return 'M';
        case '3':
            return 'H';
        default:
            clear();
            mvprintw(0, 0, "Invalid");
            refresh();
            return 'I';
    }
}
