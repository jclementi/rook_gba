#include "rook_memmap.h"
#include "rook_video.h"
#include "rook_types.h"

// draw a line on a 16bpp canvas
void bmp_line(int x1, int y1, int x2, int y2, u32 clr,
		void *dstBase, uint dstPitch)
{
	int ii, dx, dy, xstep, ystep, dd;
	u16 *dst = (u16*)(dstBase + y1*dstPitch + x1*2);
	dstPitch /= 2;

	// normalize
	if (x1 > x2) {
		xstep = -1;
		dx = x1 - x2;
	} else {
		xstep = +1;
		dx = x2 - x1;
	}

	if (y1 > y2) {
		ystep = -dstPitch;
		dy = y1 - y2;
	} else {
		ystep = +dstPitch;
		dy = y2 - y1;
	}

	// drawing
	if (dy == 0) {		// horizontal
		for (ii = 0; ii <= dx; ii++) 
			dst[ii*xstep]= clr;
	} else if (dx == 0) { 	// vertical
		for (ii = 0; ii <= dy; ii++)
			dst[ii*ystep]= clr;
	} else if (dx >= dy) { 	// diagonal, slope <= 1
		dd = 2*dy - dx;
		for (ii = 0; ii <= dx; ii++) {
			*dst = clr;
			if (dd >= 0) {
				dd -= 2*dx;
				dst += ystep;
			}

			dd += 2*dy;
			dst += xstep;
		}
	} else { 		// diagonal, slope > 1
		dd = 2*dx - dy;
		for (ii = 0; ii <= dy; ii++) {
			*dst = clr;
			if (dd >= 0) {
				dd -= 2*dy;
				dst += xstep;
			}

			dd += 2*dx;
			dst += ystep;
		}
	}
}

// draw a rectangle on a 16bpp canvas
void bmp16_rect(int left, int top, int right, int bottom, u32 clr,
		void *dstBase, uint dstPitch)
{
	int ix, iy;

	uint width = right-left, height = bottom-top;
	u16 *dst = (u16*)(dstBase+top*dstPitch + left*2);
	dstPitch /= 2;

	// draw
	for (iy = 0; iy < height; iy++)
		for (ix = 0; ix < width; ix++)
			dst[iy*dstPitch + ix] = clr;
}

// draw a frame on a 16bpp canvas
void bmp_frame(int left, int top, int right, int bottom, u32 clr,
		void *dstBase, uint dstPitch)
{
	// frame is rb exclusive
	right--;
	bottom--;

	bmp16_line(left, top, right, top, clr, dstBase, dstPitch);
	bmp16_line(left, bottom, right, botttom, clr, dstBase, dstPitch);

	bmp16_line(left, top, left, bottom, clr, dstBase, dstPitch);
	bmp16_line(right, top, right, bottom, clr, dstBase, dstPitch);
}

// fill mode 3 background with a color
void m3_fill(COLOR clr)
{
	int ii;
	u32 *dst = (u32*)vid_mem;
	u32 wd (clr<<16) | clr;

	for (ii = 0; ii < M3_SIZE / 4; ii++)
		*dst++ = wd;
}
