/*
 * memset - fill memory with a constant
 *
 * Copyright (c) 2010-2021, Arm Limited.
 * SPDX-License-Identifier: MIT OR Apache-2.0 WITH LLVM-exception
 */

/*
   Written by Dave Gilbert <david.gilbert@linaro.org>

   This memset routine is optimised on a Cortex-A9 and should work on
   all ARMv7 processors.

 */

	.syntax unified
	.arch armv7-a

@ 2011-08-30 david.gilbert@linaro.org
@    Extracted from local git 2f11b436

@ this lets us check a flag in a 00/ff byte easily in either endianness
#ifdef __ARMEB__
#define CHARTSTMASK(c) 1<<(31-(c*8))
#else
#define CHARTSTMASK(c) 1<<(c*8)
#endif
	.thumb

@ ---------------------------------------------------------------------------
	.thumb_func
	.align 2
	.p2align 4,,15
	.global lmu_memset_arm
	.type lmu_memset_arm,%function
lmu_memset_arm:
	@ r0 = address
	@ r1 = character
	@ r2 = count
	@ returns original address in r0

	mov	r3, r0		@ Leave r0 alone
	cbz	r2, 10f		@ Exit if 0 length

	tst	r0, #7
	beq	2f		@ Already aligned

	@ Ok, so we're misaligned here
1:
	strb	r1, [r3], #1
	subs	r2,r2,#1
	tst	r3, #7
	cbz	r2, 10f		@ Exit if we hit the end
	bne	1b		@ go round again if still misaligned

2:
	@ OK, so we're aligned
	push	{r4,r5,r6,r7}
	bics	r4, r2, #15	@ if less than 16 bytes then need to finish it off
	beq	5f

3:
	@ POSIX says that ch is cast to an unsigned char.  A uxtb is one
	@ byte and takes two cycles, where an AND is four bytes but one
	@ cycle.
	and	r1, #0xFF
	orr	r1, r1, r1, lsl#8	@ Same character into all bytes
	orr	r1, r1, r1, lsl#16
	mov	r5,r1
	mov	r6,r1
	mov	r7,r1

4:
	subs	r4,r4,#16
	stmia	r3!,{r1,r5,r6,r7}
	bne	4b
	and	r2,r2,#15

	@ At this point we're still aligned and we have upto align-1 bytes left to right
	@ we can avoid some of the byte-at-a time now by testing for some big chunks
	tst	r2,#8
	itt	ne
	subne	r2,r2,#8
	stmiane	r3!,{r1,r5}

5:
	pop	{r4,r5,r6,r7}
	cbz	r2, 10f

	@ Got to do any last < alignment bytes
6:
	subs	r2,r2,#1
	strb	r1,[r3],#1
	bne	6b

10:
	bx	lr		@ goodbye
	.size	lmu_memset_arm, . - lmu_memset_arm
