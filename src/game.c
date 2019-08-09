#include <keypad.h>
#include <screen.h>

#define TO_STR(ch) ( ( ((ch) >= 0 ) && ((ch) <= 9) )? (48 + (ch)) : ('a' + ((ch) - 10)) )

extern void initLevel();

typedef struct clown
{
    int lives;
    int pos_x;
    int pos_y;
    bool ball;
} clown;

typedef struct dino
{
    bool isVisible;
    bool isDead;
    int pos_x;
    int pos_y;
    bool isTrapped;
    bool trappedWays[4];
} dino;

typedef struct wall
{
    bool hasCherry;
    bool exists;
}wall;

//enemies 2
uint8_t cherryNumber;
clown player;
dino dinos[3];
wall walls[13][12] = {false,false};

// void initLevel()
// {
    
//     for(int y=0;y<13;y++){

//         switch(y){
//             case(0):{
//                 for(int x=0;x<=3;x++){
//                     walls[0][x].exists=true;
//                 }
//                 walls[0][10].exists=true;
//                 walls[0][11].exists=true;
//                 break;

//             }
//             case(1):{
//                 for(int x=0;x<=8;x++){
//                 if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 walls[y][11].exists=true;
//                 break;
//             }
//             case(2):{
//                 for(int x=0;x<=9;x++){
//                 if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(3):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(4):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(5):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(6):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(7):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(8):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(9):{
//                 for(int x=0;x<=10;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(10):{
//                  for(int x=3;x<=9;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 break;
//             }
//             case(11):{
//                 walls[y][1].exists=true;
//                 for(int x=3;x<=8;x++){
//                     if(x==5) x++;
//                     walls[y][x].exists=true;
//                 }
//                 walls[y][11].exists=true;
//                 break;
//             }
//             case(12):{
//                 walls[y][10].exists=true;
//                 walls[y][11].exists=true;
//                 break;
            // }
//             default:{
//                 break;
//             }
//         }
//     }
// }
    //     if(y==0){
    //         for(int x=0;x<=3;x++){
    //             walls[y][x].exists=true;
    //         }
    //         walls[0][10].exists=true;
    //         walls[0][11].exists=true;

    //     }
       
    //     if(y==1){
    //         for(int x=0;x<=8;x++){
    //             if(x==5) x++;
    //             walls[y][x].exists=true;
    //         }
    //         walls[y][11].exists=true;
    //     }
    //     if(y==2){
    //        for(int x=0;x<=9;x++){
    //             if(x==5) x++;
    //             walls[y][x].exists=true;
    //         }
    //     }
    //     if(y==3||y==4||y==5||y==6||y==7||y==8||y==9){
    //        for(int x=0;x<=10;x++){
    //             if(x==5) x++;
    //             walls[y][x].exists=true;
    //         }
    //     }
    //     if(y==10){
    //          for(int x=3;x<=9;x++){
    //             if(x==5) x++;
    //             walls[y][x].exists=true;
    //         }
    //     }
    //     if(y==11){
    //         walls[y][1].exists=true;
    //         for(int x=3;x<=8;x++){
    //             if(x==5) x++;
    //             walls[y][x].exists=true;
    //         }
    //         walls[y][11].exists=true;
    //     }
    //     if(y==12){
    //         walls[y][10].exists=true;
    //         walls[y][11].exists=true;
    //     }
    // }

// }

void initCherries()
{
    cherryNumber = 40;

    for(int x=0;x<2;x++){
        for(int y = 1; y<5;y++){
            walls[y][x].hasCherry = true;
        }
    }

    for(int x=3;x<5;x++){
        for(int y = 3; y < 7; y++){
            walls[y][x].hasCherry = true;
        }
    }

    for(int x=8;x<10;x++){
        for(int y = 6; y < 10;y++){
            walls[y][x].hasCherry = true;
        }
    }

    for(int y = 8; y < 10;y++){
        for(int x=0;x<4;x++){
            walls[y][x].hasCherry = true;
        }
    }

     for(int y = 2; y < 4;y++){
        for(int x=6;x<10;x++){
            walls[y][x].hasCherry = true;
        }
    }
}

void initCharacters()
{
    player.lives = 3;
    player.pos_x=20;
    player.pos_y=28;
    player.ball = true;
    for(uint8_t i=0;i<3;i++){
        dinos[i].isVisible = false;                                                                                                                                                                                                                                                                                                                                          
        dinos[i].isDead = false;
        dinos[i].pos_x = 20;
        dinos[i].pos_y = 18;
        dinos[i].isTrapped=false;
        for(int j=0;j<4;j++){
            dinos[i].trappedWays[j]=false;
        }
    }
    
}

// void move_clow(uint8_t dir)
// {
//      switch(dir){
//             case(1):{
//                 if(player.pos_x>=4){
//                     player.pos_x-=4;
//                 }
//                 break;
//             }
//             case(2):{
//                 if(player.pos_x<=40){
//                     player.pos_x+=4;
//                 }
//                 break;
//             }
//             case(4):{
//                 if(player.pos_y<=26){
//                     player.pos_y+=2;
//                 }
//                 break;
//             }
//             case(8):{
//                 if(player.pos_y>=6){
//                     player.pos_y-=2;
//                 }
//                 break;
//             }
//             default:{
//                 break;
//             }
//         }
// }

bool calculate_dino_move(uint8_t pos_y, uint8_t pos_x)
{
    pos_y = pos_y >> 1;
    pos_x = pos_x >> 2;
    return !walls[pos_y-2][pos_x].exists;
}

void clean_enemy_trapped_ways(dino *enemy){
    for(uint8_t i=0;i<4;i++){
        enemy->trappedWays[i]=false;
    }
    return;
}

void move_enemy(dino *enemy)
{
    bool sides[4]={false};
    int pos_x, pos_y;
    
    pos_y = enemy->pos_y+2;
    sides[0] = pos_y > 28 ? false : calculate_dino_move(pos_y,enemy->pos_x);
    pos_y = enemy->pos_y-2;
    sides[1] = pos_y < 4 ? false : calculate_dino_move(pos_y,enemy->pos_x);
    pos_x = enemy->pos_x-4;
    sides[2] = pos_x < 0 ? false : calculate_dino_move(enemy->pos_y,pos_x);
    pos_x = enemy->pos_x+4;
    sides[3] = pos_x > 44 ? false : calculate_dino_move(enemy->pos_y,pos_x);
    if(enemy->isTrapped){
        if(enemy->pos_x<player.pos_x && !sides[3]){
            if(!enemy->trappedWays[0]){
                if(sides[0]){
                    enemy->pos_y+=2;
                    // if(calculate_dino_move(enemy.pos_y,enemy.pos_x+4)){
                    //     enemy.isTrapped = false;
                    //     clean_enemy_trapped_ways(enemy);
                    // }
                    return;
                }else{
                    enemy->trappedWays[0]=true;
                    return;
                }
            }
            if(!enemy->trappedWays[1]){
                if(sides[1]){
                    enemy->pos_y-=2;
                    
                    return;
                }else{
                    enemy->trappedWays[1] = true;
                    return;
                }
                
            }
        }
        if(enemy->pos_x<player.pos_x && sides[3]){
            enemy->pos_x+=4;
            enemy->isTrapped = false;
            clean_enemy_trapped_ways(enemy);
            return;
        }
        if(enemy->pos_x>player.pos_x && !sides[2]){
            if(!enemy->trappedWays[0]){
                if(sides[0]){
                    enemy->pos_y+=2;
                    // if(calculate_dino_move(enemy.pos_y,enemy.pos_x-4)){
                    //     enemy.isTrapped = false;
                    //     clean_enemy_trapped_ways(enemy);
                    // }
                    return;
                }else{
                    enemy->trappedWays[0]=true;
                    return;
                }
            }
            if(!enemy->trappedWays[1]){
                if(sides[1]){
                    enemy->pos_y-=2;
                    // if(calculate_dino_move(enemy.pos_y,enemy.pos_x-4)){
                    //     enemy.isTrapped = false;
                    //     clean_enemy_trapped_ways(enemy);
                    // }
                    return;
                }else{
                    enemy->trappedWays[1] = true;
                    return;
                }
                
            }
        }
        if(enemy->pos_x>player.pos_x && sides[2]){
            enemy->pos_x-=4;
            enemy->isTrapped = false;
            clean_enemy_trapped_ways(enemy);
            return;
        }
    }
    if(sides[0]){
        if(player.pos_y>enemy->pos_y){
            enemy->pos_y +=2;
            return;
        }
    }
    if(sides[1]){
        if(enemy->pos_y>player.pos_y){
            enemy->pos_y -=2;
            return;
        }
    }
    if(sides[3]){
        if(enemy->pos_x<player.pos_x){
            enemy->pos_x +=4;
            return;
        }
    }
    if(sides[2]){
        if(enemy->pos_x>player.pos_x){
            enemy->pos_x -=4;
            return;
        }
    }
    else{
        enemy->isTrapped=true;
    }
}

void move_dinos(){
    for(uint8_t i = 0;i < 3;i++){
        if(dinos[i].isVisible){
            move_enemy(&dinos[i]);
        }
    }
}

void draw_clown()
{
    uint8_t pieces=1;
    set_color(MAGENTA,BLACK);
    uint8_t row = player.pos_y, col = player.pos_x;
    for(uint8_t i=0;i<4;i++){
        set_cursor(row,col++);
        put_char(pieces++);
    }
    col-=4;
    row++;
    for(uint8_t i=0;i<4;i++){
        set_cursor(row,col++);
        put_char(pieces++);
    }
}

void draw_enemy(dino *enemy)
{
    uint8_t pieces=11;
    set_color(LIGHT_BLUE,BLACK);
    uint8_t row = enemy->pos_y, col = enemy->pos_x;
    for(uint8_t i=0;i<4;i++){
        set_cursor(row,col++);
        put_char(pieces++);
    }
    col-=4;
    row++;
    for(uint8_t i=0;i<4;i++){
        set_cursor(row,col++);
        put_char(pieces++);
    }

    set_cursor(28,78);
    set_color(WHITE,BLACK);
    uint8_t varx = enemy->pos_x>>2;
    varx = TO_STR(varx);
    put_char(varx);
    set_cursor(29,78);
    uint8_t vary = enemy->pos_y>>1;
    vary = TO_STR(vary-2);
    put_char(vary);
}

void draw_dinos(){
    for(uint8_t i=0;i<3;i++){
        if(dinos[i].isVisible){
            draw_enemy(&dinos[i]);
        }
    }
}

void draw_level()
{
    uint8_t pos_x = 0,
            pos_y = 0,
            pos = 0;
    set_cursor(pos_y,pos_x);
    for(uint8_t y=0;y<13;y++){
        for(uint8_t x=0;x<12;x++){
            if(walls[y][x].exists){
                pos_x = 4 * x;
                pos_y =  2 * y;
                pos_y+=4;
                if(walls[y][x].hasCherry){
                    pos =19;
                    set_color(RED,LIGHT_GREEN);
                    for(uint8_t i=0;i<4;i++){
                        set_cursor(pos_y,pos_x+i);
                        put_char(pos++);
                    }
                    pos_y++;
                    for(uint8_t i=0;i<4;i++){
                        set_cursor(pos_y,pos_x+i);
                        put_char(pos++);
                    }
                }else{
                    set_color(GREEN,LIGHT_GREEN);
                    for(uint8_t i=0;i<4;i++){
                        set_cursor(pos_y,pos_x+i);
                        put_char(9);
                    }
                    pos_y++;
                    for(uint8_t i=0;i<4;i++){
                        set_cursor(pos_y,pos_x+i);
                        put_char(9);
                    }
                }
            }
        }
    }
}

void draw_gui()
{

    uint8_t pos_y  = 5;
    uint8_t pos_x = 50;
    set_color(YELLOW,BLACK);
    for(uint8_t i=0;i<25;i++){
        set_cursor(pos_y,pos_x++);
        put_char(220);
    }
    pos_x--;
    pos_y++;
    for(uint8_t i=0;i<3;i++){
        set_cursor(pos_y++,pos_x);
        put_char(219);
    }
    pos_y--;
    pos_x--;
    for(uint8_t i=0;i< 23;i++){
        set_cursor(pos_y,pos_x--);
        put_char(220);
    }
    for(uint8_t i=0;i< 3;i++){
        set_cursor(pos_y--,pos_x);
        put_char(219);
    }

    set_cursor(7,59);
    set_color(BRIGHT_WHITE,BLACK);
    puts("MR. DO!");


    // pos_y =6;
    // pos_x=50;
    // for(uint8_t i=0;i< 3;i++){
    //     set_cursor(pos_y++,pos_x);
    //     put_char(219);
    // }

    pos_x =48,pos_y=16;
    uint8_t pieces=1;
    set_color(MAGENTA,BLACK);
    for(uint8_t i=0;i<4;i++){
        set_cursor(pos_y,pos_x++);
        put_char(pieces++);
    }
    pos_x-=4;
    pos_y++;
    for(uint8_t i=0;i<4;i++){
        set_cursor(pos_y,pos_x++);
        put_char(pieces++);
    }
    
    set_color(WHITE,BLACK);
    pos_x = 56;
    set_cursor(pos_y,pos_x++);
    put_char(10);

    pos_x +=4;
    char lives = TO_STR(player.lives);
    set_cursor(pos_y,pos_x++);
    put_char(lives);

}

void check_collision()
{
    uint8_t pos_x = player.pos_x,
            pos_y = player.pos_y;
    pos_y-=4;
    pos_x = pos_x >> 2;
    pos_y = pos_y >> 1;
    char x = TO_STR(pos_x),y = TO_STR(pos_y);
    set_cursor(28,79);
    put_char(x);
    set_cursor(29,79);
    put_char(y);
    if(walls[pos_y][pos_x].exists){
        walls[pos_y][pos_x].exists = false;
        if(walls[pos_y][pos_x].hasCherry){
            cherryNumber--;
        }
    }
}

bool respawn(uint8_t* dino_number, uint8_t* dino_spawn_time)
{
    if(player.lives==0){
        return true;
    }else{
        delay_ms(100);
        *dino_number = 0;
        *dino_spawn_time = 10;
        player.pos_x=20;
        player.pos_y=28;
        for(uint8_t i=0;i<3;i++){
            dinos[i].isVisible = false;                                                                                                                                                                                                                                                                                                                                          
            dinos[i].isDead = false;
            dinos[i].pos_x = 20;
            dinos[i].pos_y = 18;
            dinos[i].isTrapped=false;
            for(int j=0;j<4;j++){
                dinos[i].trappedWays[j]=false;
            }
        }
        return false;
    }
}

bool check_loose()
{
    for(uint8_t i=0;i<3;i++){
        if(dinos[i].pos_x == player.pos_x && dinos[i].pos_y == player.pos_y){
            player.lives--;
            return true;
        }
    }
    return false;
}

bool check_win()
{
    return cherryNumber == 0;
}

void dino_spawn(uint8_t *dino, uint8_t *time){
    if(*time == 0){
        if(*dino<3){
            dinos[*dino].isVisible = true;
            *time = 30;
            *dino = *dino+1;
        }
    }else{
        *time = *time -1;
    }
}

void initLevelOne(){
    initLevel();
    initCherries();
    initCharacters();
    draw_level();
    draw_gui();
    draw_clown();
}

void draw_everything()
{
    draw_level();
    draw_gui();
    draw_clown();
    draw_dinos();
}

void draw_win_scenario(){
    set_cursor(18,16);
    set_color(WHITE,BLACK);
    check_win()? puts("YOU     WIN"):puts("YOU     LOSE");
    set_cursor(19,13);
    puts("PRESS R TO RESTART");
}