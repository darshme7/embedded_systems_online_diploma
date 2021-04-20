
uart.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <Uart_send_string>:
   0:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
   4:	e28db000 	add	fp, sp, #0
   8:	e24dd00c 	sub	sp, sp, #12
   c:	e50b0008 	str	r0, [fp, #-8]
  10:	ea000006 	b	30 <Uart_send_string+0x30>
  14:	e59f3030 	ldr	r3, [pc, #48]	; 4c <Uart_send_string+0x4c>
  18:	e51b2008 	ldr	r2, [fp, #-8]
  1c:	e5d22000 	ldrb	r2, [r2]
  20:	e5832000 	str	r2, [r3]
  24:	e51b3008 	ldr	r3, [fp, #-8]
  28:	e2833001 	add	r3, r3, #1
  2c:	e50b3008 	str	r3, [fp, #-8]
  30:	e51b3008 	ldr	r3, [fp, #-8]
  34:	e5d33000 	ldrb	r3, [r3]
  38:	e3530000 	cmp	r3, #0
  3c:	1afffff4 	bne	14 <Uart_send_string+0x14>
  40:	e28bd000 	add	sp, fp, #0
  44:	e8bd0800 	ldmfd	sp!, {fp}
  48:	e12fff1e 	bx	lr
  4c:	101f1000 	andsne	r1, pc, r0

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000058 	andeq	r0, r0, r8, asr r0
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000002c 	andeq	r0, r0, ip, lsr #32
  10:	00004901 	andeq	r4, r0, r1, lsl #18
  14:	00001700 	andeq	r1, r0, r0, lsl #14
  18:	00000000 	andeq	r0, r0, r0
  1c:	00005000 	andeq	r5, r0, r0
  20:	00000000 	andeq	r0, r0, r0
  24:	38010200 	stmdacc	r1, {r9}
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000105 	andeq	r0, r0, r5, lsl #2
  30:	00500000 	subseq	r0, r0, r0
  34:	00000000 	andeq	r0, r0, r0
  38:	4e010000 	cdpmi	0, 0, cr0, cr1, cr0, {0}
  3c:	03000000 	movweq	r0, #0
  40:	00000000 	andeq	r0, r0, r0
  44:	004e0501 	subeq	r0, lr, r1, lsl #10
  48:	91020000 	mrsls	r0, (UNDEF: 2)
  4c:	04040074 	streq	r0, [r4], #-116	; 0x74
  50:	00000054 	andeq	r0, r0, r4, asr r0
  54:	09080105 	stmdbeq	r8, {r0, r2, r8}
  58:	00000000 	andeq	r0, r0, r0

Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f012e 	ldfeqs	f0, [pc], #-184	; ffffff64 <Uart_send_string+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <Uart_send_string+0xe8382c>
  1c:	0c270b3b 	stceq	11, cr0, [r7], #-236	; 0xffffff14
  20:	01120111 	tsteq	r2, r1, lsl r1
  24:	42970640 	addsmi	r0, r7, #64, 12	; 0x4000000
  28:	0013010c 	andseq	r0, r3, ip, lsl #2
  2c:	00050300 	andeq	r0, r5, r0, lsl #6
  30:	0b3a0e03 	bleq	e83844 <Uart_send_string+0xe83844>
  34:	13490b3b 	movtne	r0, #39739	; 0x9b3b
  38:	00000a02 	andeq	r0, r0, r2, lsl #20
  3c:	0b000f04 	bleq	3c54 <Uart_send_string+0x3c54>
  40:	0013490b 	andseq	r4, r3, fp, lsl #18
  44:	00240500 	eoreq	r0, r4, r0, lsl #10
  48:	0b3e0b0b 	bleq	f82c7c <Uart_send_string+0xf82c7c>
  4c:	00000e03 	andeq	r0, r0, r3, lsl #28
	...

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	047d0002 	ldrbteq	r0, [sp], #-2
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000050 	andeq	r0, r0, r0, asr r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000039 	andeq	r0, r0, r9, lsr r0
   4:	001d0002 	andseq	r0, sp, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	74726175 	ldrbtvc	r6, [r2], #-373	; 0x175
  20:	0000632e 	andeq	r6, r0, lr, lsr #6
  24:	00000000 	andeq	r0, r0, r0
  28:	00000205 	andeq	r0, r0, r5, lsl #4
  2c:	84160000 	ldrhi	r0, [r6], #-0
  30:	0200832f 	andeq	r8, r0, #-1140850688	; 0xbc000000
  34:	86640104 	strbthi	r0, [r4], -r4, lsl #2
  38:	01000802 	tsteq	r0, r2, lsl #16
  3c:	Address 0x0000003c is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	74735f70 	ldrbtvc	r5, [r3], #-3952	; 0xf70
   4:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
   8:	736e7500 	cmnvc	lr, #0, 10
   c:	656e6769 	strbvs	r6, [lr, #-1897]!	; 0x769
  10:	68632064 	stmdavs	r3!, {r2, r5, r6, sp}^
  14:	43007261 	movwmi	r7, #609	; 0x261
  18:	52415c3a 	subpl	r5, r1, #14848	; 0x3a00
  1c:	4f545f4d 	svcmi	0x00545f4d
  20:	48434c4f 	stmdami	r3, {r0, r1, r2, r3, r6, sl, fp, lr}^
  24:	5c4e4941 	mcrrpl	9, 4, r4, lr, cr1
  28:	006e6962 	rsbeq	r6, lr, r2, ror #18
  2c:	20554e47 	subscs	r4, r5, r7, asr #28
  30:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
  34:	00322e37 	eorseq	r2, r2, r7, lsr lr
  38:	74726155 	ldrbtvc	r6, [r2], #-341	; 0x155
  3c:	6e65735f 	mcrvs	3, 3, r7, cr5, cr15, {2}
  40:	74735f64 	ldrbtvc	r5, [r3], #-3940	; 0xf64
  44:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  48:	72617500 	rsbvc	r7, r1, #0, 10
  4c:	00632e74 	rsbeq	r2, r3, r4, ror lr

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4728203a 			; <UNDEFINED> instruction: 0x4728203a
   8:	2029554e 	eorcs	r5, r9, lr, asr #10
   c:	2e372e34 	mrccs	14, 1, r2, cr7, cr4, {1}
  10:	Address 0x00000010 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00003141 	andeq	r3, r0, r1, asr #2
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	00000027 	andeq	r0, r0, r7, lsr #32
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	45363239 	ldrmi	r3, [r6, #-569]!	; 0x239
  18:	00532d4a 	subseq	r2, r3, sl, asr #26
  1c:	01080506 	tsteq	r8, r6, lsl #10
  20:	04120109 	ldreq	r0, [r2], #-265	; 0x109
  24:	01150114 	tsteq	r5, r4, lsl r1
  28:	01180317 	tsteq	r8, r7, lsl r3
  2c:	011a0119 	tsteq	sl, r9, lsl r1
  30:	Address 0x00000030 is out of bounds.


Disassembly of section .debug_frame:

00000000 <.debug_frame>:
   0:	0000000c 	andeq	r0, r0, ip
   4:	ffffffff 			; <UNDEFINED> instruction: 0xffffffff
   8:	7c020001 	stcvc	0, cr0, [r2], {1}
   c:	000d0c0e 	andeq	r0, sp, lr, lsl #24
  10:	00000014 	andeq	r0, r0, r4, lsl r0
	...
  1c:	00000050 	andeq	r0, r0, r0, asr r0
  20:	8b040e42 	blhi	103930 <Uart_send_string+0x103930>
  24:	0b0d4201 	bleq	350830 <Uart_send_string+0x350830>
