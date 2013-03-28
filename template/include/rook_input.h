/*
 * rook_input.h
 *
 * defines and inlines for working with keys
 *
 * */

#ifndef __INPUT__
#define __INPUT__

#include "rook_core.h"

typedef enum KEY_INDEX
{
	KI_A = 0, 	KI_B,		KI_SELECT,	KI_START,
	KI_RIGHT,	KI_LEFT,	KI_UP,		KI_DOWN,
	KI_R,		KI_L,		KI_MAX	
} KEY_INDEX

// prototypes for inlines
INLINE void key_poll();
INLINE u32 key_curr_state();
INLINE u32 key_prev_state();

INLINE u32 key_is_down(u32 key);
INLINE u32 key_is_up(u32 key);
INLINE u32 key_was_down(u32 key);
INLINE u32 key_was_up(u32 key);

INLINE u32 key_transit(u32 key);	// any key change?
INLINE u32 key_held(u32 key);		// any key held?
INLINE u32 key_hit(u32 key);		// keys depressed this frame
INLINE u32 key_released(u32 key);	// keys released this frame

// tribools
INLINE int key_tri_hori();
INLINE int key_tri_vert();

// inline definitions
INLINE void key_poll()
{ __key_prev = __key_curr; __key_curr = ~(REG_KEYINPUT & KEY_MASK); }

INLINE u32 key_curr_state() { return __key_curr; }
INLINE u32 key_prev_state() { return __key_prev; }

INLINE u32 key_is_down(u32 key) { return __key_curr & key; }
INLINE u32 key_is_up(u32 key) { return ~__key_curr & key; }
INLINE u32 key_was_down(u32 key) { return __key_prev & key; }
INLINE u32 key_was_up(u32 key) { return ~__key_prev & key; }

INLINE u32 key_transit(u32 key) { return (__key_prev ^ __key_curr) & key; }
INLINE u32 key_held(u32 key) { return (__key_prev & __key_curr) & key; }
:help
INLINE u32 key_released(u32 key) { return (__key_prev & ~__key_curr) & key; }

INLINE int key_tri_hori() 
{ 	return bit_tribool(__key_curr, KI_RIGHT, KI_LEFT); 	}

INLINE int key_tri_vert()
{	return bit_tribool(__key_curr, KI_UP, KI_DOWN);		}


#endif // __INPUT__
