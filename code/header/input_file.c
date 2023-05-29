/****************************************
 * input_file.c -- cung cấp các hàm làm 
 *      việc nhanh với file input 
 * 
 * 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const long long MAX_LENGTH = 10000; /* MAX LENGTH OF STRING */


/*******************************************
 * num_line_file -- đếm số dòng của 1 file
 * 
*/
int num_line_file(const char* file_name) {
    int result = 0; 

    FILE* input_file; /* file variable containing input data */
    input_file = fopen(file_name, "r");

    char line[100]; /* input line */
    
    char* status; /* status of fgets function */
    status = fgets(line, sizeof(line), input_file);

    while (1)
    {
        if (status == NULL) {
            break;
        } else {
            ++result;
            status = fgets(line, sizeof(line), input_file); 
        }
    }

    #ifdef DEBUG9
        printf("The number of line in file \"%s\" is %d lines", file_name, result); 
    #endif  

    return result; 
}

/***********************************************
 * content_line_file -- nội dung 1 dòng cụ thể 
 *      của file
 * 
*/
char* content_line_file(const char* file_name, int lineV) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    FILE* input_file; 
    input_file = fopen(file_name, "r"); 
    char line[100]; /* input line */

    if (lineV > num_line_file(file_name)) {
        result = NULL; 
    } else {
        for (int i = 1; i <= lineV; ++i) {
            fgets(line, sizeof(line), input_file);
        }

        strcpy(result, line); 
    }



    return result; 
}


/******************************************
 * content_file -- nội dung của cả file 
*/
char* content_file(const char* file_name) {
    char* result; 
    result = (char*)malloc(MAX_LENGTH); 

    if (num_line_file(file_name) == 0) {
        result = NULL; 
    } else if (num_line_file(file_name) == 1) {
        strcpy(result, content_line_file(file_name, 1));
    } else {
        strcpy(result, content_line_file(file_name, 1)); 

        for (int i = 2; i <= num_line_file(file_name); ++i) {
            strcat(result, content_line_file(file_name, i)); 
        }
    }

    


    return result; 
}


#ifdef DEBUG_G

int main(void) {

    content_file("output.txt"); 



}

#endif