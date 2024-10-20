#include <curses.h>  // Include the PDCurses header

int main() {
    // Initialize the PDCurses library
    initscr();             // Start curses mode
    cbreak();              // Line buffering disabled, Pass on evertything to me
    noecho();              // Don't echo pressed keys

    // Get the size of the window
    int height, width;
    getmaxyx(stdscr, height, width); // Get the size of the window

    // Print a message at the center of the window
    const char* message = "Hello, PDCurses!";
    mvprintw(height / 2, (width) / 2, "%s", message);
    
    // Refresh to show the output
    refresh();            // Print it on to the real screen

    // Wait for user input
    getch();              // Wait for a key press

    // End the PDCurses session
    endwin();             // End curses mode
    return 0;
}
