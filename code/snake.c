/***************************************
 * snake.c -- giá trị con rắn 
 * 
 * PURPOSE: 1. tạo ra giá trị con rắn có 
 *      thể di chuyển và rẽ trong mê cung
 *          2. tạo ra
 *              2.1 giá trị con rắn có 
 *                  hình dáng và hướng 
 *                  di chuyển cũng như 
 *                  không gian cụ thể mà 
 *                  nó ở trong 
 *              
 *              2.2 hàm di chuyển 
 * 
 * STATUS: 
 * 
 * SOURCE: 
 * 
*/
// #include "shape.c"

enum direction {right, left, top, down}; /* direction of snake and in game */

typedef enum direction direction; 

struct snake {
    direction current_direction; /* current direction of snake */
    shape body; /* shape of the snake */
    space* inside_space; /* the space which the snake inside */
}; 

typedef struct snake snake; 

/*********************************
 * snake_template -- tạo giá trị mẫu 
 *      cho giá trị con rắn 
 * 
*/
snake snake_template() {
    snake result; 

    return result; 
}

/**************************************
 * snake_to_string -- minh họa giá trị 
 *      con rắn 
 * 
*/
char* snake_to_string(void); 



/***************************************
 * snake_move -- con rắn di chuyển 
 * 
*/
void snake_move(snake* snake_ptrV); 



/**************************************
 * snake_turn -- con rắn rẽ 
 * 
*/
void snake_turn(snake* snake_ptrV); 



/*************************************
 * snake_grow -- con rắn phát triển 
 *      dài thêm 
 * 
*/
void snake_grow(snake* snake_ptrV); 

