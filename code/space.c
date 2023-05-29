/*****************************************
 * space.c -- tạo giá trị không gian 
 * 
 * PURPOSE: 
 *      1. tạo giá trị không gian chơi cũng như
 *          hiển thị rắn, táo, mê cung
 *      2. 
 * 
 * STATUS: 
 * 
 * SOURCE: https://tinyurl.com/tungsh6 
 * 
 * DEBUG_NUMBER: 9
 * 
*/

#include "header/setting_function.h"
#include "header/setting_program.h"
#include <stdlib.h>
#include <string.h>


const long long MAX_LENGTH = 10000; /* MAX LENGTH OF STRING */

struct space {
    int size; /* size of space */
    char* spaces; /* actual space*/
};

typedef struct space space; 

/*********************************************
 * print_space -- in ra giá trị không gian
 *      vào file stdout
 * 
*/
void print_space(space spaceV) {
    for (int i = 1; i <= spaceV.size; ++i) {
        for (int j = 1; j <= spaceV.size; ++j) {
            printf("%c ", *(spaceV.spaces + (i - 1) * spaceV.size + j - 1));
        }
        printf("\n");
    }
}

/***************************************************
 * space_template -- tạo ra 1 giá trị mẫu để bỏ vào 
 *      biến không gian
 * 
 * 
*/
space space_template(int sizeV) {
    space result; 

    result.size = sizeV; 
    result.spaces = (char*)malloc(result.size * result.size);
    


    for (int i = 1; i <= result.size; ++i) {
        for (int j = 1; j <= result.size; ++j) {
            #ifdef DEBUG_F9
                *(result.spaces + (i - 1) * result.size + j - 1) = '0';
            #else 
                *(result.spaces + (i - 1) * result.size + j - 1) = ' ';
            #endif
             
        }
    }

    #ifdef DEBUG_F9
        print_space(result); 
    #endif

    return result; 
}

#ifdef DEBUG_P9

space game_space; /* create space maze */

int main(void) {
    game_space = space_template(10); 
}

#endif



