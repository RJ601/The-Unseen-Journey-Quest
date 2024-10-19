#include "player.h"

Player::Player(Maze *m, char mode)
{
    maze = m;

    block = maze->get_head();  // initially, player positioned at first block

    x_coordinate = block->get_x();
    y_coordinate = block->get_y();
    maze->get_head()->set_char('P');

    win = lose = false;

    int distance = calculate_distance(*(maze->get_key()));
    *db = Dashboard(distance, 0, 0, mode);

    *moves = Stack(db->get_undoes());

    // push initial position/state
    moves->push(db, block);
}

bool Player::get_win() const
{
    return win;
}

bool Player::get_lose() const
{
    return lose;
}
    
int Player::calculate_distance(Point key)
{
    // manhattan distance
    int x = (x_coordinate - key.get_x());
    if (x < 0)
        x = x*-1;
    
    int y = (y_coordinate - key.get_y());
    if (y < 0)
        y = y*-1;
    
    int distance = x + y;

    return distance;
}

void Player::move_up()
{
    if (block->get_up())
    {
        change_block(block->get_up());
    }
}

void Player::move_down()
{
    if (block->get_down())
    {
        change_block(block->get_down());
    }
}

void Player::move_left()
{
    if (block->get_left())
    {
        change_block(block->get_left());
    }
}

void Player::move_right()
{
    if (block->get_right())
    {
        change_block(block->get_right());
    }
}

bool Player::undo_move()
{
    // through pop, update block of player and update the dashboard
    moves->pop();
    db = moves->get_db();
    change_block(moves->get_block());
}

void Player::take_coin() 
{
    db->set_score(db->get_score() + 100);

    // update list of coins taken
    coins->insert(block->get_x(), block->get_y(), 'C');

    // remove coin at that point from list of coins in maze
    maze->coins->remove(block->get_x(), block->get_y());

    // additional undo move for each coin taken 
    db->set_undoes(db->get_undoes() + 1);
}
    
void Player::calculate_score()
{
    while (db->get_moves() > 0)
    {
        db->set_score(db->get_score() + 20);
        db->set_moves(db->get_moves() - 1);
    }
}

void Player::display_dashboard()
{
    db->display();
}
    
void Player::display() 
{
    int x = 0;
    int y = 0;

    if (win)
    {
        calculate_score();

        // display score
        mvprintw(x, y, "YOU WIN!");
        mvprintw(x, y + 10, "Score:");
        mvprintw(x + 20, y + 10, "%i", db->get_score());

        // display coins collected in loop
        coins->display(x, y + 20);
    }

    if (lose)
    {
        mvprintw(x, y, "YOU LOSE!");
    }
}

void Player::change_block(Block *next)
{
    block->set_char('-');
    block = next;

    // check if coin or bomb on new position 
    if (block->get_char() == 'C')
        take_coin();
    else if (block->get_char() == 'B')
        lose = true;

    block->set_char('P');
    x_coordinate = block->get_x();
    y_coordinate = block->get_y();

    // check if key reached
    Point k = maze->get_key();
    if ((x_coordinate == k.get_x()) && (y_coordinate == k.get_y()))
        db->set_key(true);

    // check if door reached
    Point d = maze->get_door();
    if ((x_coordinate == d.get_x()) && (y_coordinate == d.get_y()) && db->get_key())
        win = true;

    // check if key or door reached
    int distance;
    if (db->get_key() == false)
        distance = calculate_distance(maze->get_key());
        db->set_sense(distance);

    db->set_moves(db->get_moves() - 1);
    moves->push(db, block);
}