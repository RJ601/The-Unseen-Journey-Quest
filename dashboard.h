#include <iostream>
#include <curses.h>
#include "point.h"

using namespace std;

class Dashboard: public Point
{
    int moves; //calculated according to distance and level
    int score; // calculated according to collected coins and remaining moves
    int key; 
    int distance;
    int undoes;
    char mode; // difficulty level
    int sensing;

public: 
    Dashboard(int d, int x, int y, char m = 'E'); 

    int get_moves() const;
    int get_score() const;
    int get_key() const;
    int get_undoes() const;
    char get_mode() const;

    void set_moves(int d);
    void set_score(int s);
    void set_key(int k);
    void set_undoes(int u);
    void set_mode(char m);
    void set_sense(int d);

    void display() const;
};