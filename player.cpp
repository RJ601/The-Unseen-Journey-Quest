#include "player.h"

Player::Player(Maze *m, char mode)
{
    maze = m;

    block = maze->get_head();  // initially, player positioned at first block

    x_coordinate = block->get_x();
    y_coordinate = block->get_y();
    maze->get_head()->set_char('P');

    win = lose = false;

    Point key = *(maze->get_key());
    Point door = *(maze->get_door());
    int distance = calculate_distance(key);
    
    int x_dist = key.get_x() - door.get_x();
    int y_dist = key.get_y() - door.get_y();
    if (x_dist < 0)
        x_dist = x_dist*-1;
    if (y_dist < 0)
        y_dist = y_dist*-1;

    distance = distance + x_dist/8 + y_dist/4;
    db = new Dashboard(distance, 0, 0, mode);

    moves = new Stack(db->get_undoes());

    coins = new Objects;

    // push initial position/state
    moves->push(db, block);
}

Player::~Player()
{
    if (db)
        delete db;
    if (moves)
        delete moves;
    if (coins)
        delete coins;
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
    
    int distance = x/8 + y/4;

    return distance;
}

void Player::move_up()
{
    if (block->get_up())
    {
        change_block(block->get_up());
        change_moves();
    }
}

void Player::move_down()
{
    if (block->get_down())
    {
        change_block(block->get_down());
        change_moves();
    }
}

void Player::move_left()
{
    if (block->get_left())
    {
        change_block(block->get_left());
        change_moves();
    }
}

void Player::move_right()
{
    if (block->get_right())
    {
        change_block(block->get_right());
        change_moves();
    }
}

bool Player::undo_move()
{
    if (db->get_undoes() == 0)
        return false;


    // through pop, update block of player and update the dashboard
    if (moves->pop())
    {
        delete db;
        db = moves->get_db();
        db->set_undoes(db->get_undoes() - 1);
        
        change_block(moves->get_block());
        return true;
    }

    return false;
}

void Player::take_coin() 
{
    // update score
    db->set_score(db->get_score() + 100);

    // additional undo move for each coin taken 
    db->set_undoes(db->get_undoes() + 1);

    cout<<"Updated"<<endl;

    // update list of coins taken
    coins->insert(block->get_x(), block->get_y(), 'C');

    cout<<"Coin Inserted"<<endl;

    // remove coin at that point from list of coins in maze
    maze->get_coins()->remove(block->get_x(), block->get_y());

    cout<<"Coin removed"<<endl;
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
        mvprintw(x, y + 2, "Score:");
        mvprintw(x + 20, y + 2, "%i", db->get_score());

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
    Point k = *(maze->get_key());
    if ((x_coordinate == k.get_x()) && (y_coordinate == k.get_y()))
        db->set_key(true);

    // check if door reached
    Point d = *(maze->get_door());
    if ((x_coordinate == d.get_x()) && (y_coordinate == d.get_y()) && db->get_key())
        win = true;

    // check if key or door reached
    int distance;
    if (db->get_key() == false)
        distance = calculate_distance(*(maze->get_key()));
        db->set_sense(distance);
}

void Player::change_moves()
{
    db->set_moves(db->get_moves() - 1);
    moves->push(db, block);

    if (db->get_moves() == 0)
    {
        lose = true;
    }
}