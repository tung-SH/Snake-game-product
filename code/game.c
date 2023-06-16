/*******************************************
 * game.c -- giá trị game rắn săn mồi 
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
 *      - PROGRAM: 3
 *      - FUNCTION: 6
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
    space game_space; /* space for game */
    maze game_maze; /* maze of game */
    apple game_apple; /* apple of game */
    snake game_snake; /* snake of game */
    game_status status; /* status of game */
}; 

typedef struct game game; 

game game_level_1_init(void) {
    game result; 

    result.game_space = space_template(20); 
    result.game_maze = maze_level_1_template(&(result.game_space)); 
    result.game_apple = apple_template(&(result.game_maze)); 
    result.game_snake = snake_level_1_template(&(result.game_maze)); 

    return result; 
}; 

game_status game_run(game* game_ptrV) {
    game_status result; 

    const int GAME_SPEED = 150; /* SPEED OF GAME IN MILI-SECONDS */
    const char UP_ARROW = 'w'; 
    const char DOWN_ARROW = 's'; 
    const char LEFT_ARROW = 'a'; 
    const char RIGHT_ARROW = 'd'; 
    const char ESCAPE = 27; 
    
    clrscr(); 
    if (_kbhit()) {
    int ch = _getch(); 

        if (ch == UP_ARROW) {
            snake_turn_up(&((*game_ptrV).game_snake)); 
        } else if (ch == DOWN_ARROW) {
            snake_turn_down(&((*game_ptrV).game_snake)); 
        } else if (ch == RIGHT_ARROW) {
            snake_turn_right(&((*game_ptrV).game_snake)); 
        } else if (ch == LEFT_ARROW) {
            snake_turn_left(&((*game_ptrV).game_snake)); 
        } else if (ch == ESCAPE) {
            (*game_ptrV).status = OVER;  
        }
    }

    if (snake_is_going_crush_maze(&((*game_ptrV).game_snake))) {
        (*game_ptrV).status = OVER; 
    } 

    if (snake_is_goint_to_eat_itself(&((*game_ptrV).game_snake))) {
        (*game_ptrV).status = OVER; 
    }

    if (snake_is_goint_to_eat_apple(&((*game_ptrV).game_snake), &((*game_ptrV).game_apple))) {

        snake_grow(&((*game_ptrV).game_snake)); 
        apple_random_without_onto_snake(&((*game_ptrV).game_apple), &((*game_ptrV).game_snake));

    } else {
        snake_move(&((*game_ptrV).game_snake));

    }

    print_space(*((*game_ptrV).game_maze.space_game_ptr)); 
    wait_1ms(GAME_SPEED); 
    clrscr(); 


    result = (*game_ptrV).status; 
    return result; 
}

#ifdef DEBUG_P3

game snake_game; 

int main(void) {
    snake_game = game_level_1_init(); 

    while (1) {
        game_status status = game_run(&snake_game); 

        if (status == OVER) {
            break; 
        } 
    }
}

#endif