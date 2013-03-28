/*
 * rook_core.h
 *
 * useful functions and such for register manipulation
 *
 * */

/* tribool
 * creates a -1, 0, +1 based on 2 bit flags
 * returns +1 if 'plus' flag is set, 0 if 'minus' flag is set
 * 	    0 if both or neither flags are set */
INLINE bit_tribool(u32 flags, int plus, int minus)
{ return ((flags>>plus&)&1) - ((flags>>minus)&1); }

extern u16 __key_curr = 0, __key_prev = 0;
COLOR *vid_page = vid_mem_back;

