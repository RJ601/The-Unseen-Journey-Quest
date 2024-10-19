#include "maze.h"

Maze::Maze(char m) 
{
    head = NULL;
    tail = NULL;

    // set size and mode
    mode = m;
    if (m == 'E')
        size = 10;
    else if (m == 'M')
        size = 15;
    else if (m == 'H')
        size = 20;
    else // error handling
    {
        cout<<"Error Detected! Shutting Down..."<<endl;
    }

    int x = 0, y = 50;

    srand(time(0));

    int min_y = 50;                       // The minimum value in the range
    int max_y = (size * 10) + 40;          // The maximum value in the range

    // initialize coins list - random x, y coordinates
    for (int count = 0; count < size; count++)
    {
        // randomly choose a block
        x = (rand() % size) * 10;
        y = (rand() % ((max_y - min_y) / 10 + 1)) * 10 + min_y;

        coins->insert(x, y, 'C');
    }

    // initialize bombs list - random x, y coordinates
    for (int count = 0; count < size/5; count++)
    {
        // randomly choose a block
        x = (rand() % size) * 10;
        y = (rand() % ((max_y - min_y) / 10 + 1)) * 10 + min_y;

        bombs->insert(x, y, 'B');
    }

    // initialize key - random choose a block
    x = (rand() % size) * 10;
    y = (rand() % ((max_y - min_y) / 10 + 1)) * 10 + min_y;
    *key = Point(x, y);

    // initialize door
    x = (rand() % size) * 10;
    y = (rand() % ((max_y - min_y) / 10 + 1)) * 10 + min_y;

    // Ensure door and key dont have same coordinates
    while ((key->get_x() == x) && (key->get_y() == y))
    {
        x = (rand() % size) * 10;
        y = (rand() % ((max_y - min_y) / 10 + 1)) * 10 + min_y;    
    }
    *door = Point(x, y); 

    // initialize blocks list
    x = 0;
    y = 50;
    for (int count = 0; count < size*size; count++)
    {
        // insert blocks - check for coins
        if (coins->check(x, y)) // create a function in objects to check if a coin exists at the provided coordinates
        {
            insert(x, y, 'C');
        }

        // insert blocks - check for bombs
        else if (bombs->check(x, y))
        {
            insert(x, y, 'B');
        }

        // insert blocks - check key and door
        else if ((x == key->get_x()) && (y = key->get_y()))
            insert(x, y, 'K');

        else if ((x == door->get_x()) && (y = door->get_y()))
            insert(x, y, 'D');

        else 
            insert(x, y, '-');

        // iteration - how x and y coordinates change with count
        if (count%(size-1) == 0)
        {
            y += 10;
            x = 0;
        }
        else
        {
            x += 10;
        }
    }
}

void Maze::set_head(Block *b) 
{
    head = b;
}

void Maze::set_coins(Objects *c) 
{
    coins = c;
}

void Maze::set_bombs(Objects *b) 
{
    bombs = b;
}

void Maze::set_key(int x, int y) 
{
    *key = Point(x, y);
}

void Maze::set_door(int x, int y) 
{
    *door = Point(x, y);
}

Block* Maze::get_head() const 
{
    return head;
}

Objects* Maze::get_coins() const 
{
    return coins;
}

Objects* Maze::get_bombs() const 
{
    return bombs;
}

Point* Maze::get_key() const 
{
    return key;
}

Point* Maze::get_door() const 
{
    return door;
}

void Maze::insert(int x, int y, char obj) 
{
    // new block initialize
    Block *block = new Block(x, y, obj);

    // if list is empty - first block
    if (head == NULL)
    {
        head = block;
        tail = block;
    }

    // if list is not empty
    else
    {
        Block *first = head; // for keeping first column of each row to get to next row's first column in O(1)
        
        int count = 0;
        for (Block *ptr = head; ptr != NULL; count++)
        {
            // if last block in row reached but row's end not reached - insert at right
            if ((ptr->get_right() == NULL) && (count < size-1))
            {
                block->set_left(ptr);
                block->set_up(ptr->get_up()->get_right());
                block->set_right(ptr->get_right());
                block->set_down(ptr->get_up()->get_right()->get_down());
                ptr->set_right(block);
                ptr->get_up()->get_right()->set_down(block);
            }

            // if last block in row reached and row has ended, insert at next row's first column
            else if ((ptr->get_right() == NULL) && (count == (size-1)))
            {
                count = 0; // start counting from first column
                block->set_up(first);
                block->set_down(first->get_down());
                first->set_down(block);
            }

            else
            {
                ptr = ptr->get_right();
            }
        }

        tail = block;
    }
}

void Maze::display() 
{
    Block *ptr = head;
    for (int count = 0; count < size*size; count++, ptr = ptr->get_right())
    {
        ptr->display_block();
    }
}
