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

    // testing
    clear();
    mvprintw(0,0, "Start");
    refresh();
    getch();

    Maze *maze = new Maze(mode);
    // testing
    clear();
    mvprintw(0,0, "Maze created");
    refresh();
    getch();
    Player *player = new Player(maze, mode);

    // testing
    clear();
    mvprintw(0,0, "Objects created");
    refresh();
    getch();


    bool lose = false, win = false;

    Menu menu;

    // Clear the screen
    clear();

    // display the menu 
    menu.display();

    // take user input and update 
    char choice = getch();

    switch(choice)
    {
        case '1':
            break;
        case '2':
            delete maze;
            delete player;
            maze = new Maze(mode);
            player = new Player(maze, mode);
            break;
        case '3':
            mode = menu.select_level(); 
            if (mode == 'I')
            {
                return 0;
            } 
            delete maze;
            delete player;
            maze = new Maze(mode);
            player = new Player(maze, mode);
            break;
        default:
            clear();
            mvprintw(0, 0, "Invalid Input!");
            refresh();
            getch();
            delete maze;
            delete player;
            return 0;
    }

    while ((lose == false) && (win == false))
    {
        // Clear the screen
        clear();

        // once resume or restart selected from menu, display maze
        mvprintw(0, 0, "Maze Printing...");
        refresh();
        getch();
        clear();

        player->display_dashboard();

        maze->display();
        refresh();
        getch();

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
    delete player;
    delete maze;
    endwin();
    return 0;
}
