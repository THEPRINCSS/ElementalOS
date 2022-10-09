/*
 *      Elemental OS
 *Copyright(c) Andrey Skripcka, 2022
 * 
 */

#include <kstdint.h>
#include <kstring.h>


#define SCREEN_HEIGHT 80
#define SCREEN_WIDTH 25
#define SCREEN_MATRIX SCREEN_HEIGHT * SCREEN_WIDTH

uint16_t * screen = (uint16_t*)(0xb800 << 8);
uint16_t screen_step = 0;

#define TAB 4
#define VERTICAL_TAB 2

//данная функция передвигает экран на одну строку
void reprint()
{
    for(int i = 0; i < SCREEN_MATRIX - SCREEN_HEIGHT; i++)
    {
        screen[i] = screen[i + 80];
    }
}


//выводит текст на экран
void print(const char* text)
{
   for(size_t i = 0; i < kstrlen(text);i++)
   {
        if(screen_step == SCREEN_MATRIX)
        {
            rewrite();
            screen_step -= SCREEN_HEIGHT;
        }
        switch (text[i])
        {
            //если символ перехода строки
        case '\n':
            screen_step = ((screen_step / SCREEN_HEIGHT + 1) * SCREEN_HEIGHT); 
            break;
            //если символ табуляции
        case '\t':
            uint8_t step = 0;
            while(step < TAB)
            {
                if(screen_step % SCREEN_HEIGHT == 0)
                    break;
                screen[screen_step] = (' ' << 8) + 0x07;
                screen_step++;
            }
            break;
            //если символ вертикальной таблуляции
        case 'v':
            screen_step -= screen_step % SCREEN_HEIGHT;
            screen_step += SCREEN_HEIGHT * VERTICAL_TAB;
            break;
            //просто вывод на экран
        default:
            screen[screen_step] = ((text[i] << 8) + 0x07);
            screen_step++;
            break;
        }
   } 
}

//очищает экран
void screen_clear()
{
    for(int i = 0; i < SCREEN_MATRIX; i++)
    {
        screen[i] = (' ' << 8) + 0x07;
    }
}