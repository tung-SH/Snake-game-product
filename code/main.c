/*******************************************
 * main.c -- chương trình chính của game 
 *      rắn săn mồi 
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
 *      - PROGRAM: 
 *      - FUNCTION: 
 * 
**********************************************/

#include "menu.c"

game snake_game; 
int user_choice; 

int main(void) {
    while(1) {
        snake_game = game_level_1_init(); 
        print_main_menu(); 
        scanf("%d", &user_choice); 
        if (user_choice == 1) {
            while (1) {
                static int count = 1; 
                game_status status = game_mode_2_run(&snake_game);
                if (count == 1) {
                    wait_1ms(3000);
                    ++count; 
                }
                 

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