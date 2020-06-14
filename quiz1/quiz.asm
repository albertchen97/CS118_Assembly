global evens_and_odds
; uint32_t evens_and_odds(uint32_t* src, uint32_t* evn, uint32_t* odd,  uint32_t size);
; src = rdi
; evn = rsi
; odd = rdx
; size = rcx
; return rax

section .text

evens_and_odds:
	; prologue
	push rbp
	mov rbp, rsp	; we have a new base pointer
	push r12
	
	xor rax, rax
	mov r12, rcx	; r12 = size
	mov rcx, 0		; counter = 0
	
	cmp rdi, 0
	je exit
	cmp r12, 0
	je exit
	
; get even numbers and push into evn array

evenLoop:

	mov r10, rdi
	and r10, 0	; use and to check even number, if rdi & 0x00000001 = 0 then is even
	
	cmp r10, 0
	je add_even
	
	add rdi, 4
	sub r12, 1
	cmp r12, 0
	jne evenLoop
	
add_even:
	mov rsi, rdi
	
	mov eax, dword[rsi]
	mov dword[rsi], eax 
	
	add rcx, 1		 			; number of even + 1
	add rsi, 4
	
	add rdi, 4
	sub r12, 1					; counter = counter - 1
	cmp r12, 0
	jne evenLoop

	mov eax, dword[rcx]
	mov dword[rcx], eax
	
exit:
	pop r12
	pop rbp
	ret
