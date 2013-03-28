/* 
 * rook_memmap.h
 *
 * a list of defines for all commonly accessed areas of memory
 *
 * __rook
 * 19-02-13
 */


// --- DISPLAY CONTROL ---

// gba contains 96kb of VRAM : 06000000-06007FFF
// 64kb of bgmap and tiles   : 06000000-0600FFFF
// 32kb of obj tiles	     : 06010000-06017FFF
#define MEM_IO		0x04000000
#define MEM_PAL		0x05000000 // no 8 bit write
#define MEM_VRAM	0x06000000 // no 8 bit write

#define PAL_SIZE	0x00400
#define VRAM_SIZE	0x18000

#define M3_SIZE		0x12C00	   
#define M4_SIZE		0x09600
#define M5_SIZE		0x0A000
#define VRAM_PAGE_SIZE	0x0A000	

#define MEM_VRAM_BACK	(MEM_VRAM + VRAM_PAGE_SIZE)


// memory address to palatte memory cast as a pointer to color
#define pal_bg_mem	((COLOR*)MEM_PAL)
#define vid_mem		((COLOR*)MEM_VRAM)

#define REG_BASE	MEM_IO
#define REG_DISPCNT	*(vu32*)(REG_BASE+0x0000) // disp control
#define REG_DISPSTAT	*(vu16*)(REG_BASE+0x0004) // dish interrupt
#define REG_VCOUNT	*(vu16*)(REG_BASE+0x0006) // vertical cnt

// display control register, some control defines
#define DCNT_MODE0		0x0000 // set to 0: video mode 0
#define DCNT_MODE1		0x0001 // bg 0-1: reg; bg 2: affine
#define DCNT_MODE2		0x0002 // bg 2-2: affine
#define DCNT_MODE3		0x0003 // bg 2: 240x160 16 bpp
#define DCNT_MODE4		0x0004 // bg 2: 240x160  8 bpp
#define DCNT_MODE5		0x0005 // bg 2: 160x128 16 bpp
#define DCNT_GBC		0x0008 // gbc indicator (RO)
#define DCNT_PAGE		0x0010 // frame select for m4, m5
#define DCNT_OAM_HBL		0x0020 // allow OAM updates in hblank
#define DCNT_OBJ_1D		0x0040 // 0=2d; 1=1d
#define DCNT_BLANK		0x0080 // force screen blank
#define DCNT_BG0		0x0100 // enable bg0
#define DCNT_BG1		0x0200 // enable bg1
#define DCNT_BG2		0x0400 // enable bg2
#define DCNT_BG3		0x0800 // enable bg3
#define DCNT_OBJ		0x1000 // enable obj layer
#define DCNT_WIN0		0x2000 // enable window 0
#define DCNT_WIN1		0x4000 // enable window 1
#define DCNT_WINOBJ		0x8000 // enable object window

// page flipping
#define DCNT_PG			0x0010 // 00000000.00001000
// layers - 0=off 1=on
#define DCNT_BG0		0x0100 // 00000001.00000000
#define DCNT_BG1		0x0200 // 00000010.00000000
#define DCNT_BG2		0x0400 // 00000100.00000000
#define DCNT_BG3		0x0800 // 00001000.00000000
#define DCNT_OBJ		0x1000 // 00010000.00000000


// --- KEY INPUT --- 
#define REG_KEYINPUT	*(vu16*)(REG_BASE+0x0130) // key status

#define KEY_MASK		0x03FF // key bits are clear when depressed

#define KEY_A			0x0001 // A button
#define KEY_B			0x0002 // B button
#define KEY_SELECT		0x0004 // Select button
#define KEY_START		0x0008 // Start button
#define KEY_RIGHT		0x0010 // D-pad Right
#define KEY_LEFT		0x0020 // D-pad Left
#define KEY_UP			0x0040 // D-pad Up
#define KEY_DOWN		0x0080 // D-pad Down
#define KEY_R			0x0100 // Right Shoulder button
#define KEY_L			0x0200 // Left Shoulder button

#define KEY_ANY			0x03FF // any key
#define KEY_DIR			0x00F0 // any direction
#define KEY_SHOULDER		0x0300 // L or R
#define KEY_RESET		0x000F // A+B+SELECT+START

