#include <stdio.h>
#include <stdlib.h>

void wait_1ms(int); 
int strlen(char str[]); 
void print_type_writing(char str[], int, int);
void clrscr(void); 

// int main(void) {
//     for (int i = 1; i <= 10; i++) {
//         printf("%d", i);
//         wait_1ms(1000); 
//         clrscr(); 
//     }
    
    
// }

// program to clear the screen
void clrscr() {
    printf("\e[1;1H\e[2J"); 
}

// program to wait msec milisecond until go to the next statement
void wait_1ms(int msec) {
    while (msec >= 1) {
        int count = 663157; // count for 1ms
        while (count >= 1) {
            count--; 
        }
        msec--; 
    }
}


// program to count the lenght of a string
int strlen(char str[]) {
    int result; 
    result = 0; 
    bool is_end_of_string = false; 
    while (!is_end_of_string) {
        is_end_of_string = (str[result] == '\0');
        result++; 
    }

    return result; 
}

/** program to print the text str with the speed * 100 (milisecond) 
 *      and delay * 100 (milisecond)
 * 
*/
void print_type_writing(char str[], int speed, int delay) {
    for (int i = 0; i <= strlen(str) - 1; i++) {
        printf("%c", str[i]); wait_1ms(speed * 100); 
    }
    wait_1ms(delay * 100); 
}