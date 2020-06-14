global myMemoryCopy

section .text

;myMemoryCopy(*des, *src, MEMORY_SIZE_IN_BYTE)
;myMemoryCopy([rdi], [rsi], [rdx])

_start:

	mov rcx, qword [rdx] ; counter = size

myMemoryCopy:
	
	; do memory copy
	mov rax, [rsi] ; move the content in the seconde parameter(esi) to the register eax. (memory to register)
	mov [rdi], rax ; move the memory address of esi that stored in the register eax to the memory address of edi. (register to memory)
	
	; memory address is 32-bits (4 bytes), so increment by 4 (memory is byte addresable)
	add rsi, 8
	add rdi, 8
	
	; loop until ecx = 0
	sub rcx, 1; ecx -= 4 (4 bytes)
	cmp rcx, 0 ; is ecx 0?

	; if rcx does ont equal to 0, jump to the beginning of the loop
	jne myMemoryCopy

	ret

