/* 
 * rook_video.h
 *
 * a set of defines and inlines for video work
 *
 * __rook
 * 19-02-13
 */
#include "rook_memmap.h"

// sizes
#define SCREEN_WIDTH	240
#define SCREEN_HEIGHT	160

#define M3_WIDTH	SCREEN_WIDTH
#define M3_HEIGHT	SCREEN_HEIGHT
#define M4_WIDTH	SCREEN_WIDTH
#define M4_HEIGHT	SCREEN_HEIGHT
#define M5_WIDTH	160
#define M5_HEIGHT	128

// colors
#define CLR_BLACK	0x0000
#define CLR_RED		0x001F
#define CLR_LIME	0x03E0
#define CLR_YELLOW	0x03FF
#define CLR_BLUE	0x7C00
#define CLR_MAG		0x7C1F
#define CLR_CYAN	0x7FE0
#define CLR_WHITE	0x7FFF



// builds a (5,5,5) color
INLINE COLOR RGB15(u32 red, u32 green, u32 blue)
{	return red | (green<<5) | (blue<<10);	}

// waits for vblank, will be replaced by inteurrupt sequence later
INLINE void vid_vsync()
{
	while(REG_VCOUNT >= 160); // wait until vdraw
	while(REG_VCOUNT <  160); // wain until vblank
}

// prototypes
INLINE void m3_plot(int x, int y, COLOR clr);
INLINE void m3_line(int x1, int y1, int x2, int y2, COLOR clr);
INLINE void m3_rect(int left, int top, int right, int bottom, COLOR clr);
INLINE void m3_frame(int left, int top, int right, int bottom, COLOR clr);
void bmp16_line(int x1, int y1, int x2, int y2, u32 clr, void *dstBase, 
		u32 dstPitch);
void bmp16_rect(int left, int top, int right, int bottom, u32 clr,
		void *dstBase, u32 dstPitch);
void bmp16_frame(int left, int top, int right, int bottom, u32 clr,
		void *dstBase, u32 dstPitch);

INLINE void m3_plot(int x, int y, COLOR clr)
{	vid_mem[y*SCREEN_WIDTH+x]= clr; 	}

INLINE void m3_line(int x1, int y1, int x2, int y2, COLOR clr)
{	bmp16_line(x1, y1, x2, y2, clr, vid_mem, SCREEN_WIDTH*2); 	}

INLINE void m3_rect(int left, int top, int right, int bottom, COLOR clr)
{	bmp16_rect(left, top, right, bottom, clr, vid_mem, M3_WIDTH*2); }

INLINE void m3_frame(int left, int top, int right, int bottom, COLOR clr)
{	bmp16_frame(left, top, right, bottom, clr, vid_mem, M3_WIDTH*2); }
