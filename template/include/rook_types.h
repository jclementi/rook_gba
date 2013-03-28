/*
 * a set of typedefs for all of the commonly used datatypes
 * 
 * the usage of datatypes is admittedly liberal, but in light of the
 * absolutely massive amount of data that's passed as straight bits 
 * and hex, the more infastructure that I can build, the clearer everything
 * will be in the end. And that's well worth the up front cost of these
 * keystrokes
 *
 * __rook
 * 19-02-13
 */

#ifndef __TYPES__
#define __TYPES__

// --- GCC ATTRIBUTES ---
// alignment boundary
#define ALIGN(_n) 	__attribute__((aligned(_n)))
#define ALIGN4		__attribute__((aligned(4)))

// pack aggregate members
#define PACKED		__attribute__((packed))


// --- TYPES ---

typedef unsigned char	u8,	byte;
typedef unsigned short	u16,	hword;
typedef unsigned int	u32,	word;
typedef unsigned long long u64;

typedef signed char	s8;
typedef signed short	s16;
typedef signed int	s32;
typedef signed long long s64;

// volatiles to prevent constant-based optimizations in compiler
typedef volatile u8  vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef volatile s8  vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

// consts for parameters
typedef const u8  cu8;
typedef const u16 cu16;
typedef const u32 cu32;
typedef const u64 cu64;

typedef const s8  cs8;
typedef const s16 cs16;
typedef const s32 cs32;
typedef const s64 cs64;




typedef u16 COLOR;

#define INLINE static inline
