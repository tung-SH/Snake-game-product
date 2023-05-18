#include <stdio.h>
#include <stdlib.h>

struct size {
    int w, h; 
}; 


class maze {
    size maze_s; /* the size of the maze */
    

    public: 
    char** content; /* the content of the maze */
    maze(int w = 30, int h = 20) {
        maze_s.w = w; 
        maze_s.h = h; 
    }

    void initial(void);
    void construct(void); 
    void print(void); 
    int get_height() {
        return maze_s.h;
    }
    int get_weight() {
        return maze_s.w; 
    }
};



// int main(void) {
//     maze hampton(40, 30);
//     hampton.initial(); 
//     hampton.construct(); 
//     hampton.print(); 
    

// }


// program to set up the 2d content array and assign space into every elements of its content 
void maze::initial(void) {
        content = (char**)malloc(maze_s.h * sizeof(char*));
        for (int i = 0; i <= maze_s.h - 1; i++) {
            content[i] = (char*)malloc(maze_s.w * sizeof(char)); 
        }

        for (int i = 0; i <= maze_s.h - 1; i++) {
            for (int j = 0; j <= maze_s.w - 1; j++) {
                content[i][j] = 32; 
            }
        }
}

// program to set up the wall of the maze 
void maze::construct(void) {
    for (int i = 0; i <= maze_s.w - 1; i++) {
        int a = 0; 
        int b = maze_s.h - 1; 
        
        content[a][i] = 42; 
        content[b][i] = 42; 
    }

    for (int i = 0; i <= maze_s.h - 1; i++) {
        int a = 0; 
        int b = maze_s.w - 1; 

        content[i][a] = 42; 
        content[i][b] = 42; 
    }
    
}

// program to print the maze on the command line
void maze::print(void) {
    for (int i = 0; i <= maze_s.h - 1; i++) {
        for (int j = 0; j <= maze_s.w - 1; j++) {
            printf("%c", content[i][j]);
        }
        printf("\n"); 
    }
}

