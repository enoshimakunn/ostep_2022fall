	.file	"9-15.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$1, -8(%rbp)	#initializing variate i, correspondent with "int i = 1"
	movl	$2, -4(%rbp)	#initializing variate j, correspondent with "int j = 2"
	movl	$0, -12(%rbp)	#initializing variate num, correspondent with "int num = 0"
	#the lines above stand for "int i = 1, j = 2, k; int num = 0;"

	movl	-8(%rbp), %edx	#load the value of i into register %edx
	movl	-4(%rbp), %eax	#load the value of j into register %eax
	addl	%edx, %eax	#add i and j and store the result in register %eax
	movl	%eax, -16(%rbp)	#load the sum of i and j into the address of variate k
	#the lines above stand for "k = i + j;"

	movl	-8(%rbp), %eax	#load the value of i into register %eax
	subl	-4(%rbp), %eax	#subtract %eax with variate j and store the result in %eax
	movl	%eax, -16(%rbp)	#store the result of "i - j" into the address of variate k
	#the lines above stand for "k = i - j;"

	movl	-8(%rbp), %eax	#load the value of i into register %eax
	imull	-4(%rbp), %eax	#multiply i by j and store the result in register %eax
	movl	%eax, -16(%rbp)	#store the result into the address of k 
	#the lines above stand for "k = i * j;"

	movl	-4(%rbp), %eax	#load the value of j into register %eax
	cltd	#expand %eax into 64 bits by filling %edx with sign bit of %eax
	idivl	-8(%rbp)	#divide the concatenated %eax and %edx by the value of i and store the result into %eax
	movl	%eax, -16(%rbp)	#move the result towards the address of variate k 
	#the lines above stand for "k = i / j"

	cmpl	$2, -16(%rbp)	#compare the value of k with imm 2
	jne	.L4	#if the above two are different, jump to .L4
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	movl	%eax, -16(%rbp)	#as is explained above, these steps represent the process of "k = i / j;"
	jmp	.L3
.L5:
	addl	$1, -12(%rbp)	#add variate num by 1 and store the result in the original address
	addl	$1, -16(%rbp)	#add variate k by 1 and store the result in the original address
.L4:
	cmpl	$2, -16(%rbp)	#compare the value of k with imm 2
	jne	.L5	#if the above two are different, jump to .L5
.L3:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
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
