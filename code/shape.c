/*******************************************
 * shape.c -- giá trị hình dạng 
 * 
 * PURPOSE: 
 *      - tổng quan: phục vụ tạo hình cho 
 *          mê cung, quả táo, con rắn cho 
 *          game 
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
 *      - PROGRAM: 7
 *      - FUNCTION: 17, 16
 * 
**********************************************/


#include "point.c"

const int MAX_POINT = 1000; /* MAX POINT IN SHAPE */

struct shape {
    char represent_point; /* character to represent by 1 point of shape */
    int num_point; /* number of points */
    point* points; /* the position of all points in shape */
};

typedef struct shape shape; 

/***************************************************
 * shape_template -- tạo ra 1 giá trị mẫu để bỏ vào 
 *      biến hình dạng 
 * 
 * 
*/
shape shape_template(char represent_pointV, int num_pointV, point* pointsV) {
    shape result; 

    result.represent_point = represent_pointV; 
    result.num_point = num_pointV; 
    result.points = pointsV; 

    #ifdef DEBUG_F17
        printf("---------Shape------------\nRepresent point with '%c'\nNumber of points: %d\nAll points:\n", result.represent_point, result.num_point);
        for (int i = 1; i <= result.num_point; ++i) {
            printf("%d: point %s\n", i, point_to_string(result.points[i -1]));
        }
        printf("--------------------------\n");
    #endif

    return result; 
}

/****************************************
 * shape_to_string -- biểu hiện giá trị 
 *      hình dạng bằng xâu kí tự 
 * 
 * 
*/
char* shape_to_string(shape shapeV) {
    char* result; 

    result = (char*)malloc(MAX_LENGTH); 
    sprintf(result, "----------Shape---------\nRepresent point with '%c'\nNumber of points: %d\nAll points:\n", shapeV.represent_point, shapeV.num_point);
    for (int i = 1; i <= shapeV.num_point; ++i) {
        char str[50]; /* middle string */
        sprintf(str, "%d: point %s\n", i, point_to_string(shapeV.points[i -1]));
        strcat(result, str);
    }
    strcat(result, "-----------------------\n"); 

    #ifdef DEBUG_F17
        printf("Shape to string:\n%s", result); 
    #endif

    return result; 
}

/*******************************************
 * draw -- vẽ hình dạng vào không gian 
 *      cho sẵn 
 * 
*/
void draw_shape(shape shapeV, space* space_ptrV) {
    for (int i = 1; i <= shapeV.num_point; ++i) {
        draw_point(shapeV.points[i -1], shapeV.represent_point, space_ptrV);
    }

    #ifdef DEBUG_F16
        printf("The shape need draw is\n%s", shape_to_string(shapeV)); 
        print_space(*space_ptrV); 
    #endif
}


/************************************
 * is_point_belong_to_shape -- kiểm tra
 *      xem điểm có thuộc shape ko 
 * 
 * example: 
 * 
*/
int is_point_belong_to_shape(point pointV, shape shapeV) {
    int result; 

    result = 0; 
    for (int i = 1; i <= shapeV.num_point; ++i) {
        if (is_pointA_equal_pointB(pointV, shapeV.points[i -1])) {
            result = 1; 
            break; 
        }
    }

    #ifdef DEBUG_F16
        if (result) {
            printf("point %s belongs to shape below\n%s", point_to_string(pointV), shape_to_string(shapeV));
        } else {
            printf("point %s does not belong to shape below\n%s", point_to_string(pointV), shape_to_string(shapeV));
        }

    #endif

    return result; 
}

#ifdef DEBUG_P7

space game_space; /* create game_space space */
shape game_snake; /* create shape snake */
shape game_space_wall; /* create game_space wall */

int main(void) {
    game_space = space_template(5); 

    {
        point *snake_shape = (point*)malloc(2 * sizeof(point)); 
        snake_shape[1 -1] = point_template(2, 2); 
        snake_shape[2 -1] = point_template(2, 3); 
        game_snake = shape_template('*', 2, snake_shape); 
    }

    {
        point *wall_shape = (point*)malloc(4 * sizeof(point)); 
        wall_shape[1 -1] = point_template(1, 1); 
        wall_shape[2 -1] = point_template(1, 5); 
        wall_shape[3 -1] = point_template(5, 1); 
        wall_shape[4 -1] = point_template(5, 5); 

        game_space_wall = shape_template('=', 4, wall_shape); 
    }

    draw_shape(game_snake, &game_space); 
    draw_shape(game_space_wall, &game_space); 

    is_point_belong_to_shape(point_template(5, 5), game_space_wall); 


}

#endif
