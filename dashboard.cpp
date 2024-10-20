#include "dashboard.h"

using namespace std;

Dashboard::Dashboard(int d, int x, int y, char m)
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
int Dashboard::get_distance() const
{
    return distance;
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
    int entry_gap = 20;
    int variable_gap = 30;
    int y_gap = 2;

    mvprintw(y_coordinate, x_coordinate, "Mode:");
    mvprintw(y_coordinate, x_coordinate + entry_gap, "%c", mode);

    mvprintw(y_coordinate + y_gap, x_coordinate, "Remaining Moves:");
    mvprintw(y_coordinate + y_gap, x_coordinate + entry_gap, "%i", moves);
    mvprintw(y_coordinate + y_gap, x_coordinate + entry_gap + variable_gap, "Remaining Undoes:");
    mvprintw(y_coordinate + y_gap, x_coordinate + entry_gap + variable_gap + entry_gap, "%i", undoes);

    mvprintw(y_coordinate + y_gap*2, x_coordinate, "Score:");
    mvprintw(y_coordinate + y_gap*2, x_coordinate + entry_gap, "%i", score);
    mvprintw(y_coordinate + y_gap*2, x_coordinate + entry_gap + variable_gap, "Key Status:");
    if (key)
        mvprintw(y_coordinate + y_gap*2, x_coordinate + entry_gap + variable_gap + entry_gap, "Found");
    else
        mvprintw(y_coordinate + y_gap*2, x_coordinate + entry_gap + variable_gap + entry_gap, "Not Found");

    mvprintw(y_coordinate + y_gap*3, x_coordinate, "Hint:");
    switch (sensing)
    {
        case 0:
            mvprintw(y_coordinate + y_gap*3, x_coordinate + entry_gap, "Further Away");
            break;
        case 1:
            mvprintw(y_coordinate + y_gap*3, x_coordinate + entry_gap, "Getting Closer");
            break;
    }
}