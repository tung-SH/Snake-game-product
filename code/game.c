/*******************************************
 * 
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
 *      - PROGRAM: 
 *      - FUNCTION: 
 * 
**********************************************/

#include "snake.c"


enum game_status {OVER, RUNNING};

typedef enum game_status game_status; 

char* game_status_to_string(game_status game_statusV) {
    char* result; 

    switch (game_statusV) {
        case OVER: 
            strcpy(result, "game over"); 
            break;

        case RUNNING: 
            strcpy(result, "game is running"); 
            break;
    }

    return result; 
}

struct game {
    maze game_maze; /* maze of game */
    apple game_apple; /* apple of game */
    snake game_snake; /* snake of game */
    game_status status; /* status of game */
}; 

typedef struct game game; 

game game_init(void) {
    
}

game_status game_run(game* game_ptrV) {
    game_status result; 

    

    return result; 
}