/*******************************************
 * apple.c -- giá trị táo của game 
 * 
 * PURPOSE: 
 *      - tổng quan: phục vụ xây dựng game rắn săn mồi 
 *      - cụ thể: tạo giá trị táo; hàm template, random_pos
 * 
 * STATUS: 
 *      - [x]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: 
 * 
**********************************************/
#include "maze.c"
#include "header/random.c"
#include "header/interactive.c"

struct apple {
    maze *maze_game_ptr; /* maze of game */ 
    point pos; /* position of apple */
}; 

typedef struct apple apple; 


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
        
        result.pos = point_template(centre_maze, centre_maze); 
    }
    
    draw_point(result.pos, '@', result.maze_game_ptr->space_game_ptr); 

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
    (*apple_ptrV).pos = point_template(random(2, range), random(2, range)); 

    draw_point((*apple_ptrV).pos, '@', (*apple_ptrV).maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F5
        print_space(*((*apple_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

}


#ifdef DEBUG_P5

space game_space; 
maze game_maze; 
apple game_apple; 

int main(void) {
    game_space = space_template(7); 
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

