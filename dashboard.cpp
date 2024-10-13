#include "dashboard.h"
#include "point.h"
#include <iomanip>

using namespace std;

Dashboard::Dashboard(int d, char m = 'E')
{
    mode = m;
    score = 0;
    key = false;
    distance = d;

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
        sensing = "Getting Closer";
    else if (distance < d)
        sensing = "Further Away";
    else
        sensing = "";

    // update distance
    distance = d; 
}

void Dashboard::display() const
{
    int entry_gap = 7;

    cout<<"Mode:"<<setw(entry_gap)<<mode<<endl;
    cout<<"Remaining Moves:"<<setw(entry_gap)<<moves<<setw(40)<<"Remaining Undoes:"<<setw(entry_gap)<<undoes<<endl;
    cout<<"Score:"<<setw(entry_gap)<<score<<setw(35)<<"Key Status:";

    if (key)
        cout<<setw(entry_gap)<<"Found"<<endl;
    else
        cout<<setw(entry_gap)<<"Not Found"<<endl;

    cout<<"Hint:"<<setw(6 + sensing.length())<<sensing<<endl;
    cout<<setfill('-')<<setw(70)<<endl;
}