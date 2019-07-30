#include "screen.c"
#include "keypad.c"
#include "game.c"



int main() {
    clear_screen();
    initLevelOne();
    uint8_t dir, dino_number=0, dino_spawn_time=10;
    while (1) {
        
        dir = keypad_getkey();
        if(dir!=0){
            move_clow(dir);
            check_collision();
        }
        move_dinos();
        draw_everything();
        if(check_win()){
            break;
        }
        if(check_loose()){
            if(respawn(&dino_number,&dino_spawn_time)){
                break;
            }
        }
        set_color(WHITE, BLACK);
        set_cursor(1,1);
        put_char(TO_STR(dir));
        set_cursor(0,79);
        put_char(TO_STR(dino_spawn_time));
        dino_spawn(&dino_number,&dino_spawn_time);
        delay_ms(100);
        clear_screen();
    }

    while(1){
        draw_everything();
        draw_win_scenario();
    }

    return 0;
}
