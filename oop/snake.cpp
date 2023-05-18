#include <stdio.h>
#include "maze.cpp"
#include "interactive.cpp"

struct cooordinate_2d {
    int x, y; 
}; 

class snake {
    maze stucked_maze; /* the maze in which the snake being stucked */
    cooordinate_2d pos; /* the position of the snake in the maze */
    public:
    void set_maze(maze mazeP) {
        stucked_maze = mazeP; 
    }
    void set_pos(void) {
        pos.x = stucked_maze.get_weight() / 2; 
        pos.y = stucked_maze.get_height() / 2;
    }
    void inital(void);
    void move_right(void); 
    bool is_snake_crashed_maze() {
        bool result; 
        
        result = (pos.x >= stucked_maze.get_height() - 1) ? true : false; 

        return result; 
    }
}; 

// int main(void) {
//     // initial 
//     maze hampton(30, 20);
//     hampton.initial(); 
//     hampton.construct(); 
    
//     snake krait;
//     krait.set_maze(hampton); 
//     krait.set_pos(); 
//     krait.inital(); 

//     hampton.print(); 
//     wait_1ms(5000);
//     clrscr(); 
//     do {
//         krait.move_right();
//         hampton.print(); 
//         wait_1ms(200); 
//         clrscr(); 
//     } while (!krait.is_snake_crashed_maze());

// }

// program to initial the snake in the maze
void snake::inital(void) {
    stucked_maze.content[pos.y][pos.x] = 35; 
}

// program to move the snake to the right
void snake::move_right() {
    stucked_maze.content[pos.y][pos.x] = 32; 
    pos.x += 1; 
    
    stucked_maze.content[pos.y][pos.x] = 35; 
}