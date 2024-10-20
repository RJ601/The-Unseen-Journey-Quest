#ifndef PLAYER_H
#define PLAYER_H

#include "dashboard.h"
#include "maze.h"
#include "stack.h"

// player moves, interacts with objects, has dashboard object (composition)

class Player: public Point
{
    int distance;
    Dashboard *db; // composition
    Maze *maze; // aggregation b/w player and maze = maze has address for list of coins, bomb, key and door 
    Block *block; // address of the block the player is cureently on - we get this through maze
    Objects *coins; // list of coins taken
    Stack *moves; // stack of moves

    // to check if player won or lost
    bool win;
    bool lose;

public:
    Player(Maze *m, char mode);
    ~Player();
    int calculate_distance(Point key); // called after every valid move, would update moves too, and sensing - distnace bw player and key
    bool get_win() const;
    bool get_lose() const;
    void move_up();
    void move_down();
    void move_left();
    void move_right();
    bool undo_move();
    void take_coin(); // increase score
    void calculate_score(); // through display - when player wins, calculate final score
    void display_dashboard();
    void display(); // when player wins
    void change_block(Block* next); // returns true if player alive after changing position
};

#endif