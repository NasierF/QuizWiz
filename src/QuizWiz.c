#include <ti/getcsc.h>
#include <graphx.h>
#include <compression.h>
#include <sys/lcd.h>
#include <keypadc.h>
#include <string.h>
#include <ti/screen.h>
#include <stdlib.h>
#include <debug.h>
#include "gfx/gfx.h"
#include "gfx/FlashCards.h"
#include "gfx/Trivia.h"
void PrintedCentered(const char *str);
void PrintMenuopt1(const char *str);
void PrintMenuOpt3(const char *str);

int main(void)
{
    const char str[] = {"2. trivia quizzes"};
    const char opt1[] = {"1. flash cards"};
    const char opt2[] = {"0. exit"};
    gfx_Begin();
    
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    zx7_Decompress(gfx_vram, QuizWiz_back_compressed);

    gfx_SetTransparentColor(0x0);
    gfx_Sprite_NoClip(QuizWizTxt, 80, 90);
    gfx_TransparentSprite_NoClip(QuizWizTxt, 80, 90);
    while (!os_GetCSC());
    gfx_FillScreen(200);
    //Aplication initialization is done here
    //PrintedCentered(str);
    while(1){
    gfx_FillScreen(200);
    PrintMenuopt1(opt1);
    PrintedCentered(str);
    PrintMenuOpt3(opt2);
    while (!os_GetCSC());
    kb_Scan();
    if (kb_Data[3] == kb_1){
        gfx_FillScreen(200);
        //PrintedCentered("nisubviuviudivusbvisb");
        FlashCards();
        gfx_SetDrawScreen();
        gfx_FillScreen(200);
    } else if(kb_Data[3] == kb_0){
        gfx_End();
        exit(0);
    }else if (kb_Data[4] == kb_2){
        gfx_SetPalette(gfx_palette, 512, 0);
        Trivia();
        gfx_SetDrawScreen();
        gfx_SetPalette(global_palette, sizeof_global_palette, 0);
    }



    }

    gfx_End();

    return 0;
}

void PrintedCentered(const char *str)
{
    gfx_PrintStringXY(str, (GFX_LCD_WIDTH - gfx_GetStringWidth(str))/2, (GFX_LCD_HEIGHT - 8)/2);
}

void PrintMenuopt1(const char *str)
{
    gfx_PrintStringXY(str, (GFX_LCD_WIDTH - gfx_GetStringWidth(str))/2, (GFX_LCD_HEIGHT - 60)/2);
}

void PrintMenuOpt3(const char *str)
{
    gfx_PrintStringXY(str, (GFX_LCD_WIDTH - gfx_GetStringWidth(str))/2, (GFX_LCD_HEIGHT + 40)/2);
}