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
#include "gfx/gfx.h"
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
    int numQuestion = 10;
    gfx_Begin();
    gfx_SetDrawBuffer();

	// Set up Fontlib stuff
    fontlib_SetFont(test_font, 0);

    /* First, we'll display centered text in a window */
    /* Add some vertical padding around our text */
    fontlib_SetWindow(25, 40, 240, 200);
    fontlib_SetLineSpacing(2, 2);
    /* Set some random (and ugly) colors */
    fontlib_SetColors(0x2, 0xFF);
    /* This is a crazy combination of settings that you probably don't want to use in any real program, but we're using
    it here for testing purposes. */
    fontlib_SetTransparency(true);
    fontlib_SetNewlineOptions(FONTLIB_ENABLE_AUTO_WRAP | FONTLIB_AUTO_CLEAR_TO_EOL | FONTLIB_PRECLEAR_NEWLINE);
    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    int count = 0;
    struct question questions[10];
    struct answer answers[10];
    
    // Set the initial questions and answers
    strcpy(questions[0].myQuestion, "A string in C is an array of ___");
    strcpy(answers[0].myAnswer, "Character");
    
    strcpy(questions[1].myQuestion, "a step-by-step procedure for solving a problem");
    strcpy(answers[1].myAnswer, "Algorithm");
    
    strcpy(questions[2].myQuestion, "finding and correcting errors");
    strcpy(answers[2].myAnswer, "Debug");

    strcpy(questions[3].myQuestion, "provide a computer or other machine with coded instructions for the automatic performance of a particular task");
    strcpy(answers[3].myAnswer, "program");

    strcpy(questions[4].myQuestion, "the programs and other operating information used by a computer.");
    strcpy(answers[4].myAnswer, "software");

    strcpy(questions[5].myQuestion, "identify the most relevant information needed to solve the problem and eliminate or hide the extraneous details");
    strcpy(answers[5].myAnswer, "abstraction");

    strcpy(questions[6].myQuestion, "to repeat");
    strcpy(answers[6].myAnswer, "iterate");

    strcpy(questions[7].myQuestion, "a diagram that shows step-by-step progression through a procedure using connecting lines and a set of symbols");
    strcpy(answers[7].myAnswer, "Flowchart");

    strcpy(questions[8].myQuestion, "a high-level description of the actions of a program or algorithm, using a mixture of English and informal programming language syntax");
    strcpy(answers[8].myAnswer, "Pseudocode");

    strcpy(questions[9].myQuestion, "What is a protocol?");
    strcpy(answers[9].myAnswer, "An agreed-upon set of rules that specify system behavior.");

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
		gfx_FillScreen(0x3);

		if(displayQuestion)
		{
            gfx_Sprite_NoClip(FlashCardSprite, 35, 40);
			PrintCentered(questions[count].myQuestion);
		}
		else
		{
            gfx_Sprite_NoClip(FlashCardSprite, 35, 40);
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
    fontlib_SetCursorPosition((GFX_LCD_WIDTH - gfx_GetStringWidth(string))/2, (GFX_LCD_HEIGHT - 8)/2);
    fontlib_DrawString(string);
}
