#include <ti/getcsc.h>
#include <graphx.h>
#include <compression.h>

#include "gfx/gfx.h"

int main(void)
{
    gfx_Begin();

    gfx_SetPalette(global_palette, sizeof_global_palette, 0);

    zx7_Decompress(gfx_vram, QuizWiz_back_compressed);

    gfx_SetTransparentColor(0);
    gfx_Sprite_NoClip(Flash_cards_button, 80, 13);
    gfx_TransparentSprite_NoClip(Flash_cards_button, 80, 13);

    while (!os_GetCSC());

    gfx_End();

    return 0;
}
