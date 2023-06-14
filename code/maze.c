/*******************************************
 * maze.c -- giá trị mê cung cho game 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: 
 * 
 * STATUS: 
 *      - [x]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 
 *      - PROGRAM: 6
 *      - FUNCTION: 15
 * 
**********************************************/
#include "shape.c"

const char REPRESENT_WALL = '='; 

struct maze {
    shape wall; /* wall of maze */
    space *space_game_ptr; /* space of game */
}; 

typedef struct maze maze; 

/************************************
 * draw_maze -- vẽ giá trị maze vào 
 *      giá trị không gian 
 * 
 * example: 
 * 
*/
void draw_maze(maze mazeV) {
    draw_shape(mazeV.wall, mazeV.space_game_ptr); 
}


/**********************************
 * maze_level_1_template -- giá trị mê cung 
 *      mẫu cho level 1
 * 
*/
maze maze_level_1_template(space *space_ptrV) {
    maze result; 

    result.space_game_ptr = space_ptrV; 
    int size_maze = result.space_game_ptr->size; 

    {   
        int num_point = (size_maze - 1) * 4; 
        int nth = 1; /* điểm thứ nth của tường */
        point *wall_shape = (point*)malloc(num_point * sizeof(point)); 

        /* tạo tường trên cho mê cung */
        for (int i = 1; i <= size_maze; ++i) {
            wall_shape[nth -1] = point_template(1, i); 
            ++nth; 
        }

        /* tạo tường dưới cho mê cung */
        for (int i = 1; i <= size_maze; ++i) {
            wall_shape[nth -1] = point_template(size_maze, i); 
            ++nth; 
        }

        /* tạo tường trái cho mê cung */
        for (int i = 2; i <= size_maze - 1; ++i) {
            wall_shape[nth -1] = point_template(i, 1); 
            ++nth; 
        }

        /* tạo tường phải cho mê cung */
        for (int i = 2; i <= size_maze - 1; ++i) {
            wall_shape[nth -1] = point_template(i, size_maze); 
            ++nth; 
        }

        result.wall = shape_template(REPRESENT_WALL, num_point, wall_shape); 

        #ifdef DEBUG_F15
            printf("Wall template is\n");
            printf("Address of its space: 0x%x\n", result.space_game_ptr); 
            printf("Wall shape:\n%s", shape_to_string(result.wall));
        #endif
    }
    
    draw_maze(result); 

    #ifdef DEBUG_F15
        printf("After draw maze template\n");
        print_space(*(result.space_game_ptr)); 
    #endif

    return result; 
}

/************************************
 * maze_to_string -- chuyển đổi giá trị 
 *      mê cung thành xâu kí tự 
 * 
 * example: 
 * 
*/
char* maze_to_string(maze mazeV) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    sprintf(result, "-----------------------\nMaze:\nAddress of its space: 0x%x\nWall:\n%s", mazeV.space_game_ptr, shape_to_string(mazeV.wall)); 

    #ifdef DEBUG_F15
        printf("Maze to string:\n%s", result); 
    #endif

    return result; 
}

#ifdef DEBUG_P6

space game_space; 
maze game_maze; 

int main(void) {
    game_space = space_template(5); 
    game_maze = maze_level_1_template(&game_space); 

    maze_to_string(game_maze); 

}

#endif