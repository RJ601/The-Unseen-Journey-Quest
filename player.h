#include <iostream>
#include "dashboard.h"
#include "point.h"

// player moves, interacts with objects, has dashboard object (composition)

class Player: public Point
{
    int distance;
    Dashboard db;

public:
    Player();
    Player(float x, float y);
    void calculate_distance(); // called after every valid move, would update moves too, and sensing - distnace bw player and key
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    void take_coin(); // increase score
    void take_key(); // update key status 
    void reset(); // when player touches bomb
    void calculate_score(); // through display - when player wins, calculate final score
    void display(); // when player wins
};