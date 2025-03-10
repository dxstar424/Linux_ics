	.file	"c3.c"
	.intel_syntax noprefix
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"x = %d, y = %f, z = %lf\n"
	.text
	.p2align 4
	.globl	arithmetic_operations
	.type	arithmetic_operations, @function
arithmetic_operations:
.LFB23:
	.cfi_startproc
	endbr64
	pxor	xmm3, xmm3
	pxor	xmm2, xmm2
	lea	rsi, .LC0[rip]
	mov	eax, 2
	cvtsi2sd	xmm3, edi
	cvtsd2ss	xmm2, xmm1
	mulss	xmm2, xmm0
	cvttss2si	edx, xmm0
	divsd	xmm1, xmm3
	add	edx, edi
	cvtss2sd	xmm2, xmm2
	mov	edi, 1
	movapd	xmm0, xmm2
	jmp	__printf_chk@PLT
	.cfi_endproc
.LFE23:
	.size	arithmetic_operations, .-arithmetic_operations
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	sub	rsp, 8
	.cfi_def_cfa_offset 16
	mov	edx, 15
	movsd	xmm1, QWORD PTR .LC1[rip]
	movsd	xmm0, QWORD PTR .LC2[rip]
	lea	rsi, .LC0[rip]
	mov	edi, 1
	mov	eax, 2
	call	__printf_chk@PLT
	xor	eax, eax
	add	rsp, 8
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	171798692
	.long	1073783767
	.align 8
.LC2:
	.long	2147483648
	.long	1079810457
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
