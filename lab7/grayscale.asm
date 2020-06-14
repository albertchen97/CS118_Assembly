; compilation command: 
; 1. Assemble: yasm -g dwarf2 -f elf64 -l grayscale.lst grayscale.asm
; 2. Compile and link: 
;		g++ -g -no-pie grayscale.o main.cpp -o main -I/usr/local/include/opencv4/opencv2 -I/usr/local/include/opencv4 ;		  -L/usr/local/lib -lopencv_core -lopencv_highgui -ldl -lm -lpthread -lrt -lstdc++ -lopencv_imgcodecs

section .text

global gray_scale_asm
gray_scale_asm:

;prologue
	push rbp
	mov rbp, rsp
	push rcx
	
	;clear rax
	xor rax, rax
	mov rax, 0
	
	mov edi, dword [rdi]		; get the value of the argument
	
	mov ecx, dword 0xFF000000
	and ecx, edi				; *p & 0xFF000000
	shr ecx, 24					; >> 24
	add eax, ecx				; eax = eax + ecx
	
	mov ecx, dword 0x00FF0000  
	and ecx, edi				; *p & 0x00FF0000
	shr ecx, 16					; >> 16
	add eax, ecx				; eax = eax + ecx
	
	mov ecx, dword 0x0000FF00	
	and ecx, edi				; *p & 0x0000FF00
	shr ecx, 8					; >> 8
	add eax, ecx				; eax = eax + ecx
	
	mov cl,  3					
	div cl						; al = eax / cl = eax / 3
	
;epilogue
exit:
	pop rcx
	pop rbp
	ret
	
	
