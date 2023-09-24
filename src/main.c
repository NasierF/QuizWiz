#include <ti/getcsc.h>
#include <sys/util.h>
#include <graphx.h>
#include <keypadc.h>

#include <fontlibc.h>

#include "fonts/fonts.h"

void blink_cursor_frame(int* frame_ctr, int* prev_cursor_x, int *prev_cursor_y);

int main(void)
{
    /* Initialize graphics drawing */
    gfx_Begin();
	gfx_SetDrawBuffer();


	/* Clear the screen */
	/* gfx_FillScreen(0x08); */
	gfx_FillScreen(0xff);

	gfx_SetColor(0x0A);
	gfx_Line(0, 20, 5+320, 20);
	gfx_SetColor(0x1A);
	gfx_Line(0, GFX_LCD_HEIGHT - 20, 320, GFX_LCD_HEIGHT - 20);

	/* fontlib_SetFont(test_font, 0); */

	/* /1* First, we'll display centered text in a window *1/ */
	/* /1* Add some vertical padding around our text *1/ */
	/* fontlib_SetLineSpacing(2, 2); */
	/* fontlib_SetWindow(25, 40, 240, 200); */
	/* fontlib_SetCursorPosition(25, 42); */
	/* /1* Set some random (and ugly) colors *1/ */
	/* fontlib_SetColors(0x0, 0xFF); */
	/* /1* This is a crazy combination of settings that you probably don't want to use in any real program, but we're using */
	/* it here for testing purposes. *1/ */
	/* fontlib_SetTransparency(true); */
	/* fontlib_SetNewlineOptions(FONTLIB_ENABLE_AUTO_WRAP | FONTLIB_AUTO_CLEAR_TO_EOL | FONTLIB_PRECLEAR_NEWLINE); */
	/* /1* It's not as generic as Hello, world! *1/ */
	/* /1* fontlib_DrawString("The quick brown fox jumps over the lazy dog kjdkfjdkljflkdjfa;s jksdjflkdjf  jdkfjldskjfkd fkdjlfksjdlkfjakfl df ."); *1/ */
	/* fontlib_DrawString(buffer); */

	const char *chars = "\0\0\0\0\0\0\0\0\0\0\"WRMH\0\0?[VQLG\0\0:ZUPKFC\0 YTOJEB\0\0XSNIDA\0\0\0\0\0\0\0\0";
	const char *lower_chars = "\0\0\0\0\0\0\0\0\0\0\"wrmh\0\0?[vqlg\0\0:zupkfc\0 ytojeb\0\0xsnida\0\0\0\0\0\0\0\0";
	uint8_t key, i = 0;
	char buffer[30];


	int curr_question = 0;
	int num_questions = 20;

	/* gfx_SetTextFGColor(0xff); */

	gfx_SetTextXY(GFX_LCD_WIDTH/2, 10);
	gfx_PrintInt(curr_question, 1);
	gfx_PrintChar('/');
	gfx_PrintInt(num_questions, 1);

	gfx_SetTextFGColor(0x8c);
	gfx_PrintStringXY("TYPE THE TERM", 5, GFX_LCD_HEIGHT-10);

	gfx_SetTextFGColor(0x0);
	gfx_SetTextXY(5, GFX_LCD_HEIGHT/2);
	char* term = "blue";
	gfx_PrintString(term);

	gfx_SetTextXY(5, GFX_LCD_HEIGHT-30);
	gfx_SwapDraw();

	int frame_ctr = 0;
	int prev_cursor_x = -1, prev_cursor_y = -1;

	key = os_GetCSC();
	while(key != sk_Enter && i < sizeof buffer) {
		gfx_BlitScreen();
		// Remove previous cursor
		if (prev_cursor_x != -1 && prev_cursor_y != -1) {
			gfx_SetColor(0xff);
			gfx_Line(prev_cursor_x + 1, prev_cursor_y, prev_cursor_x + 1, prev_cursor_y+8);
		}
		if(chars[key]) {
			buffer[i++] = lower_chars[key];
			gfx_PrintChar(lower_chars[key]);
		}
		blink_cursor_frame(&frame_ctr, &prev_cursor_x, &prev_cursor_y);

		gfx_SwapDraw();

		key = os_GetCSC();
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
