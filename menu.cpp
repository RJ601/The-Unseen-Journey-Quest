#include "menu.h"

using namespace std;

Menu::Menu()
{
    mode = 'E';
    choice = 1;
}

void Menu::display()
{
    mvprintw(0, 0, "Select an option:");
    mvprintw(0, 20, "1) Resume");
    mvprintw(0, 30, "2) Restart");
    mvprintw(0, 40, "3) Modes");
}

int Menu::select_level()
{

}
