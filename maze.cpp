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

    cout<<"Size of maze: "<<size<<endl;

    int x = 0, y = 50;

    srand(time(0));

    int x_gap = 8;
    int y_gap = 4;

    int min_y = 10;                       // The minimum value in the range
    int max_y = ((size-1) * y_gap) + 10;          // The maximum value in the range

    // initialize coins list - random x, y coordinates
    coins = new Objects;
    for (int count = 0; count < size; count++)
    {
        // randomly choose a block
        x = (rand() % size) * x_gap;
        y = (rand() % ((max_y - min_y) / y_gap + 1)) * y_gap + min_y;

        // cout<<"COINS:\n"<<"X: "<<x<<" Y: "<<y<<endl; // testing

        coins->insert(x, y, 'C');
    }

    // initialize bombs list - random x, y coordinates
    bombs = new Objects;
    for (int count = 0; count < size/5; count++)
    {
        // randomly choose a block
        x = (rand() % size) * x_gap;
        y = (rand() % ((max_y - min_y) / y_gap + 1)) * y_gap + min_y;

        // cout<<"X: "<<x<<"Y: "<<y<<endl; // testing

        bombs->insert(x, y, 'B');
    }

    // initialize key - random choose a block
    x = (rand() % size) * x_gap;
    y = (rand() % ((max_y - min_y) / y_gap + 1)) * y_gap + min_y;
    key = new Point(x, y);
    
    // cout<<"KEY: "<<"("<<x<<", "<<y<<")"<<endl; // testing

    // initialize door
    x = (rand() % size) * x_gap;
    y = (rand() % ((max_y - min_y) / y_gap + 1)) * y_gap + min_y;

    // Ensure door and key dont have same coordinates
    while ((key->get_x() == x) && (key->get_y() == y))
    {
        x = (rand() % size) * x_gap;
        y = (rand() % ((max_y - min_y) / y_gap + 1)) * y_gap + min_y;
    }

    door = new Point(x, y); 
    
    // cout<<"DOOR: "<<"("<<x<<", "<<y<<")"<<endl; // testing

    // initialize blocks list
    x = 0;
    y = 10;
    for (int count = 0; count < (size*size); count++)
    {
        cout<<"X: "<<x<<" Y: "<<y<<endl;

        //coins->display(0, 0);

        // player at first block
        if ((x == 0) && (y == 50))
        {
            insert(x, y, 'P');
        }

        // insert blocks - check for coins
        if (coins->check(x, y)) // create a function in objects to check if a coin exists at the provided coordinates
        {
            cout<<"Coin Check"<<endl;
            insert(x, y, 'C');
            cout<<"Insertion of coin completed"<<endl;
        }

        // insert blocks - check for bombs
        else if (bombs->check(x, y))
        {
            cout<<"Bomb Check"<<endl;
            insert(x, y, 'B');
            cout<<"Insertion of bomb completed"<<endl;
        }

        // insert blocks - check key and door
        else if ((x == key->get_x()) && (y == key->get_y()))
        {
            insert(x, y, 'K');
            cout<<"Insertion of key completed"<<endl;
        }

        else if ((x == door->get_x()) && (y == door->get_y()))
        {
            insert(x, y, 'D');
            cout<<"Insertion of door completed"<<endl;
        }

        else 
        {
            insert(x, y, '-');
            cout<<"Insertion completed"<<endl;
        }

        // iteration - how x and y coordinates change with count
        if (x == (size-1)*x_gap)
        {
            y += y_gap;
            x = 0;
        }
        else
        {
            x += x_gap;
        }
    }
}

Maze::~Maze()
{
    if (head != NULL)
    {
        Block *first = head->get_down(); // first block of next row

        for (Block* ptr = head; ptr != NULL; ptr = head)
        {
            if (head->get_right() != NULL)
                head = head->get_right();
            else
                head = first;
                first = head->get_down();

            delete ptr;
        }
    }

    delete coins;
    delete bombs;
    delete key;
    delete door;
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

    /*clear();
    block->display_block();
    refresh();
    getch();*/

    // if list is empty - first block
    if (head == NULL)
    {
        head = block;
        tail = block;
        return;
    }

    // if list is not empty
    else
    {
        Block *first = head; // for keeping first column of each row to get to next row's first column in O(1)
        
        int count = 0;
        for (Block *ptr = head; ptr != NULL; count++)
        {
            // if last block in row reached but row's end not reached - insert at right
            if ((ptr->get_right() == NULL) && (count < (size-1)))
            {
                // setup block pointers first
                block->set_left(ptr);

                if (ptr->get_up() != NULL)
                {
                    block->set_up(ptr->get_up()->get_right());
                    block->set_down(ptr->get_up()->get_right()->get_down());
                }

                block->set_right(ptr->get_right());

                // linking
                ptr->set_right(block);
                if (ptr->get_up() != NULL)
                    ptr->get_up()->get_right()->set_down(block);

                // once inserted, break
                break;
            }

            // if last block in row reached and row has ended, insert at next row's first column
            else if ((ptr->get_right() == NULL) && (count == (size-1)))
            {
                ptr = first->get_down();
                if (ptr == NULL)
                {
                    // insert at first column
                    block->set_up(first);
                    block->set_down(first->get_down());
                    first->set_down(block);

                    // once inserted, break
                    break;
                }
                else
                {
                    first = first->get_down();
                }
                count = 0;
            }

            // else, keep going
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
    Block *first = head;
    for (Block *ptr = head; ptr != NULL; )
    {
        ptr->display_block();
        if (ptr->get_right() == NULL)
        {
            ptr = first->get_down();
            first = first->get_down();
        }
        else
        {
            ptr = ptr->get_right();
        }
    }
    refresh();
}
