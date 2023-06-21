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

const int TIME_TO_START_GAME = 3000; /* TIME FOR USER TO WAIT UNTIL THE GAME START */
const int TIME_TO_DISPLAY_GAME_OVER_MENU = 4000; /* TIME TO DISPLAY GAME OVER MENU */


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
                game_status status = game_mode_1_run(&snake_game);
                if (count == 1) {
                    wait_1ms(TIME_TO_START_GAME);
                    ++count; 
                }
                 

                if (status == OVER) {
                    print_game_over(); 
                    wait_1ms(TIME_TO_DISPLAY_GAME_OVER_MENU); 
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