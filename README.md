# The-Unseen-Journey-Quest
Find the key, unlock the exit, and escape the maze!

Objects: 
    1. Block - rep each block on the maze
        pointers 
        object - null if no object
        x and y coordinates

    2. Maze - consists of a grid made with the blocks
        size
            depends on level
            
        randomly generate x and y coordinates based on size and initialize following objects
            array of coins
            array of bomb
            door 
            key
            player

        list of Blocks
            once all objects set, create maze 

    3. Coin - object initialized with random x and y values as game starts (depending on size of maze)
        x and y coordinates randomly generated based on maze size
        score

    4. Bomb - object initialized with random x and y values as game starts (depending on size of maze)
        x and y coordinates randomly generated based on maze size
        score

    5. Door
    6. Key
    7. Player 

    8. Menu - displayed at the start of game and whenever a certain key is pressed
        when a certain option selected, game starts - maze created, displayed along with dashboard

    9. Dashboard 
        moves - calculated according to distance and level
        score
        key 
        sensing after every move
        undo
        mode