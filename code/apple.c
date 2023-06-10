/*******************************************
 * apple.c -- giá trị táo của game 
 * 
 * PURPOSE: 
 *      - tổng quan: phục vụ xây dựng game rắn săn mồi 
 *      - cụ thể: tạo giá trị táo; hàm template, random_pos
 * 
 * STATUS: 
 *      - [ ]: code chưa hoàn thiện 
 *      - [X]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 5
 * 
**********************************************/
#include "maze.c"
#include "header/random.c"
#include "header/interactive.c"

struct apple {
    maze *maze_game_ptr; /* maze of game */ 
    shape body; /* position of apple */
}; 

typedef struct apple apple; 


/************************************
 * draw_apple -- vẽ giá trị apple 
 *      vào không gian của nó 
 * 
 * example: 
 * 
*/
void draw_apple(apple appleV) {
    draw_shape(appleV.body, appleV.maze_game_ptr->space_game_ptr); 
}


/**************************************
 * apple_template -- tạo giá trị mẫu 
 *      vào giá trị táo 
 * 
 * example: 
 * 
*/
apple apple_template(maze *maze_ptrV) {
    apple result; 

    result.maze_game_ptr = maze_ptrV; 

    {
        int centre_maze = (((*maze_ptrV).space_game_ptr->size % 2) 
                        + (*maze_ptrV).space_game_ptr->size) / 2; 
        
        point* apple_shape = (point*)malloc(sizeof(point)); 

        apple_shape[1 -1] = point_template(centre_maze, centre_maze); 

        result.body = shape_template('@', 1, apple_shape); 

    }
    
    draw_apple(result);  

    #ifdef DEBUG_F5
        print_space(*(maze_ptrV->space_game_ptr)); 
    #endif 

    return result; 
}

/****************************************
 * apple_random -- random vị trí của táo 
 * 
 * example: 
 * 
*/
void apple_random(apple *apple_ptrV) {
    int range = (*apple_ptrV).maze_game_ptr->space_game_ptr->size - 1; 
    (*apple_ptrV).body.points[1 -1] = point_template(random(2, range), random(2, range)); 

    draw_apple(*apple_ptrV); 

    #ifdef DEBUG_F5
        print_space(*((*apple_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

}


#ifdef DEBUG_P5

space game_space; 
maze game_maze; 
apple game_apple; 

int main(void) {
    game_space = space_template(30); 
    game_maze = maze_level_1_template(&game_space); 
    game_apple = apple_template(&game_maze); 

    wait_1ms(6000); 
    clrscr(); 
    for (int i = 1; i <= 5; ++i) {
        apple_random(&game_apple); 

        wait_1ms(6000); 
        clrscr(); 
    }


}

#endif

