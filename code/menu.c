/*******************************************
 * menu.c -- menu của game rắn săn mồi 
 * 
 * PURPOSE: 
 *      - tổng quan: 
 *      - cụ thể: 
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
 *      - PROGRAM: 2
 *      - FUNCTION: 
 * 
**********************************************/
#include "game.c"

/************************************
 * print_main_menu -- in ra màn hình 
 *      menu chính với 3 sự lựa chọn
 *          1. bắt đầu chơi 
 *          2. hướng dẫn 
 *          3. thoát game 
 * 
 * example: 
 * 
*/
void print_main_menu(void) {
    clrscr(); 
    printf("----------- MAIN MENU -----------\n"); 
    printf("1. Start play game\n"); 
    printf("2. Instructions\n"); 
    printf("3. Exit\n"); 
    printf("Your choice: "); 
}

/************************************
 * print_instruction_menu -- in ra màn 
 *      hình hướng dẫn cho game rắn 
 *      săn mồi 
 * 
 * example: 
 * 
*/
void print_instruction_menu(void) {
    clrscr(); 
    printf("-------- INSTRUCTION MENU --------\n"); 
    printf("1. Use 'a', 's', 'w', 'd' to control the snake\n"); 
    printf("2. The more apple snake eats, the more length it grows\n"); 
    printf("3. if snake eat itself or crush maze, game overs.\n"); 
    printf("Enter '0' to back to MAIN MENU: "); 
}


/************************************
 * print_game_over -- in ra màn hình 
 *      game over!
 * 
 * example: 
 * 
*/
void print_game_over(void) {
    clrscr(); 
    printf("|--------------------------------|\n");
    printf("|                                |\n");
    printf("|          GAME OVER!            |\n");
    printf("|                                |\n");
    printf("|--------------------------------|\n"); 
}

#ifdef DEBUG_P2

game snake_game; 
int user_choice; 

int main(void) {
    while(1) {
        snake_game = game_level_1_init(); 
        print_main_menu(); 
        scanf("%d", &user_choice); 
        if (user_choice == 1) {
            while (1) {
                
                game_status status = game_run(&snake_game);

                if (status == OVER) {
                    print_game_over(); 
                    wait_1ms(4000); 
                    break; 
                }
            }
        } else if (user_choice == 2) {
            while (1) {
                print_instruction_menu(); 
                scanf("%d", &user_choice); 
                if (user_choice == 0) {
                    break; 
                }
            }
        } else if (user_choice == 3) {
            break; 
        }
    }
}

#endif 