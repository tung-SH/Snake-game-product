/*******************************************
 * snake.c -- giá trị con rắn cho 
 *      game rắn săn mồi 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: 
 *          1. định nghĩa con rắn && hướng di chuyển 
 *          1.1 hàm snake_template 
 *          2. hàm di chuyển cho rắn 
 *          3. hàm điều khiển hướng di chuyển con rắn 
 *              cho người chơi  
 *          4. hàm check có chạm mê cung hoặc đụng mê
 *              cung ko 
 *          5. hàm check có chạm táo hay ko
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
#include "apple.c"
#include <math.h>
#include <conio.h>

#define SQR(x) ((x) * (x)) 

enum direction {UP, DOWN, LEFT, RIGHT}; 
typedef enum direction direction; 

struct snake {
    maze *maze_game_ptr; /* the maze it inside */
    shape body; /* body of snake */
    shape head; /* head of snake */
    direction movement_direction; /* direction of movement */
}; 


typedef struct snake snake; 

/************************************
 * snake_level_1_template -- tạo 
 *      ra giá trị rắn mẫu cho level 1
 * 
 * example: 
 * 
*/
snake snake_level_1_template(maze *maze_ptrV) {
    snake result; 

    result.maze_game_ptr = maze_ptrV; 
    result.movement_direction = RIGHT; 

    int max_length_snake = SQR(result.maze_game_ptr->space_game_ptr->size - 1); 
    {
        point* snake_shape = (point*)malloc(max_length_snake * sizeof(point)); 
        snake_shape[1 -1] = point_template(2, result.maze_game_ptr->space_game_ptr->size / 2); 
        
        result.body = shape_template('-', 1, snake_shape); 
    }

    {
        point* snake_head = (point*)malloc(sizeof(point)); 
        snake_head[1 -1] = point_template(2, result.maze_game_ptr->space_game_ptr->size / 2 + 1); 
        
        result.head = shape_template('+', 1, snake_head); 
    }


    draw_shape(result.body, result.maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F4
        printf("After draw body.\n"); 
        print_space(*(result.maze_game_ptr->space_game_ptr)); 
    #endif


    draw_shape(result.head, result.maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F4
        printf("After draw head.\n"); 
        print_space(*(result.maze_game_ptr->space_game_ptr)); 
    #endif

    return result; 
}

/****************************************
 * snake_move -- giá trị rắn di chuyển  
 * 
 * example: 
 * 
*/
void snake_move(snake* snake_ptrV) {
    point old_tail = (*snake_ptrV).body.points[(*snake_ptrV).body.num_point -1]; 
    for (int i = 2; i <= (*snake_ptrV).body.num_point; ++i) {
        (*snake_ptrV).body.points[i -1] = (*snake_ptrV).body.points[i - 1 -1]; 
    }
    (*snake_ptrV).body.points[1 -1] = (*snake_ptrV).head.points[1 -1]; 

    switch ((*snake_ptrV).movement_direction) {
        case RIGHT:
            ++((*snake_ptrV).head.points[1 -1].y); 
            break;

        case LEFT:  
            --((*snake_ptrV).head.points[1 -1].y); 
            break;

        case UP: 
            --((*snake_ptrV).head.points[1 -1].x); 
            break;

        case DOWN:
            ++((*snake_ptrV).head.points[1 -1].x); 
            break;

    }

    draw_point(old_tail, ' ', (*snake_ptrV).maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F4
        printf("After fix old tail position.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    draw_shape((*snake_ptrV).body, (*snake_ptrV).maze_game_ptr->space_game_ptr); 
    
    #ifdef DEBUG_F4
        printf("After draw new shape.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    draw_shape((*snake_ptrV).head, (*snake_ptrV).maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F4
        printf("After draw new head.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

}

/************************************
 * snake_turn_left -- giá trị rắn 
 *      đổi chiều đi thành trái  
 * 
 * example: 
 * 
*/
void snake_turn_left(snake* snake_ptrV) {
    (*snake_ptrV).movement_direction = LEFT; 
}

/************************************
 * snake_turn_right -- giá trị rắn 
 *      đổi chiều đi thành phải
 * 
 * example: 
 * 
*/
void snake_turn_right(snake* snake_ptrV) {
    (*snake_ptrV).movement_direction = RIGHT; 
}

/************************************
 * snake_turn_up -- giá trị rắn 
 *      đổi chiều đi thành trên
 * 
 * example: 
 * 
*/
void snake_turn_up(snake* snake_ptrV) {
    (*snake_ptrV).movement_direction = UP; 
}

/************************************
 * snake_turn_down -- giá trị rắn 
 *      đổi chiều đi thành xuống 
 * 
 * example: 
 * 
*/
void snake_turn_down(snake* snake_ptrV) {
    (*snake_ptrV).movement_direction = DOWN; 
}

/****************************************
 * snake_move -- giá trị rắn di chuyển  
 * 
 * example: 
 * 
*/
void snake_grow(snake* snake_ptrV) {
    ++((*snake_ptrV).body.num_point); 
    for (int i = 2; i <= (*snake_ptrV).body.num_point; ++i) {
        (*snake_ptrV).body.points[i -1] = (*snake_ptrV).body.points[i - 1 -1]; 
    }
    (*snake_ptrV).body.points[1 -1] = (*snake_ptrV).head.points[1 -1]; 




    switch ((*snake_ptrV).movement_direction) {
        case RIGHT:
            ++((*snake_ptrV).head.points[1 -1].y); 
            break;

        case LEFT:  
            --((*snake_ptrV).head.points[1 -1].y); 
            break;

        case UP: 
            --((*snake_ptrV).head.points[1 -1].x); 
            break;

        case DOWN:
            ++((*snake_ptrV).head.points[1 -1].x); 
            break;

    }

     

    #ifdef DEBUG_F4
        printf("After fix old tail position.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    draw_shape((*snake_ptrV).body, (*snake_ptrV).maze_game_ptr->space_game_ptr); 
    
    #ifdef DEBUG_F4
        printf("After draw new shape.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    draw_shape((*snake_ptrV).head, (*snake_ptrV).maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F4
        printf("After draw new head.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

}


#ifdef DEBUG_P4

space game_space; 
maze game_maze; 
snake game_snake; 

int main(void) {
    clrscr();

    game_space = space_template(30); 
    game_maze = maze_level_1_template(&game_space); 
    game_snake = snake_level_1_template(&game_maze); 
    print_space(game_space); 
    wait_1ms(650); 

    int i = 1; 
    while(1)
    {
        /********************
         * control direction 
        */
        if (_kbhit()) {
            char ch = _getch(); 

            if (ch == 'w') {
                snake_turn_up(&game_snake); 
            } else if (ch == 's') {
                snake_turn_down(&game_snake); 
            } else if (ch == 'a') {
                snake_turn_left(&game_snake); 
            } else if (ch == 'd') {
                snake_turn_right(&game_snake); 
            }else if (ch == 27) {
                break; 
            }
        }


        clrscr();
        if (i == 4 || i == 10 || i == 14) {
            snake_grow(&game_snake); 
        } else {
            snake_move(&game_snake); 
        }

        print_space(game_space);
        wait_1ms(250); 
        ++i;
    }

    
}

#endif


