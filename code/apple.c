/*******************************************
 * apple.c -- giá trị táo cho game rắn 
 *      săn mồi 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: 
 * 
 * STATUS: 
 *      - [ ]: code chưa hoàn thiện 
 *      - [x]: code hoàn thành mục đích 
 *      - [ ]: code gặp lỗi tại dòng 
 *              Ghi chú lỗi      
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 
 *      - PROGRAM: 5
 *      - FUNCTION: 14, 13, 12, 11
 * 
**********************************************/
#include "maze.c"
#include "header/random.c"
#include "header/interactive.c"

const char REPRESENT_APPLE = '@'; 

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
        int central_maze = result.maze_game_ptr->space_game_ptr->size / 2 + 1; 
        point *apple_body = (point*)malloc(sizeof(point)); 
        apple_body[1 -1] = point_template(central_maze, central_maze); 

        result.body = shape_template(REPRESENT_APPLE, 1, apple_body); 
    }

    #ifdef DEBUG_F14
        printf("Apple template:\n");
        printf("Address of its maze: 0x%x.\n", result.maze_game_ptr);
        printf("Body:\n%s", shape_to_string(result.body));
    #endif

    draw_apple(result); 

    #ifdef DEBUG_F14
        printf("After draw apple template\n"); 
        print_space(*(result.maze_game_ptr->space_game_ptr));
    #endif

    return result; 
}

/************************************
 * apple_to_string -- chuyển đổi giá 
 *      trị táo thành xâu kí tự
 * 
 * example: 
 * 
*/
char* apple_to_string(apple appleV) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    sprintf(result, "----------\nApple:\nAddress of its maze: 0x%x\nBody: \n%s", appleV.maze_game_ptr, shape_to_string(appleV.body)); 

    #ifdef DEBUG_F14
        printf("Apple to string:\n%s", result); 

    #endif

    return result; 
}
/************************************
 * apple_get_postion -- lấy giá trị 
 *      vị trí hiện tại của quả táo  
 * 
 * example: 
 * 
*/
point apple_get_postion(apple* apple_ptrV) {
    point result; 

    result = (*apple_ptrV).body.points[1 -1]; 

    #ifdef DEBUG_F13
        printf("Apple:\n%sHas the position point %s\n", apple_to_string(*apple_ptrV), point_to_string(result)); 
    #endif

    return result; 
}

/************************************
 * apple_set_position -- chỉnh vị trí 
 *      giá trị táo 
 * 
 * example: 
 * 
*/
void apple_set_postion(apple* apple_ptrV, int xV, int yV) {
    #ifdef DEBUG_F12
        printf("Position of apple before setting: point %s\n", point_to_string(apple_get_postion(apple_ptrV)));
    #endif

    (*apple_ptrV).body.points[1 -1].x = xV; 
    (*apple_ptrV).body.points[1 -1].y = yV; 

    draw_apple((*apple_ptrV)); 

    #ifdef DEBUG_F12
        printf("Position of apple after setting: point %s\n", point_to_string(apple_get_postion(apple_ptrV)));
        printf("Maze after set position of apple:\n"); 
        print_space(*((*apple_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif
}


/****************************************
 * apple_random -- random vị trí của táo 
 * 
 * example: 
 * 
*/
void apple_random(apple *apple_ptrV) {
    #ifdef DEBUG_F11 
        printf("Maze before random position of apple %s:\n", point_to_string(apple_get_postion(apple_ptrV))); 
        print_space(*((*apple_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    int size_of_maze = (*apple_ptrV).maze_game_ptr->space_game_ptr->size; 
    apple_set_postion(apple_ptrV, random(2, size_of_maze - 1), random(2, size_of_maze - 1)); 

    #ifdef DEBUG_F11 
        printf("Maze after random position of apple %s:\n", point_to_string(apple_get_postion(apple_ptrV))); 
        print_space(*((*apple_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif
}


#ifdef DEBUG_P5

space game_space; 
maze game_maze; 
apple game_apple; 

int main(void) {
    game_space = space_template(11); 
    game_maze = maze_level_1_template(&game_space); 

    game_apple = apple_template(&game_maze); 

    apple_random(&game_apple); 
    apple_random(&game_apple); 

}

#endif

