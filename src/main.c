#include <sys/lcd.h>
#include <keypadc.h>
#include <string.h>
#include <ti/getcsc.h>
#include <ti/screen.h>
#include <stdlib.h>
#include <graphx.h>
#include <debug.h>
#include <fontlibc.h>

#include "fonts/fonts.h"

/* Function Prototypes */
struct question 
{
    char myQuestion[100];
};
struct answer 
{
    char myAnswer[100];
};

void ClearKeyboardBuffer() {
	while (kb_AnyKey()) {
		kb_Scan();
	}
}

void PrintCentered(const char *string);
int main(void)
{
    int displayQuestion = 1;
    int numQuestion = 3;
    gfx_Begin();
    gfx_SetDrawBuffer();

	// Set up Fontlib stuff
    fontlib_SetFont(test_font, 0);

    /* First, we'll display centered text in a window */
    /* Add some vertical padding around our text */
    fontlib_SetWindow(25, 40, 240, 200);
    fontlib_SetLineSpacing(2, 2);
    /* Set some random (and ugly) colors */
    fontlib_SetColors(0x0, 0xFF);
    /* This is a crazy combination of settings that you probably don't want to use in any real program, but we're using
    it here for testing purposes. */
    fontlib_SetTransparency(true);
    fontlib_SetNewlineOptions(FONTLIB_ENABLE_AUTO_WRAP | FONTLIB_AUTO_CLEAR_TO_EOL | FONTLIB_PRECLEAR_NEWLINE);


    int count = 0;
    struct question questions[5];
    struct answer answers[5];
    
    // Set the initial questions and answers
    strcpy(questions[0].myQuestion, "What day is today?");
    strcpy(answers[0].myAnswer, "Saturday");
    
    strcpy(questions[1].myQuestion, "What is your name?");
    strcpy(answers[1].myAnswer, "Tom");
    
    strcpy(questions[2].myQuestion, "a(n) ___ bond is formed when atoms share electrons");
    strcpy(answers[2].myAnswer, "Covalent");

    strcpy(questions[3].myQuestion, "water molecules 'stick' to each other by means of");
    strcpy(answers[3].myAnswer, "Hydrogen (Bonds)");

    do
    {
        /* Update kb_Data */
		kb_Scan();
		if( kb_Data[3] == kb_7)
		{
			count--;
			if(count < 0)
			{
				count = 0;
			}
			displayQuestion = 1;
			ClearKeyboardBuffer();

		}
		else if(kb_Data[4] == kb_8)
		{
			displayQuestion = !displayQuestion;
			ClearKeyboardBuffer();
		}
		else if(kb_Data[5]== kb_9)
		{
			count++;
			if(count >= numQuestion)
			{
				count = numQuestion - 1;
			}
			displayQuestion = 1;
			ClearKeyboardBuffer();
		}


		gfx_FillScreen(255);

		if(displayQuestion)
		{
			PrintCentered(questions[count].myQuestion);
		}
		else
		{
			PrintCentered(answers[count].myAnswer);
		}
		gfx_SwapDraw();

	} while (kb_Data[1] != kb_2nd);
	gfx_End();
	return 0;
}

void PrintCentered(const char *string)
{
    /* We're just using some simple math to find the center of the text window.
    Then we find the center of the text to be displayed and use math to make
    sure it ends up in the center of the window. */
    fontlib_SetCursorPosition(10, GFX_LCD_HEIGHT/3);
    fontlib_DrawString(string);
}
