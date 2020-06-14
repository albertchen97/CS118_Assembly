global _abs
;unsigned int abs(int x)

section .text
_abs:
	;prologue
	push rbp
	mov rbp, rsps
	push rbx
	
	;clear rax
	xor rax, rax
	
	;get the parameter
	mov eax, edi
	
	;see if negative
	cmp eax, 0
	jge exit
	
	;ues two's complement to convert negative to positive
	
	;flip bits
	mov ebx, 0xFFFFFFFF
	sub ebx, eax
	
	;then add 1
	mov eax, ebx
	add eax, 1
	
exit:
	;epiloguee
	pop rbx
	pop rbp
	ret
