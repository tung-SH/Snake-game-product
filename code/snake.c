/*******************************************
 * snake.c -- giá trị rắn trong game 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: 
 * 
 * STATUS: 
 *      - [ ]: code chưa hoàn thiện 
 *      - [ ]: code hoàn thành mục đích 
 *      - [x]: code gặp lỗi tại dòng 465, 448
 *              Ghi chú lỗi: code chạy ko như mong muốn 
 *                  - rắn ngay khi ăn táo thì ko grow 
 *                      mà lại để lại một mẩu đuôi và 
 *                      giữ nguyên độ dài đuôi       
 * 
 * SOURCE: 
 * 
 * DEBUG_NUMBER: 
 *      - PROGRAM: 4
 *      - FUNCTION: 10, 9, 8, 7
 * 
**********************************************/
#include "apple.c"
#include <math.h>
#include <conio.h>

const char REPRESENT_SNAKE_HEAD = '+'; 
const char REPRESENT_SNAKE_BODY = '-'; 

#define SQR(x) ((x) * (x)) 

struct snake {
    maze *maze_game_ptr; /* the maze it inside */
    shape body; /* body of snake */
    shape head; /* head of snake */
    direction movement_direction; /* direction of movement */
}; 


typedef struct snake snake; 

/************************************
 * draw_snake -- vẽ giá trị con rắn 
 *      vào không gian của nó 
 * 
 * example: 
 * 
*/
void draw_snake(snake snakeV) {
    draw_shape(snakeV.body, snakeV.maze_game_ptr->space_game_ptr);
    draw_shape(snakeV.head, snakeV.maze_game_ptr->space_game_ptr);
}


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
        
        result.body = shape_template(REPRESENT_SNAKE_BODY, 1, snake_shape); 
    }

    #ifdef DEBUG_F10
        printf("Body of snake template:\n%s", shape_to_string(result.body)); 
    #endif

    {
        point* snake_head = (point*)malloc(sizeof(point)); 
        snake_head[1 -1] = point_template(2, result.maze_game_ptr->space_game_ptr->size / 2 + 1); 
        
        result.head = shape_template(REPRESENT_SNAKE_HEAD, 1, snake_head); 
    }

    #ifdef DEBUG_F10
        printf("Head of snake template:\n%s", shape_to_string(result.head)); 
    #endif

    draw_snake(result); 

    #ifdef DEBUG_F10
        printf("Maze after draw snake template:\n"); 
        print_space(*(result.maze_game_ptr->space_game_ptr)); 
    #endif

    return result; 
}

/************************************
 * snake_to_string -- chuyển đổi giá 
 *      rắn thành xâu kí tự 
 * 
 * example: 
 * 
*/
char* snake_to_string(snake snakeV) {
    char* result; 

    result = (char*)malloc(MAX_LENGTH); 
    sprintf(result, "------------------------\nSnake:\nAddress of its maze: 0x%x\nSnake head:\n%sSnake body:\n%sDirection: %s.\n------------------------\n", 
                                                        snakeV.maze_game_ptr, shape_to_string(snakeV.head), shape_to_string(snakeV.body), direction_to_string(snakeV.movement_direction)); 

    #ifdef DEBUG_F10
        printf("Snake to string:\n%s", result); 
    #endif

    return result; 
}

/************************************
 * snake_get_tail_position -- lấy giá 
 *      trị điểm đuôi của rắn 
 * 
 * example: 
 * 
*/
point snake_get_tail_position(snake* snake_ptrV) {
    point result; 

    result = (*snake_ptrV).body.points[(*snake_ptrV).body.num_point - 1]; 

    #ifdef DEBUG_F9
        printf("Tail position of\n%s IS point %s.\n", snake_to_string(*snake_ptrV), point_to_string(result)); 
    #endif

    return result; 
}


/************************************
 * snake_get_head_position -- lấy giá 
 *      trị điểm đầu của rắn 
 * 
 * example: 
 * 
*/
point snake_get_head_position(snake* snake_ptrV) {
    point result; 

    result = (*snake_ptrV).head.points[1 -1]; 

    #ifdef DEBUG_F9
        printf("Head position of\n%s IS point %s.\n", snake_to_string(*snake_ptrV), point_to_string(result)); 
    #endif

    return result; 
}

/************************************
 * snake_get_head_position -- lấy giá 
 *      trị điểm đầu của rắn 
 * 
 * example: 
 * 
*/
point snake_get_upcomming_position(snake* snake_ptrV) {
    point result; 

    result = point_move((*snake_ptrV).movement_direction, snake_get_head_position(snake_ptrV)); 

    #ifdef DEBUG_F8
        printf("upcomming position of\n%s IS point %s.\n", snake_to_string(*snake_ptrV), point_to_string(result)); 
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
    #ifdef DEBUG_F8
        printf("Snake before move ahead:\n%sMaze before snake move ahead:\n", snake_to_string(*snake_ptrV));
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    point old_pos_tail = snake_get_tail_position(snake_ptrV); 

    /* các phần của thân rắn trườn về phía trước ngoại trừ phần đầu tiên */
    for (int i = (*snake_ptrV).body.num_point; i >= 2; --i) {
        (*snake_ptrV).body.points[i -1] = (*snake_ptrV).body.points[i - 1 -1]; 
    }

    #ifdef DEBUG_F8
        printf("Snake after body except the first part move ahead\n%s", snake_to_string(*snake_ptrV)); 
    #endif

    /* phần đầu tiên của thân rắn trườn về vị trí cũ của đầu rắn */
    (*snake_ptrV).body.points[(*snake_ptrV).body.num_point -1] = (*snake_ptrV).head.points[1 -1]; 
    
    #ifdef DEBUG_F8
        printf("Snake after whole body move ahead\n%s", snake_to_string(*snake_ptrV)); 
    #endif

    /* di chuyển vị trí đầu rắn */
    switch ((*snake_ptrV).movement_direction) {
        case RIGHT: 
            ++((*snake_ptrV).head.points[1 -1].y); 
            break;

        case LEFT: 
            --((*snake_ptrV).head.points[1 -1].y); 
            break;

        case DOWN: 
            ++((*snake_ptrV).head.points[1 -1].x); 
            break;

        case UP: 
            --((*snake_ptrV).head.points[1 -1].x); 
            break;
    }

    #ifdef DEBUG_F8
        printf("Snake after move ahead\n%s", snake_to_string(*snake_ptrV)); 
    #endif

    /* vẽ sửa lại vị trí cũ của đuôi rắn trong mê cung */
    draw_point(old_pos_tail, REPRESENT_SPACE, (*snake_ptrV).maze_game_ptr->space_game_ptr); 

    #ifdef DEBUG_F8
        printf("Maze after fix old tail:\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    /* vẽ lại con rắn mới */
    draw_snake((*snake_ptrV)); 

    #ifdef DEBUG_F8
        printf("Maze after draw new snake:\n"); 
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
 * snake_grow -- giá trị rắn phát triển   
 * 
 * example: 
 * 
*/
void snake_grow(snake* snake_ptrV) {
    #ifdef DEBUG_F7
        printf("Snake before grow:\n%sMaze before snake grow:\n", snake_to_string(*snake_ptrV)); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    point new_tail_pos = snake_get_tail_position(snake_ptrV); 

    snake_move(snake_ptrV); 

    #ifdef DEBUG_F7
        printf("Snake after move ahead:\n%sMaze after snake move ahead:\n", snake_to_string(*snake_ptrV)); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

    /* thêm duôi mới cho rắn */
    ++((*snake_ptrV).body.num_point); 
    (*snake_ptrV).body.points[(*snake_ptrV).body.num_point -1] = new_tail_pos; 

    draw_snake(*snake_ptrV); 

    #ifdef DEBUG_F7
        printf("Snake after add new tail:\n%sMaze after snake add new tail:\n", snake_to_string(*snake_ptrV)); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif
}

/************************************
 * snake_is_going_crush_maze -- kiểm 
 *      tra giá tri rắn có chuẩn bị 
 *      đụng tường ko
 * 
 * example: 
 * 
*/
int snake_is_going_crush_maze(snake* snake_ptrV) {
    int result; 

    result = is_point_belong_to_shape(snake_get_upcomming_position(snake_ptrV), (*snake_ptrV).maze_game_ptr->wall); 
    
    #ifdef DEBUG_F7
        if (result) {
            printf("Snake is going to crush maze.\nCurrent maze:\n");
            print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
        } else {
            printf("Snake is not going to crush maze.\nCurrent maze:\n");
            print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr));  
        }
    #endif

    return result; 
}

/************************************
 * snake_is_going_to_eat_apple -- kiểm 
 *      tra giá trị rắn có chuẩn bị ăn 
 *          táo hay ko  
 * 
 * example: 
 * 
*/
int snake_is_goint_to_eat_apple(snake* snake_ptrV, apple* apple_ptrV) {
    int result; 

    result = is_pointA_equal_pointB(snake_get_upcomming_position(snake_ptrV), apple_get_postion(apple_ptrV)); 

    #ifdef DEBUG_F7
        if (result) {
            printf("Snake is going to eat apple.\nCurrent Maze:\n"); 
            print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
        } else {
            printf("Snake is not going to eat apple.\nCurrent Maze:\n"); 
            print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
        }

    #endif 

    return result; 
}

/********************************************
 * apple_random_without_onto_snake -- random 
 *      vị trí của táo mà ko random nhầm vị trí
 *      của rắn 
 * 
 * example: 
 * 
*/
void apple_random_without_onto_snake(apple* apple_ptrV, snake* snake_ptrV) {
    do {
        apple_random(apple_ptrV); 

    } while (
        is_pointA_equal_pointB(apple_get_postion(apple_ptrV), snake_get_head_position(snake_ptrV)) 
    ||  is_point_belong_to_shape(apple_get_postion(apple_ptrV), (*snake_ptrV).body)  
    ); /* UNTIL APPLE POSITION DOES NOT ALIKE SNAKE HEAD OR BODY */

    #ifdef DEBUG_F7
        printf("Maze after random apple successfully.\n"); 
        print_space(*((*snake_ptrV).maze_game_ptr->space_game_ptr)); 
    #endif

}


#ifdef DEBUG_P4

const int GAME_SPEED = 150; /* SPEED OF SNAKE IN MILISECONDS */
const char UP_ARROW = 'w'; 
const char DOWN_ARROW = 's'; 
const char LEFT_ARROW = 'a'; 
const char RIGHT_ARROW = 'd'; 
const char ESCAPE = 27; 

FILE* debug_file; 

space game_space; 
maze game_maze; 
snake game_snake; 
apple game_apple; 

int main(void) {
    game_space = space_template(20); 
    game_maze = maze_level_1_template(&game_space); 
    game_apple = apple_template(&game_maze); 
    game_snake = snake_level_1_template(&game_maze); 

    while (1) {
        if (_kbhit()) { /* IF ANY KEY IS PRESSED */
            int ch = _getch(); 

            /* CONTROL SNAKE */
            if (ch == UP_ARROW) {
                snake_turn_up(&game_snake); 
            } else if (ch == DOWN_ARROW) {
                snake_turn_down(&game_snake); 
            } else if (ch == RIGHT_ARROW) {
                snake_turn_right(&game_snake); 
            } else if (ch == LEFT_ARROW) {
                snake_turn_left(&game_snake); 
            } else if (ch == ESCAPE) {
                break;  
            }
        }

        if (snake_is_going_crush_maze(&game_snake)) {
            break; /* GAME OVER */
        } 

        if (snake_is_goint_to_eat_apple(&game_snake, &game_apple)) {
            snake_grow(&game_snake); 
            apple_random_without_onto_snake(&game_apple, &game_snake);
        } else {
            snake_move(&game_snake);     
        }

        print_space(game_space); 
        wait_1ms(GAME_SPEED); 
        clrscr(); 
    }



    
}

#endif


