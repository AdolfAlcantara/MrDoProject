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
        draw_level();
        draw_gui();
        draw_clown();
        draw_dinos();
        set_color(WHITE, BLACK);
        set_cursor(1,1);
        put_char(TO_STR(dir));
        set_cursor(0,79);
        put_char(TO_STR(dino_spawn_time));
        dino_spawn(&dino_number,&dino_spawn_time);
        delay_ms(100);
        clear_screen();

    }

    return 0;
}
