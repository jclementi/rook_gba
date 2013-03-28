/* 
 * rook_memmap.h
 *
 * a list of defines for all commonly accessed areas of memory
 *
 * __rook
 * 19-02-13
 */


// gba contains 96kb of VRAM : 06000000-06007FFF
// 64kb of bgmap and tiles   : 06000000-0600FFFF
// 32kb of obj tiles	     : 06010000-06017FFF
#define MEM_IO		0x04000000
#define MEM_PAL		0x05000000 // no 8 bit write
#define MEM_VRAM	0x06000000 // no 8 bit write

#define PAL_SIZE	0x00400
#define VRAM_SIZE	0x18000

#define M3_SIZE		0x12C00	   

// memory address to palatte memory cast as a pointer to color
#define pal_bg_mem	((COLOR*)MEM_PAL)
#define vid_mem		((COLOR*)MEM_VRAM)

#define REG_BASE	MEM_IO
#define REG_DISPCNT	*(vu32*)(REG_BASE+0x0000) // disp control
#define REG_DISPSTAT	*(vu16*)(REG_BASE+0x0004) // dish interrupt
#define REG_VCOUNT	*(vu16*)(REG_BASE+0x0006) // vertical cnt

// display control register, some control defines
#define REG_DISPCNT	*((volatile u32*)(MEM_IO+0x0000))

#define DCNT_MODE0		0x0000 // set to 0: video mode 0
#define DCNT_MODE1		0x0001 // 00000000.00000001
#define DCNT_MODE2		0x0002 // 00000000.00000010
#define DCNT_MODE3		0x0003 // ...
#define DCNT_MODE4		0x0004
#define DCNT_MODE5		0x0005
//	DCNT_MODE6 and MODE7 do not exist
// page flipping
#define DCNT_PG			0x0010 // 00000000.00001000
// layers - 0=off 1=on
#define DCNT_BG0		0x0100 // 00000001.00000000
#define DCNT_BG1		0x0200 // 00000010.00000000
#define DCNT_BG2		0x0400 // 00000100.00000000
#define DCNT_BG3		0x0800 // 00001000.00000000
#define DCNT_OBJ		0x1000 // 00010000.00000000

