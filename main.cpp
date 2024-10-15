// player aur maze interact here
// update player coordinates and dashboard and maze's specifc blocks after each move
// points array for coins, bombs etc are initialized here

#include <curses.h>

int main() 
{
    // Initialize the curses screen
    initscr();            // Start curses mode
    start_color();        // Start color functionality
    init_pair(1, COLOR_CYAN, COLOR_BLACK); // Define a color pair
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);

    // initialize maze and player

    bool lose = false, win = false;

    while ((lose == false) && (win == false))
    {
        // Clear the screen
        clear();

        // display the menu and update level

        // Refresh the screen to show changes
        refresh();

        // once resume or restart selected from menu, create dashboard and maze

        // if restarted, reset maze and player

        // Refresh the screen to show changes
        refresh();

        // Wait for user input
        getch(); // Wait for user to press any key
    }

    // End curses mode
    endwin();
    return 0;
}
