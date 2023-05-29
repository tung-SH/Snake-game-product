/*****************************************
 * interactive.c -- thư viện cung cấp các 
 *      hàm tương tác với file stdout và 
 *      stdin 
 * 
 * PURPOSE: 1. cung cấp các hàm hỗ trợ cho 
 *              việc tương tác trên terminal,
 *              cụ thể là file stdout, stdin 
 *          2. tạo các hàm sau
 *              2.1 hàm chờ msec milisecond
 *              2.2 hàm hiệu ứng gõ 
 *              2.3 hàm xóa màn hình 
 * 
 * STATUS: hoàn thành mục đích 
 * 
 * SOURCE: tự nghĩ 
 * 
*/
#include <stdlib.h>
#include <string.h>
// #include "setting_general.h"


/**********************************
 * wait_1ms -- chờ msec milisecond 
 *      trước khi sang câu lệnh
 *      tiếp theo 
 * 
*/
void wait_1ms(int msec) {
    while (msec >= 1) {
        int count = 663157; // count for 1ms
        while (count >= 1) {
            count--; 
        }
        msec--; 
    }
}

/***********************************************
 * type_writing -- xâu kí tự xuất hiện theo 
 *      hiệu ứng từng chữ với tốc độ speed * 100ms
 *      và nghỉ với thời gian delay * 100ms
 * 
*/
void type_writing(const char str[], int speed, int delay) {
    for (int i = 1; i <= strlen(str); ++i) {
        printf("%c", str[i -1]); wait_1ms(speed * 100); 
    }
    wait_1ms(delay * 100); 
}


/*************************************
 * clrscr -- xóa màn hình tương tác 
 * 
*/
void clrscr(void) {
    system("cls"); 
}


#ifdef DEBUG_G

int main(void) {
    for (int i = 10; i >= 1; --i) {
        printf("count down to %d", i); wait_1ms(1000); 
        clrscr();  
    }
}

#endif