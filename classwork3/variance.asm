global variance
;int variance(uint32_t* , uint32_t*, uint32_t);
;rdi = src
;rsi = tmp
;rdx = size

section .text
variance:
	;prologue
	push rbp
	mov rbp, rsp
	push rbx
	
	;make sure the parameters are not zero
	cmp rdi, 0
	je exit
	cmp rsi, 0 
	je exit
	cmp rdx, 0
	je exit
	
	;clear registers
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx
	
	mov rcx, rdx	;counter
	
	;get average
	xor ebx, ebx
	
	mov rbx, rdi
	push rcx
	
	;get the average of the raw data
averageLoop:
	
	add eax, dword [rdi]
	add rdi, 4
	sub rcx, 1
	cmp rcx, 0
	jne averageLoop
	
	pop rcx
	mov rdi, rbx				;get back rdi
	
	mov ecx, edx
	cdq
	idiv ecx			;average = total / size
	mov ebx, eax
	
	;push squares into tmp
	
	push rcx
	
tmpLoop:

	mov eax, dword [rdi]
	sub eax, ebx				;element - mean
	mul eax					;(element - mean)^2
	mov dword [rsi], eax		;push into tmp array
	add rdi, 4
	add rsi, 4
	sub rcx, 1
	cmp rcx, 0
	jne tmpLoop
	
	pop rcx
	
	;get the sum of the squares
	xor rax, rax
	mov rax, 0
	
	push rcx
	
sumLoop:
	
	add eax, dword [rsi]
	add rsi, 4
	sub rcx, 1
	cmp rcx, 0
	jne sumLoop
	
	pop rcx
	
	push rcx
	;get the variance
	cdq
	idiv ecx
	pop rcx
	
;epilogue 
exit:
	pop rbx
	pop rbp
	ret
	

	
