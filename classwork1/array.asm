global add_array_asm
global reverse_array_asm
global add_square_asm

section .text

add_square_asm:

;prologue
	push rbp
	mov rbp, rsp
	push rcx

	xor rax, rax
	mov rcx, rsi
	
	cmp rdi, 0
	je exit_square
	cmp rcx, 0
	je exit_square
	
begin_loop_square:
	
	mov edx, dword [rdi]
	imul edx, edx 
	add eax, edx
	
	add rdi, 4
	sub rcx, 1
	
	cmp rcx, 0
	jne begin_loop_square
	
;epilogue
exit_square:
	pop rcx
	pop rbp
	ret
	
	
	
	
	
	
	
	
	
	
add_array_asm:

;prologue
	push rbp
	mov rbp, rsp
	push rcx

	xor rax, rax
	mov rcx, rsi			; counter = size
	
	; return 0 if the pointer is null or the size is 0
	cmp rdi, 0
	je exit_add
	cmp rcx, 0
	je exit_add

begin_loop_add:
	add rax, [rdi] ; dereferencing rdi
	add rdi, 4
	sub rcx, 1
	cmp rcx, 0
	jne begin_loop_add
                                                                                                                                                        
;epilogue
exit_add:
	pop rcx
	pop rbp
	ret


reverse_array_asm:

	;prologue
	push rbp
	mov rbp, rsp
	push rcx
	
	xor rax, rax
	mov rcx, rdx			; counter = size
	
	; return 0 if the pointer is null or the size is 0
	cmp rsi, 0
	je exit_reverse
	cmp rdi, 0
	je exit_reverse
	cmp rcx, 0
	je exit_reverse
	
	; *array[front] = *array[front + size - 1] = *array[end]
	sub rdx, 1
	imul rdx, 4
	add rdi, rdx
	
begin_loop_reverse:			; while(counter !=0)
	
	mov eax, dword[rdi]		; temp = *array
	mov dword[rsi], eax		; *reversed_array = temp
	sub rdi, 4				; 
	add rsi, 4				; 
	sub rcx, 1 				; counter = counter - 1
	cmp rcx, 0 				; (counter == 0)?
	jne begin_loop_reverse 	; if(counter != 0), jump to the beginning of the loop, else return
	
;epilogue
exit_reverse:
	pop rcx
	pop rbp
	ret	
	
	
	
	
	
	
	
	
