/*******************************************
 * game.c -- giá trị game rắn săn mồi 
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
    maze* game_maze_ptr; /* maze of game */
    apple* game_apple_ptr; /* apple of game */
    snake game_snake; /* snake of game */
    game_status status; /* status of game */
}; 

typedef struct game game; 

game game_level_1_init(void) {
    game_space = space_template(20); 
    game_maze = maze_level_1_template(&game_space); 
    game_apple = apple_template(&game_maze); 
    game_snake = snake_level_1_template(&game_maze); 
}

game_status game_run(game* game_ptrV) {
    game_status result; 

        if (_kbhit()) {
        int ch = _getch(); 

        if (ch == UP_ARROW) {
            snake_turn_up((*game_ptrV).game_snake); 
        } else if (ch == DOWN_ARROW) {
            snake_turn_down(&game_snake); 
        } else if (ch == RIGHT_ARROW) {
            snake_turn_right(&game_snake); 
        } else if (ch == LEFT_ARROW) {
            snake_turn_left(&game_snake); 
        } else if (ch == ESCAPE) {
            ;  
        }
    }

    if (snake_is_going_crush_maze(&game_snake)) {
        break; 
    } 

    if (snake_is_goint_to_eat_apple(&game_snake, &game_apple)) {
        snake_grow(&game_snake); 

        #ifdef DEBUG
            debug_file = fopen("debug.txt", "w"); 
            fprintf(debug_file, "Snake after grow:\n%s", snake_to_string(game_snake)); 
            fclose(debug_file); 
        #endif

        apple_random_without_onto_snake(&game_apple, &game_snake);
        
        #ifdef DEBUG
            debug_file = fopen("debug.txt", "w"); 
            fprintf(debug_file, "Snake random apple:\n%s", snake_to_string(game_snake)); 
            fclose(debug_file); 
        #endif

    } else {
        snake_move(&game_snake);     

        #ifdef DEBUG
            debug_file = fopen("debug.txt", "w"); 
            fprintf(debug_file, "Snake after move:\n%s", snake_to_string(game_snake)); 
            fclose(debug_file); 
        #endif
    }

    print_space(game_space); 
    wait_1ms(GAME_SPEED); 
    clrscr(); 

    return result; 
}

#ifdef DEBUG_P3

game snake_game; 

int main(void) {
    snake_game = game_level_1_init(); 

    while (1) {
        game_status status = (&snake_game); 

        if (status == OVER) {
            break; 
        } 
    }
}

#endif