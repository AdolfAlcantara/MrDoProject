#include <screen.h>

uint8_t BGCOLOR = 0;
uint8_t FGCOLOR = 0;
uint8_t ROW = 0;
uint8_t COLUMN = 0;

void set_color(uint8_t fgcolor, uint8_t bgcolor)
{
    FGCOLOR = fgcolor;
    BGCOLOR = bgcolor;
}

void get_color(uint8_t *fgcolor, uint8_t *bgcolor)
{
    *fgcolor = FGCOLOR;
    *bgcolor = BGCOLOR;
}

void set_cursor(uint8_t row, uint8_t col)
{
    ROW = row;
    COLUMN = col;
}

void get_cursor(uint8_t *row, uint8_t *column){
    *row = ROW;
    *column = COLUMN;
}

void put_char(uint8_t ch)
{
    uint16_t data = 0;
    data = data | BGCOLOR;
    data = data<<4;
    data = data | FGCOLOR;
    data = data<<8;
    data = data | ch;
    uint16_t *pos = (uint16_t *)VGA_START_ADDR+(ROW*80)+COLUMN;
    *pos = data;
}

void puts(const char *message)
{
    uint8_t col=0;
    uint8_t row=0;
    get_cursor(&row,&col);
    while(*message){
        put_char(*message);
        message++;
        set_cursor(row,++col);
    }
}

void clear_screen(){
    uint8_t col = 0;
    uint8_t row = 0;
    set_color(YELLOW,BLACK);
    while(row < MAX_ROWS){
        while(col<MAX_COLS){
            set_cursor(row,col);
            put_char(' ');
            col++;
        }
        row++;
        col=0;
    }
}