#include <ti/getcsc.h>
#include <sys/util.h>
#include <graphx.h>
#include <keypadc.h>
#include <string.h>
#include <debug.h>

#include <fontlibc.h>

#include "fonts/fonts.h"

struct question 
{
	char myQuestion[256];
};
struct answer 
{
	char myAnswer[256];
};

void blink_cursor_frame(int* frame_ctr, int* prev_cursor_x, int *prev_cursor_y);

int main(void)
{
	const char *chars = "\0\0\0\0\0\0\0\0\0\0\"WRMH\0\0?[VQLG\0\0:ZUPKFC\0 YTOJEB\0\0XSNIDA\0\0\0\0\0\0\0\0";
	const char *lower_chars = "\0\0\0\0\0\0\0\0\0\0\"wrmh\0\0?[vqlg\0\0:zupkfc\0 ytojeb\0\0xsnida\0\0\0\0\0\0\0\0";
    /* Initialize graphics drawing */
    gfx_Begin();
	gfx_SetDrawBuffer();


	fontlib_SetFont(test_font, 0);
	fontlib_SetLineSpacing(2, 2);
	fontlib_SetWindow(10, 30, 280, GFX_LCD_HEIGHT-50);
	fontlib_SetColors(0x0, 0xFF);
	fontlib_SetTransparency(true);
	fontlib_SetNewlineOptions(FONTLIB_ENABLE_AUTO_WRAP | FONTLIB_AUTO_CLEAR_TO_EOL | FONTLIB_PRECLEAR_NEWLINE);

	int num_questions = 9;
	struct question questions[num_questions];
    struct answer answers[num_questions];

	strcpy(questions[0].myQuestion, "A string in C is an array of ___");
    strcpy(answers[0].myAnswer, "character");
    
    strcpy(questions[1].myQuestion, "a step-by-step procedure for solving a problem");
    strcpy(answers[1].myAnswer, "algorithm");
    
    strcpy(questions[2].myQuestion, "finding and correcting errors");
    strcpy(answers[2].myAnswer, "debug");

    strcpy(questions[3].myQuestion, "provide a computer or other machine with coded instructions for the automatic performance of a particular task");
    strcpy(answers[3].myAnswer, "program");

    strcpy(questions[4].myQuestion, "the programs and other operating information used by a computer.");
    strcpy(answers[4].myAnswer, "software");

    strcpy(questions[5].myQuestion, "identify the most relevant information needed to solve the problem and eliminate or hide the extraneous details");
    strcpy(answers[5].myAnswer, "abstraction");

    strcpy(questions[6].myQuestion, "to repeat");
    strcpy(answers[6].myAnswer, "iterate");

    strcpy(questions[7].myQuestion, "a diagram that shows step-by-step progression through a procedure using connecting lines and a set of symbols");
    strcpy(answers[7].myAnswer, "flowchart");

    strcpy(questions[8].myQuestion, "a high-level description of the actions of a program or algorithm, using a mixture of English and informal programming language syntax");
    strcpy(answers[8].myAnswer, "pseudocode");

	int curr_question = 0;
	char buffer[30];

	for (; curr_question < num_questions; curr_question++) {

		/* Clear the screen */
		gfx_FillScreen(0xff);

		gfx_SetColor(0x8c);
		gfx_FillRectangle(0, 20, GFX_LCD_WIDTH, 4);

		gfx_SetColor(0x0);
		gfx_FillRectangle(0, 20, (int) ((curr_question+1) * GFX_LCD_WIDTH/(1.0 * (num_questions))), 4);

		gfx_SetColor(0x1A);
		gfx_FillRectangle(10, GFX_LCD_HEIGHT - 30, GFX_LCD_WIDTH-20, 4);

		gfx_SetTextXY(GFX_LCD_WIDTH/2, 10);
		gfx_PrintInt(curr_question + 1, 1);
		gfx_PrintChar('/');
		gfx_PrintInt(num_questions, 1);

		gfx_SetTextFGColor(0x8c);
		gfx_PrintStringXY("TYPE THE TERM", 10, GFX_LCD_HEIGHT-20);

		gfx_SetTextFGColor(0x0);
		gfx_SetTextXY(10, GFX_LCD_HEIGHT/2);

		fontlib_SetCursorPosition(10, 30);
		fontlib_DrawString(questions[curr_question].myQuestion);

		gfx_SetTextXY(10, GFX_LCD_HEIGHT-40);
		/* fontlib_SetCursorPosition(10, GFX_LCD_HEIGHT-40); */
		gfx_SwapDraw();

		int frame_ctr = 0;
		int prev_cursor_x = -1, prev_cursor_y = -1;

		uint8_t key, i = 0;

		key = os_GetCSC();
		while(key != sk_Enter && i < sizeof buffer) {
			gfx_BlitScreen();
			// Remove previous cursor
			if (prev_cursor_x != -1 && prev_cursor_y != -1) {
				gfx_SetColor(0xff);
				gfx_Line(prev_cursor_x + 1, prev_cursor_y, prev_cursor_x + 1, prev_cursor_y+8);
			}
			if (chars[key]) {
				buffer[i++] = lower_chars[key];
				gfx_PrintChar(lower_chars[key]);
			}
			else if (key == sk_Clear) {
				gfx_SetTextXY(10, GFX_LCD_HEIGHT-40);
				gfx_SetColor(0xff);
				gfx_FillRectangle(10, GFX_LCD_HEIGHT-40, GFX_LCD_WIDTH-10, 10);
				i=0;
			}
			blink_cursor_frame(&frame_ctr, &prev_cursor_x, &prev_cursor_y);


			gfx_SwapDraw();

			key = os_GetCSC();
		}

		gfx_BlitScreen();

		buffer[i] = '\0';

		// If they're equal
		if (strcmp(buffer, answers[curr_question].myAnswer) == 0) {
			// Show that the answer correct (e.g. check mark green)
			gfx_SetColor(0x06);
			gfx_Line(GFX_LCD_WIDTH-40, GFX_LCD_HEIGHT-40, GFX_LCD_WIDTH-30, GFX_LCD_HEIGHT-35);
			gfx_Line(GFX_LCD_WIDTH-30, GFX_LCD_HEIGHT-35, GFX_LCD_WIDTH-15, GFX_LCD_HEIGHT-50);
		} else {
			// Red X mark
			gfx_SetColor(0xA0);
			gfx_Line(GFX_LCD_WIDTH-30, GFX_LCD_HEIGHT-45, GFX_LCD_WIDTH-20, GFX_LCD_HEIGHT-35);
			gfx_Line(GFX_LCD_WIDTH-30, GFX_LCD_HEIGHT-35, GFX_LCD_WIDTH-20, GFX_LCD_HEIGHT-45);
		}
		gfx_SwapDraw();
		while (!os_GetCSC());

		
	}

    while (!os_GetCSC());


    /* End graphics drawing */
    gfx_End();

    return 0;
}

void blink_cursor_frame(int *frame_ctr, int* prev_cursor_x, int *prev_cursor_y) {
	// Display cursor at new location every other frame
	// if (*frame_ctr % 10) {
	if (*frame_ctr % 30) {
		gfx_SetColor(0x01);
		gfx_Line(gfx_GetTextX() + 1, gfx_GetTextY(), gfx_GetTextX() + 1, gfx_GetTextY()+8);
	}

	*prev_cursor_x = gfx_GetTextX();
	*prev_cursor_y = gfx_GetTextY();
	*frame_ctr = *frame_ctr + 1;
}
