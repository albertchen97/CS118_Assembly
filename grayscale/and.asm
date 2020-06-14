section .text
global _start
_start:
	xor rax, rax
	mov eax, 0xDDDDDDDD
	and eax, 0x0F
