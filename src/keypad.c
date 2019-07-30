#include <keypad.h>

uint8_t keypad_getkey()
{
    return *BTN_STATE_REG_ADDR; 
}

void delay_ms(uint32_t ms)
{
    uint32_t time = *MS_COUNTER_REG_ADDR;
    uint32_t expected_time = time + ms;
    while(time < expected_time){
        time = *MS_COUNTER_REG_ADDR;
    }
}