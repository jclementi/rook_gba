#include "rook_memmap.h"
#include "rook_video.h"
#include "rook_types.h"

int main()
{

	/* set the background mode */
	REG_DISPCNT = DCNT_MODE3 | DCNT_BG2;

	/* fill screen */
	m3_fill(RGB15(12, 10, 14));

	/* rectangles */
	m3_rect(200, 8, 208, 262, CLR_RED);

	/* rectangle frame */
	m3_frame(200, 130, 210, 140, CLR_BLACK);
	m3_frame(200, 50, 210, 190, CLR_BLACK);

	/* YO */
	m3_line(30, 130, 90, 50, CLR_BLACK);
	m3_line(30, 50, 60, 90, CLR_BLACK);

	m3_rect(100, 90, 150, 140, CLR_BLACK);	

	while(1)
		;

	return 0;
}
