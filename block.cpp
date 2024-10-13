#include "block.h"

Block::Block()
{
    x_coordinate = 0;
    y_coordinate = 0;
    up = down = left = right = NULL;
    object = '\0';
    size = 10;
}
Block::Block(float x, float y, char obj = '\0', Block *u = NULL, Block *d = NULL, Block *l = NULL, Block *r = NULL)
{
    x_coordinate = x;
    y_coordinate = y;
    up = u;
    down = d;
    left = l;
    right = r;
    object = obj;
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

void Block::display_block()
{
    for (int count = 0; count < size/2; count++)
    {
        cout<<' ';
    }

    if ((object == 'd') || (object == 'k'))
    {
        cout<<"-";
    }
    else
    {
        cout<<object;
    }

    for (int count = 0; count < size/2; count++)
    {
        cout<<' ';
    }
}