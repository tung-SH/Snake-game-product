/********************************************
 * maze.c -- không gian mê cung cho game 
 * 
 * PURPOSE: 
 * 
 * STATUS: code lỗi khi chạy ở dòng 94 --> 
 *      lỗi chỉ tới dòng  70 của file point.c 
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 6
 * 
*/
#include "shape.c"

struct maze {
    shape wall; /* wall of maze */
    space *space_game_ptr; /* space of game */
}; 

typedef struct maze maze; 


/**********************************
 * maze_level_1_template -- giá trị mê cung 
 *      mẫu cho level 1
 * 
*/
maze maze_level_1_template(space *space_ptrV) {
    maze result; 

    result.space_game_ptr = space_ptrV; 
    
    {   
        int num_wall_point = (result.space_game_ptr->size - 1) * 4;
        point wall_points[num_wall_point]; /* middle list to add to wall of maze */

        int nth = 1; /* the nth points of wall */

        /********************************
         * tạo tường trên của mê cung
        */
        for (int j = 1; j <= result.space_game_ptr->size; ++j) {
            wall_points[nth -1] = point_template(1, j); 
            ++nth;
        }
        --nth; /* reset nth */

        /*******************************
         * tạo tường dưới cho mê cung
        */
        for (int j = 1; j <= result.space_game_ptr->size; ++j) {
            wall_points[nth -1] = point_template(result.space_game_ptr->size, j); 
            ++nth; 
        }
        --nth; /* reset nth */

        /*******************************
         * tạo tường trái cho mê cung
        */
        for (int i = 2; i <= result.space_game_ptr->size - 1; ++i) {
            wall_points[nth -1] = point_template(i, 1); 
        }
        --nth; /* reset nth */

        /*******************************
         * tạo tường phải cho mê cung
        */
        for (int i = 2; i <= result.space_game_ptr->size - 1; ++i) {
            wall_points[nth -1] = point_template(i, result.space_game_ptr->size); 
        }

        result.wall = shape_template('=', num_wall_point, wall_points); 

    }

    

    draw_shape(result.wall, space_ptrV); 

    #ifdef DEBUG_P6
        print_space(*space_ptrV); 
    #endif


    return result; 
}


#ifdef DEBUG_P6

space game_space; 
maze game_maze; 

int main(void) {
    game_space = space_template(7); 
    game_maze = maze_level_1_template(&game_space); 


}

#endif