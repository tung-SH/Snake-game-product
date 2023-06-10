/*************************************
 * point.c -- cơ sở vị trí cho các vật thể 
 *      trong game răn săn mồi 
 * 
 * PURPOSE: tạo cơ sở vị trí cho các vật thể 
 *      như rắn, mê cung, táo trong game 
 *      rắn săn mồi 
 * 
 * STATUS: 
 * 
 * SOURCE: https://tinyurl.com/tungsh6
 * 
 * DEBUG_NUMBER: 8
 * 
*/
#include "space.c"

/***************************
 * point trong trục tọa độ 
 * 0 ----------------> Y
 * |
 * |
 * |
 * |
 * |
 * v
 * X
*/
struct point {
    int x; /* coordinate x of point */
    int y; /* coordinate y of point */
};

typedef struct point point; 


/***************************************************
 * point_template -- tạo ra 1 giá trị mẫu để bỏ vào 
 *      biến điểm 
 * 
 * 
*/
point point_template(int xV, int yV) {
    point result; 

    result.x = xV; 
    result.y = yV; 

    #ifdef DEBUG_F8
        printf("point is (%d, %d).\n", result.x, result.y); 
    #endif

    return result; 
}


/****************************************
 * point_to_string -- biểu hiện giá trị 
 *      điểm bằng xâu kí tự 
 * 
 * 
*/
char* point_to_string(point pointV) {
    char* result; 

    result = (char*)malloc(MAX_LENGTH); 
    sprintf(result, "(%d,%d)", pointV.x, pointV.y); 

    #ifdef DEBUG_F8
        printf("%s", result); 
    #endif

    return result; 
}

/*******************************************
 * draw -- vẽ 1 điểm vào không gian 
 *      cho sẵn 
 * 
*/
void draw_point(point pointV, char type_point, space* space_ptrV) {
    if (pointV.x <= space_ptrV->size || pointV.y <= space_ptrV->size) {
        *(space_ptrV->spaces + (pointV.x -1) * space_ptrV->size + pointV.y -1) = type_point; 
    }

    #ifdef DEBUG_F8
        print_space(*space_ptrV); 
    #endif
}


#ifdef DEBUG_P8

point A, B; /* declare 2 points A and B */
space game_space; 

int main(void) {
    game_space = space_template(5);
    A = point_template(1, 4); 
    draw_point(A, '*', &game_space); 
    B = point_template(3, 3); 
    draw_point(B, '*', &game_space); 
}

#endif