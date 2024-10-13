# The-Unseen-Journey-Quest
Find the key, unlock the exit, and escape the maze!

Objects: 
    1. Point
        contains x and y coordinates only

    1. Block - rep each block on the maze
        pointers 
        object - null if no object
        inherits points

    2. Maze - consists of grid made with the blocks
        size
            depends on level
            
        randomly generate x and y coordinates based on size and initialize array of points for each:
            array of coins
            array of bomb
            door 
            key

        list of Blocks
            once all objects set, create maze 

    7. Player 
        inherits point

    8. Menu - displayed at the start of game and whenever a certain key is pressed
        when a certain option selected, game starts - maze created, displayed along with dashboard

    9. Dashboard 
        moves - calculated according to distance and level
        score
        key 
        sensing after every move
        undo
        mode