global evens_and_odds
; void evens_and_odds(uint32_t* src, uint32_t* evn, uint32_t* odd,  uint32_t size);
; src = rdi
; evn = rsi
; odd = rdx
; size = rcx
; return rax

section .text

evens_and_odds:
	;prologue
	push rbp
	mov rbp, rsp	; we have a nwe base pointer
	
	xor rax, rax
	xor r8, r8
	
	; 1. Pick the first element from src
	mov ebx, dword [rdi]
	and ebx, 0x1
	cmp ebx, 1
	jne even
	
even:
	mov eax, dword [rdi]
	mov dword [rsi], eax
	add rsi, 4
	add r8, 1
	jmp evens_and_odds
	
	; 2. Check if even
	; 3. Copy element in even array
	; 4. else
	;    copy it into odd array

exit:
	mov rax, r8
	pop rbp
	ret
