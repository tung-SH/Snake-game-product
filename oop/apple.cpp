#include <stdio.h>
#include <stdlib.h>
#include "snake.cpp"
#include "maze.cpp"

class apple {
    cooordinate_2d pos; /* the position of the apple */
    maze stucked_maze; /* the stucked maze of the snake */

    public: 
    void set_maze(maze m) {
        stucked_maze = m; 
    }
    void set_random_pos() {
        pos.x = ((rand() % (stucked_maze.get_weight() - 3) )  + 1); 
        pos.y = ((rand() % (stucked_maze.get_height() - 3) )  + 1); 
    }
    void initial() {
        stucked_maze.content[pos.y][pos.x] = 48; 
    }
};

int main(void) {
    maze hampton;
    hampton.initial(); 
    hampton.construct(); 
    hampton.print(); 

}