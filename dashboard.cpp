#include "dashboard.h"
#include "point.h"

using namespace std;

Dashboard::Dashboard(int d, int x = 0, int y = 0, char m = 'E')
{
    mode = m;
    score = 0;
    key = false;
    distance = d;
    sensing = -1;
    x_coordinate = x;
    y_coordinate = y;

    if (mode == 'E')
    {
        undoes = 6;
        moves = d + 6;
    }
    else if (mode == 'M')
    {
        undoes = 4;
        moves = d + 2;
    }
    else if (mode == 'H')
    {
        undoes = 1;
        moves = d;
    }
    else // error handling
    {
        cout<<"Error Detected! Shutting Down..."<<endl;
    }
}

int Dashboard::get_moves() const
{
    return moves;
}
int Dashboard::get_score() const
{
    return score;
}
int Dashboard::get_key() const
{
    return key;
}
int Dashboard::get_undoes() const
{
    return undoes;
}
char Dashboard::get_mode() const
{
    return mode;
}

void Dashboard::set_moves(int m)
{
    moves = m;
}
void Dashboard::set_score(int s)
{
    score = s;
}
void Dashboard::set_key(int k)
{
    key = k;
}
void Dashboard::set_undoes(int u)
{
    undoes = u;
}
void Dashboard::set_mode(char m)
{
    mode = m;
}
void Dashboard::set_sense(int d)
{
    // compare to previous distance for sensing
    if (distance > d)
        sensing = 1; // getting closer
    else if (distance < d)
        sensing = 0; // further away
    else
        sensing = -1; // neither

    // update distance
    distance = d; 
}

void Dashboard::display() const
{
    int entry_gap = 5;
    int variable_gap = 30;
    int y_gap = 10;

    mvprintw(x_coordinate, y_coordinate, "Mode:");
    mvprintw(x_coordinate + entry_gap, y_coordinate, "%c", mode);

    mvprintw(x_coordinate, y_coordinate + y_gap, "Remaining Moves:");
    mvprintw(x_coordinate + entry_gap, y_coordinate + y_gap, "%i", moves);
    mvprintw(x_coordinate + entry_gap + variable_gap, y_coordinate + y_gap, "Remaining Undoes:");
    mvprintw(x_coordinate + entry_gap + variable_gap + entry_gap, y_coordinate + y_gap, "%i", undoes);

    mvprintw(x_coordinate, y_coordinate + y_gap*2, "Score:");
    mvprintw(x_coordinate + entry_gap, y_coordinate + y_gap*2, "%i", score);
    mvprintw(x_coordinate + entry_gap + variable_gap, y_coordinate + y_gap*2, "Key Status:");
    if (key)
        mvprintw(x_coordinate + entry_gap + variable_gap + entry_gap, y_coordinate + y_gap*2, "Found");
    else
        mvprintw(x_coordinate + entry_gap + variable_gap + entry_gap, y_coordinate + y_gap*2, "Not Found");

    mvprintw(x_coordinate, y_coordinate + y_gap*3, "Hint:");
    switch (sensing)
    {
        case 0:
            mvprintw(x_coordinate + entry_gap, y_coordinate + y_gap*3, "Further Away");
            break;
        case 1:
            mvprintw(x_coordinate + entry_gap, y_coordinate + y_gap*3, "Getting Closer");
            break;
    }
}