/* 
 * rook_memmap.h
 *
 * a list of defines for all commonly accessed areas of memory
 *
 * __rook
 * 19-02-13
 */

#ifndef __MEMMAP__
#define __MEMMAP__

// --- DISPLAY CONTROL ---

// gba contains 96kb of VRAM : 06000000-06007FFF
// 64kb of bgmap and tiles   : 06000000-0600FFFF
// 32kb of obj tiles	     : 06010000-06017FFF

// sections of memory
#define MEM_IO		0x04000000
#define MEM_PAL		0x05000000 // no 8 bit write
#define MEM_VRAM	0x06000000 // no 8 bit write
#define MEM_OAM		0x07000000 // no 8 bit write

// sizes
#define PAL_SIZE	0x00400
#define VRAM_SIZE	0x18000
#define OAM_SIZE	0x00400

#define PAL_BG_SIZE	0x00200
#define PAL_OBJ_SIZE	0x00200
#define VRAM_BG_SIZE	0x10000
#define VRAM_OBJ_SIZE	0x08000
#define M3_SIZE		0x12C00	   
#define M4_SIZE		0x09600
#define M5_SIZE		0x0A000
#define VRAM_PAGE_SIZE	0x0A000

// sub sections
#define REG_BASE	MEM_IO
#define MEM_PAL_OBJ	(MEM_PAL + PAL_BG_SIZE)
#define MEM_VRAM_BACK	(MEM_VRAM + VRAM_PAGE_SIZE)
#define MEM_VRAM_OBJ	(MEM_VRAM + VRAM_BG_SIZE)


// --- STRUCTURED MAP ---

// palette memory
// pal_bg_mem[y] = COLOR (color y)
#define pal_bg_mem	((COLOR*)MEM_PAL)
#define pal_obj_mem	((COLOR*)MEM_PAL_OBJ)

// pal_bg_bank[y] = COLOR[] (bank y)
// pal_bg_bank[y][x] = COLOR (bank y, color x, : color y*16+x)
#define pal_bg_bank	((PALBANK*)MEM_PAL)
#define pal_obj_bank	((PALBANK*)MEM_PAL_OBJ)

// vram
// tile_mem[y] = TILE[] (char block y)
// tile_mem[y][x] = TILE (char block y, tile x)
#define tile_mem	( (CHARBLOCK*)MEM_VRAM)
#define tile8_mem	((CHACBLOCK8*)MEM_VRAM)

#define tile_mem_obj	( (CHARBLOCK*)MEM_VRAM_OBJ)
#define tile8_mem_obj	((CHARBLOCK8*)MEM_VRAM_OBJ)

// vid_mem[a] = COLOR
#define vid_mem		((COLOR*)MEM_VRAM)

// oam
// oatr_mem[a] = OBJ_ATTR (oam entry a)
#define oam_mem		((OBJ_ATTR*)MEM_OAM)
#define obj_mem		((OBJ_ATTR*)MEM_OAM)
#define obj_aff_mem	((OBJ_AFFINE*)MEM_OAM)


// --- REGISTERS AND CONTROL DEFINES ---

#define REG_DISPCNT	*(vu32*)(REG_BASE+0x0000) // disp control
#define REG_DISPSTAT	*(vu16*)(REG_BASE+0x0004) // dish interrupt
#define REG_VCOUNT	*(vu16*)(REG_BASE+0x0006) // vertical cnt

// display control register, control defines
#define DCNT_MODE0		0x0000 // set to 0: video mode 0
#define DCNT_MODE1		0x0001 // bg 0-1: reg; bg 2: affine
#define DCNT_MODE2		0x0002 // bg 2-2: affine
#define DCNT_MODE3		0x0003 // bg 2: 240x160 16 bpp
#define DCNT_MODE4		0x0004 // bg 2: 240x160  8 bpp
#define DCNT_MODE5		0x0005 // bg 2: 160x128 16 bpp
#define DCNT_GBC		0x0008 // gbc indicator (RO)
#define DCNT_PAGE		0x0010 // frame select for m4, m5
#define DCNT_OAM_HBL		0x0020 // allow OAM updates in hblank
#define DCNT_OBJ_1D		0x0040 // 1=1d
#define DCNT_OBJ_2D		0x0000 // 0=2d
#define DCNT_BLANK		0x0080 // force screen blank
#define DCNT_BG0		0x0100 // enable bg0
#define DCNT_BG1		0x0200 // enable bg1
#define DCNT_BG2		0x0400 // enable bg2
#define DCNT_BG3		0x0800 // enable bg3
#define DCNT_OBJ		0x1000 // enable obj layer
#define DCNT_WIN0		0x2000 // enable window 0
#define DCNT_WIN1		0x4000 // enable window 1
#define DCNT_WINOBJ		0x8000 // enable object window

#define DCNT_MODE_MASK		0x0007
#define DCNT_MODE_SHIFT		0x0000
#define DCNT_MODE(n)		((n)<<DCNT_MODE_SHIFT)

#define DCNT_LAYER_MASK		0x1F00
#define DCNT_LAYER_SHIFT	8
#define DCNT_LAYER(n)		((n)<<DCNT_LAYER_SHIFT)

#define DCNT_WIN_MASK		0xE000
#define DCNT_WIN_SHIFT		13
#define DCNT_WIN(n)		((n)<<DCNT_WIN_SHIFT)

// page flipping
#define DCNT_PG			0x0010 // 00000000.00010000
// layers - 0=off 1=on
#define DCNT_BG0		0x0100 // 00000001.00000000
#define DCNT_BG1		0x0200 // 00000010.00000000
#define DCNT_BG2		0x0400 // 00000100.00000000
#define DCNT_BG3		0x0800 // 00001000.00000000
#define DCNT_OBJ		0x1000 // 00010000.00000000

// display status register
#define DSTAT_IN_VBL		0x0001 // now in vblank
#define DSTAT_IN_HBL		0x0002 // now in hblank
#define DSTAT_IN_VCT		0x0004 // now in set vcount
#define DSTAT_VBL_IRQ		0x0008 // enable vblank irq
#define DSTAT_HBL_IRQ		0x0010 // enable hblank irq
#define DSTAT_VCT_IRQ		0x0020 // enable vcount irq

#define DSTAT_VCT_MASK		0xFF00
#define DSTAT_VCT_SHIFT		0
#define DSTAT_VCT(n)		((n)<<DSTAT_VCT_SHIFT)


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


// --- OBJECT ATTRIBUTE MEM ---

// attr 0
#define ATTR0_REG		0x0000 // regular object
#define ATTR0_AFF		0x0100 // affine obj
#define ATTR0_HIDE		0x0200 // inactive obj; for reg objects
#define ATTR0_AFF_DBL		0x0200 // double size; for aff objects
#define ATTR0_STRANSP		0x0400 // semi-transparent
#define ATTR0_OBJ_WIN		0x0800 // use for object window
#define ATTR0_MOSAIC		0x1000 // enable mosaic
#define ATTR0_4BPP		0x0000 // 16 colors, 16 palettes
#define ATTR0_8BPP		0x2000 // 256 colors, 1 palette
#define ATTR0_SQUARE		0x0000 // square shape, NxN
#define ATTR0_WIDE		0x4000 // wide shape, 2NxN 
#define ATTR0_TALL		0x8000 // tall shape, Nx2N

#define ATTR0_Y_MASK		0x00FF // bits 0-7 control y-coordinate
#define ATTR0_Y_SHIFT		0
#define ATTR0_Y(n)		((n)<<ATTR0_Y_SHIFT)

#define ATTR0_MODE_MASK		0x0300 // regular-inactive, affine-double
#define ATTR0_MODE_SHIFT	8
#define ATTR0_MODE(n)		((n)<<ATTR0_MODE_SHIFT)

#define ATTR0_SHAPE_MASK	0xC000 
#define ATTR0_SHAPE_SHIFT	14
#define ATTR0_SHAPE(n)		((n)<<ATTR0_SHAPE_SHIFT)

// attr 1
#define ATTR1_HFLIP		0x1000 // horizontal flip
#define ATTR1_VFLIP		0x2000 // vertical flip
				       // sq     wide   tall
#define ATTR1_SIZE_8		0x0000 // 8x8    8x16   16x8
#define ATTR1_SIZE_16		0x4000 // 16x16  32x8   8x32
#define ATTR1_SIZE_32		0x8000 // 32x32  32x16  16x32
#define ATTR1_SIZE_64		0xC000 // 64x64  64x32  32x64

#define ATTR1_X_MASK		0x01FF // bits 0-8 control x-coodinate
#define ATTR1_X_SHIFT		0
#define ATTR1_X(n)		((n)<<ATTR1_X_SHIFT)

#define ATTR1_AFF_MASK		0x3000
#define ATTR1_AFF_SHIFT		12
#define ATTR1_AFF(n)		((n)<<ATTR1_AFF_SHIFT)

#define ATTR1_SIZE_MASK		0xC000
#define ATTR1_SIZE_SHIFT	14
#define ATTR1_SIZE(n)		((n)<<ATTR1_SIZE_SHIFT)

// attr 2
#define ATTR2_ID_MASK		0x03FF // first 9 bits are tile index
#define ATTR2_ID_SHIFT		0x0000
#define ATTR2_ID(n)		((n)<<ATTR2_ID_SHIFT)

#define ATTR2_PRIO_MASK		0x0C00
#define ATTR2_PRIO_SHIFT	10
#define ATTR2_PRIO(n)		((n)<<ATTR2_PRIO_SHIFT)

#define ATTR2_PALBANK_MASK	0xF000 // high 4 bits are palette bank index
#define ATTR2_PALBANK_SHIFT	12
#define ATTR2_PALBANK(n)	((n)<<ATTR2_PALBANK_SHIFT)


#endif // __MEMMAP__
