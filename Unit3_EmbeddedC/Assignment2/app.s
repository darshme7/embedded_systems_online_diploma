
app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <Uart_send_string>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	4d3a6874 	ldcmi	8, cr6, [sl, #-464]!	; 0xfffffe30
  10:	6174736f 	cmnvs	r4, pc, ror #6
  14:	4d206166 	stfmis	f6, [r0, #-408]!	; 0xfffffe68
  18:	6f6d6861 	svcvs	0x006d6861
  1c:	00006475 	andeq	r6, r0, r5, ror r4
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000067 	andeq	r0, r0, r7, rrx
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000002c 	andeq	r0, r0, ip, lsr #32
  10:	00003801 	andeq	r3, r0, r1, lsl #16
  14:	00001700 	andeq	r1, r0, r0, lsl #14
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001800 	andeq	r1, r0, r0, lsl #16
  20:	00000000 	andeq	r0, r0, r0
  24:	4c010200 	sfmmi	f0, 4, [r1], {-0}
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000005 	andeq	r0, r0, r5
  30:	00001800 	andeq	r1, r0, r0, lsl #16
  34:	00000000 	andeq	r0, r0, r0
  38:	51030100 	mrspl	r0, (UNDEF: 19)
  3c:	4a000000 	bmi	44 <.debug_info+0x44>
  40:	04000000 	streq	r0, [r0], #-0
  44:	0000004a 	andeq	r0, r0, sl, asr #32
  48:	04050063 	streq	r0, [r5], #-99	; 0x63
  4c:	00000e07 	andeq	r0, r0, r7, lsl #28
  50:	08010500 	stmdaeq	r1, {r8, sl}
  54:	00000000 	andeq	r0, r0, r0
  58:	00003e06 	andeq	r3, r0, r6, lsl #28
  5c:	3a030100 	bcc	c0464 <main+0xc0464>
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	00000305 	andeq	r0, r0, r5, lsl #6
  68:	Address 0x00000068 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f002e 	ldceq	0, cr0, [pc], #-184	; ffffff64 <main+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <main+0xe8382c>
  1c:	01110b3b 	tsteq	r1, fp, lsr fp
  20:	06400112 			; <UNDEFINED> instruction: 0x06400112
  24:	000c4296 	muleq	ip, r6, r2
  28:	01010300 	mrseq	r0, SP_irq
  2c:	13011349 	movwne	r1, #4937	; 0x1349
  30:	21040000 	mrscs	r0, (UNDEF: 4)
  34:	2f134900 	svccs	0x00134900
  38:	0500000b 	streq	r0, [r0, #-11]
  3c:	0b0b0024 	bleq	2c00d4 <main+0x2c00d4>
  40:	0e030b3e 	vmoveq.16	d3[0], r0
  44:	34060000 	strcc	r0, [r6], #-0
  48:	3a0e0300 	bcc	380c50 <main+0x380c50>
  4c:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  50:	020c3f13 	andeq	r3, ip, #19, 30	; 0x4c
  54:	0000000a 	andeq	r0, r0, sl

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000018 	andeq	r0, r0, r8, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4c1600 	blmi	1305834 <main+0x1305834>
  30:	01000402 	tsteq	r0, r2, lsl #8
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	69730072 	ldmdbvs	r3!, {r1, r4, r5, r6}^
  10:	7974657a 	ldmdbvc	r4!, {r1, r3, r4, r5, r6, r8, sl, sp, lr}^
  14:	43006570 	movwmi	r6, #1392	; 0x570
  18:	52415c3a 	subpl	r5, r1, #14848	; 0x3a00
  1c:	4f545f4d 	svcmi	0x00545f4d
  20:	48434c4f 	stmdami	r3, {r0, r1, r2, r3, r6, sl, fp, lr}^
  24:	5c4e4941 	mcrrpl	9, 4, r4, lr, cr1
  28:	006e6962 	rsbeq	r6, lr, r2, ror #18
  2c:	20554e47 	subscs	r4, r5, r7, asr #28
  30:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
  34:	00322e37 	eorseq	r2, r2, r7, lsr lr
  38:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  3c:	74730063 	ldrbtvc	r0, [r3], #-99	; 0x63
  40:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  44:	6675625f 			; <UNDEFINED> instruction: 0x6675625f
  48:	00726566 	rsbseq	r6, r2, r6, ror #10
  4c:	6e69616d 	powvsez	f6, f1, #5.0
	...

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
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22

app.o:     file format elf32-littlearm


Disassembly of section .text:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e59f0004 	ldr	r0, [pc, #4]	; 14 <main+0x14>
   c:	ebfffffe 	bl	0 <Uart_send_string>
  10:	e8bd8800 	pop	{fp, pc}
  14:	00000000 	andeq	r0, r0, r0

Disassembly of section .data:

00000000 <string_buffer>:
   0:	7261656c 	rsbvc	r6, r1, #108, 10	; 0x1b000000
   4:	6e692d6e 	cdpvs	13, 6, cr2, cr9, cr14, {3}
   8:	7065642d 	rsbvc	r6, r5, sp, lsr #8
   c:	4d3a6874 	ldcmi	8, cr6, [sl, #-464]!	; 0xfffffe30
  10:	6174736f 	cmnvs	r4, pc, ror #6
  14:	4d206166 	stfmis	f6, [r0, #-408]!	; 0xfffffe68
  18:	6f6d6861 	svcvs	0x006d6861
  1c:	00006475 	andeq	r6, r0, r5, ror r4
	...

Disassembly of section .debug_info:

00000000 <.debug_info>:
   0:	00000067 	andeq	r0, r0, r7, rrx
   4:	00000002 	andeq	r0, r0, r2
   8:	01040000 	mrseq	r0, (UNDEF: 4)
   c:	0000002c 	andeq	r0, r0, ip, lsr #32
  10:	00003801 	andeq	r3, r0, r1, lsl #16
  14:	00001700 	andeq	r1, r0, r0, lsl #14
  18:	00000000 	andeq	r0, r0, r0
  1c:	00001800 	andeq	r1, r0, r0, lsl #16
  20:	00000000 	andeq	r0, r0, r0
  24:	4c010200 	sfmmi	f0, 4, [r1], {-0}
  28:	01000000 	mrseq	r0, (UNDEF: 0)
  2c:	00000005 	andeq	r0, r0, r5
  30:	00001800 	andeq	r1, r0, r0, lsl #16
  34:	00000000 	andeq	r0, r0, r0
  38:	51030100 	mrspl	r0, (UNDEF: 19)
  3c:	4a000000 	bmi	44 <.debug_info+0x44>
  40:	04000000 	streq	r0, [r0], #-0
  44:	0000004a 	andeq	r0, r0, sl, asr #32
  48:	04050063 	streq	r0, [r5], #-99	; 0x63
  4c:	00000e07 	andeq	r0, r0, r7, lsl #28
  50:	08010500 	stmdaeq	r1, {r8, sl}
  54:	00000000 	andeq	r0, r0, r0
  58:	00003e06 	andeq	r3, r0, r6, lsl #28
  5c:	3a030100 	bcc	c0464 <main+0xc0464>
  60:	01000000 	mrseq	r0, (UNDEF: 0)
  64:	00000305 	andeq	r0, r0, r5, lsl #6
  68:	Address 0x00000068 is out of bounds.


Disassembly of section .debug_abbrev:

00000000 <.debug_abbrev>:
   0:	25011101 	strcs	r1, [r1, #-257]	; 0x101
   4:	030b130e 	movweq	r1, #45838	; 0xb30e
   8:	110e1b0e 	tstne	lr, lr, lsl #22
   c:	10011201 	andne	r1, r1, r1, lsl #4
  10:	02000006 	andeq	r0, r0, #6
  14:	0c3f002e 	ldceq	0, cr0, [pc], #-184	; ffffff64 <main+0xffffff64>
  18:	0b3a0e03 	bleq	e8382c <main+0xe8382c>
  1c:	01110b3b 	tsteq	r1, fp, lsr fp
  20:	06400112 			; <UNDEFINED> instruction: 0x06400112
  24:	000c4296 	muleq	ip, r6, r2
  28:	01010300 	mrseq	r0, SP_irq
  2c:	13011349 	movwne	r1, #4937	; 0x1349
  30:	21040000 	mrscs	r0, (UNDEF: 4)
  34:	2f134900 	svccs	0x00134900
  38:	0500000b 	streq	r0, [r0, #-11]
  3c:	0b0b0024 	bleq	2c00d4 <main+0x2c00d4>
  40:	0e030b3e 	vmoveq.16	d3[0], r0
  44:	34060000 	strcc	r0, [r6], #-0
  48:	3a0e0300 	bcc	380c50 <main+0x380c50>
  4c:	490b3b0b 	stmdbmi	fp, {r0, r1, r3, r8, r9, fp, ip, sp}
  50:	020c3f13 	andeq	r3, ip, #19, 30	; 0x4c
  54:	0000000a 	andeq	r0, r0, sl

Disassembly of section .debug_loc:

00000000 <.debug_loc>:
   0:	00000000 	andeq	r0, r0, r0
   4:	00000004 	andeq	r0, r0, r4
   8:	007d0002 	rsbseq	r0, sp, r2
   c:	00000004 	andeq	r0, r0, r4
  10:	00000008 	andeq	r0, r0, r8
  14:	087d0002 	ldmdaeq	sp!, {r1}^
  18:	00000008 	andeq	r0, r0, r8
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	047b0002 	ldrbteq	r0, [fp], #-2
	...

Disassembly of section .debug_aranges:

00000000 <.debug_aranges>:
   0:	0000001c 	andeq	r0, r0, ip, lsl r0
   4:	00000002 	andeq	r0, r0, r2
   8:	00040000 	andeq	r0, r4, r0
	...
  14:	00000018 	andeq	r0, r0, r8, lsl r0
	...

Disassembly of section .debug_line:

00000000 <.debug_line>:
   0:	00000031 	andeq	r0, r0, r1, lsr r0
   4:	001c0002 	andseq	r0, ip, r2
   8:	01020000 	mrseq	r0, (UNDEF: 2)
   c:	000d0efb 	strdeq	r0, [sp], -fp
  10:	01010101 	tsteq	r1, r1, lsl #2
  14:	01000000 	mrseq	r0, (UNDEF: 0)
  18:	00010000 	andeq	r0, r1, r0
  1c:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  20:	00000063 	andeq	r0, r0, r3, rrx
  24:	05000000 	streq	r0, [r0, #-0]
  28:	00000002 	andeq	r0, r0, r2
  2c:	4b4c1600 	blmi	1305834 <main+0x1305834>
  30:	01000402 	tsteq	r0, r2, lsl #8
  34:	Address 0x00000034 is out of bounds.


Disassembly of section .debug_str:

00000000 <.debug_str>:
   0:	69736e75 	ldmdbvs	r3!, {r0, r2, r4, r5, r6, r9, sl, fp, sp, lr}^
   4:	64656e67 	strbtvs	r6, [r5], #-3687	; 0xe67
   8:	61686320 	cmnvs	r8, r0, lsr #6
   c:	69730072 	ldmdbvs	r3!, {r1, r4, r5, r6}^
  10:	7974657a 	ldmdbvc	r4!, {r1, r3, r4, r5, r6, r8, sl, sp, lr}^
  14:	43006570 	movwmi	r6, #1392	; 0x570
  18:	52415c3a 	subpl	r5, r1, #14848	; 0x3a00
  1c:	4f545f4d 	svcmi	0x00545f4d
  20:	48434c4f 	stmdami	r3, {r0, r1, r2, r3, r6, sl, fp, lr}^
  24:	5c4e4941 	mcrrpl	9, 4, r4, lr, cr1
  28:	006e6962 	rsbeq	r6, lr, r2, ror #18
  2c:	20554e47 	subscs	r4, r5, r7, asr #28
  30:	2e342043 	cdpcs	0, 3, cr2, cr4, cr3, {2}
  34:	00322e37 	eorseq	r2, r2, r7, lsr lr
  38:	2e707061 	cdpcs	0, 7, cr7, cr0, cr1, {3}
  3c:	74730063 	ldrbtvc	r0, [r3], #-99	; 0x63
  40:	676e6972 			; <UNDEFINED> instruction: 0x676e6972
  44:	6675625f 			; <UNDEFINED> instruction: 0x6675625f
  48:	00726566 	rsbseq	r6, r2, r6, ror #10
  4c:	6e69616d 	powvsez	f6, f1, #5.0
	...

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
  10:	00000018 	andeq	r0, r0, r8, lsl r0
	...
  1c:	00000018 	andeq	r0, r0, r8, lsl r0
  20:	8b080e42 	blhi	203930 <main+0x203930>
  24:	42018e02 	andmi	r8, r1, #2, 28
  28:	00040b0c 	andeq	r0, r4, ip, lsl #22
