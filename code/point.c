/*******************************************
 * point.c -- giá trị điểm trong không gian 
 * 
 * PURPOSE: 
 *      - tổng quan: tạo giá trị điểm 
 *          để tạo cơ sở cho giá trị hình dáng, 
 *          sau đó tạo ra mê cung, táo và rắn 
 * 
 *      - cụ thể: định nghĩa điểm và 2 hàm cơ bản
 *                  hàm vẽ điểm vào không gian,
 *                  hàm so sánh 2 điểm 
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
 *      - PROGRAM: 8
 *      - FUNCTION: 19, 18
 * 
**********************************************/
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

    #ifdef DEBUG_F19
        printf("point template is (%d, %d).\n", result.x, result.y); 
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

    #ifdef DEBUG_F19
        printf("point to string is %s.\n", result); 
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

    #ifdef DEBUG_F18
        printf("After draw point %s.\n", point_to_string(pointV)); 
        print_space(*space_ptrV); 
    #endif
}

/************************************
 * is_pointA_equal_pointB -- kiểm 
 *      tra điểm B có bằng điểm B 
 *      hay ko  
 * 
 * example: 
 * 
*/
int is_pointA_equal_pointB(point pointA, point pointB) {
    int result; 

    if (pointA.x == pointB.x && pointA.y == pointB.y) {
        result = 1; 
    } else {
        result = 0; 
    }

    #ifdef DEBUG_F18
        if (result) {
            printf("point %s equals to point %s.\n", point_to_string(pointA), point_to_string(pointB)); 
        } else {
            printf("point %s does not equal to point %s.\n", point_to_string(pointA), point_to_string(pointB)); 
        }
    #endif 

    return result; 
}

#ifdef DEBUG_P8

point A, B; /* declare 2 points A and B */
space game_space; 

int main(void) {
    game_space = space_template(5); 
    A = point_template(1, 2); 
    B = point_template(3, 4); 

    draw_point(A, 'A', &game_space); 
    draw_point(B, 'B', &game_space); 

    is_pointA_equal_pointB(A, point_template(1, 2)); 
    
}

#endif