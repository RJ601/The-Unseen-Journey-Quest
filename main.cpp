// player aur maze interact here
// update player coordinates and dashboard and maze's specifc blocks after each move
// points array for coins, bombs etc are initialized here

#include "maze.h"
#include "player.h"
#include "menu.h"

int main() 
{
    // Initialize the curses screen
    initscr();            // Start curses mode
    start_color();        // Start color functionality
    init_pair(1, COLOR_CYAN, COLOR_BLACK); // Define a color pair
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    // initialize maze and player
    char mode = 'E';
    Maze *maze;
    *maze = Maze(mode);
    Player *player;
    *player = Player(maze, mode);

    bool lose = false, win = false;

    Menu menu;

    // Clear the screen
    clear();

    // display the menu 
    menu.display();

    // Refresh the screen to show changes
    refresh();

    // take user input and update 
    char choice = getch();

    switch(choice)
    {
        case '1':
            break;
        case '2':
            *maze = Maze(mode);
            *player = Player(maze, mode);
            break;
        case '3':
            mode = menu.select_level();  
            *maze = Maze(mode);
            *player = Player(maze, mode);
            break;
        default:
            clear();
            mvprintw(0, 0, "Invalid Input!");
            refresh();
            return 0;
    }

    while ((lose == false) && (win == false))
    {
        // Clear the screen
        clear();

        // once resume or restart selected from menu, create dashboard and maze

        // if restarted, reset maze and player

        // Refresh the screen to show changes
        refresh();

        // Wait for user input
        getch(); // Wait for user to press any key
    }

    clear();
    player->display();
    refresh();

    getch(); // Wait for user to press any key

    // End curses mode
    endwin();
    return 0;
}
