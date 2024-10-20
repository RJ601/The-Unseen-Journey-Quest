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

    keypad(stdscr, TRUE); // Enable special keys
    cbreak();             // Disable line buffering, pass input to program immediately
    noecho();             // Do not display characters when typed

    bool undo;

    while ((lose == false) && (win == false))
    {
        // Clear the screen
        clear();

        player->display_dashboard();

        maze->display();
        refresh();

        int input = getch(); // Wait for user to press any key
        switch (input)
        {
            case KEY_UP:
                player->move_up();
                break;
            case KEY_DOWN:
                player->move_down();
                break;
            case KEY_LEFT:
                player->move_left();
                break;
            case KEY_RIGHT:
                player->move_right();
                break;
            case ' ':
                undo = player->undo_move();
                break;
            default:
                break;
        }

        win = player->get_win();
        lose = player->get_lose();
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
