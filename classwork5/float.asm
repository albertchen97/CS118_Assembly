section .text
global sum
sum:
	;prologue
	push rbp
	mov rbp, rsp
	
	;clear rax
	xor rax, rax
	
	cmp rdi, 0
	je exit
	cmp rsi, 0
	je exit
	
	;get the function arguments
	mov rbx, rdi
	mov	rcx, rsi
	
	;initialize sum = 0
	mov rax, 0
	cvtsi2ss xmm1, eax
	
;get the sum
sumLoop:
	movss xmm0, dword [rbx]
	addss xmm1, xmm0
	add	rbx, 4
	sub	rcx, 1
	cmp rcx, 0
	jne	sumLoop
	
	;return sum
	movss xmm0, xmm1
	
;epilogue
exit:
	pop rbp
	ret
	
