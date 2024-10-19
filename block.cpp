#include "block.h"

Block::Block()
{
    x_coordinate = 0;
    y_coordinate = 0;
    up = down = left = right = NULL;
    size = 10;
    character = '-';
}
Block::Block(int x, int y, Block *u = NULL, Block *d = NULL, Block *l = NULL, Block *r = NULL, char obj = '-')
{
    x_coordinate = x;
    y_coordinate = y;
    character = obj;
    up = u;
    down = d;
    left = l;
    right = r;
    size = 10;
}

void Block::set_up(Block *u)
{
    up = u;
}
void Block::set_down(Block *d)
{
    down = d;
}
void Block::set_left(Block *l)
{
    left = l;
}
void Block::set_right(Block *r)
{
    right = r;
}
void Block::set_size(int s)
{
    size = s;
}
void Block::set_char(char obj)
{
    character = obj;
}

Block* Block::get_up() const
{
    return up;
}
Block* Block::get_down() const
{
    return down;
}
Block* Block::get_left() const
{
    return left;
}
Block* Block::get_right() const
{
    return right;
}
int Block::get_size() const
{
    return size;
}
char Block::get_char() const
{
    return character;
}

void Block::display_block()
{
    // if door or key, keep it hidden
    if ((character == 'K') || (character == 'D'))
        mvprintw(x_coordinate, y_coordinate, "%c", '-');
    else
        mvprintw(x_coordinate, y_coordinate, "%c", character);
}