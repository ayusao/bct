TITLE To input string and count no of vowels
.model small
.stack 64
.data
string label byte
maxlen db 20
actuallen db ?
kbinput db 20 dup('?')
vowel db 'aeiouAEIOU'
prompt db 'Input String: ','$'
.code
main proc far
    mov ax,@data
    mov ds,ax
    call displaymsg
    call readstring
	call nextline
    call count
	
    call display
    mov ax,4c00h
    int 21h
    main endp

displaymsg proc near
    mov ah,09
    lea dx,prompt
    int 21h
    ret
    displaymsg endp

readstring proc near
    mov ah,0ah
    lea dx,string
    int 21h
    ret
    readstring endp

count proc near
    lea si, kbinput
    mov bh,actuallen
    mov dx,00h
back1: lea di,vowel
    mov cx,000ah
    mov al,[si]
back: cmp al,[di]
    jnz fwd 
    inc dx
fwd: inc di
    loop back
    inc si
    dec bh
    jnz back1
    ret
count endp

nextline proc
	mov ah, 02h
	mov dl, 0dh
	int 21h
	mov dl, 0ah
	int 21h
	ret
nextline endp

display proc
    mov cx, 00
	mov bx, 10
	mov ax, dx
again:	mov dx, 00
	div bx
	inc cx
	push dx
	cmp ax, 00
	jg again
	
disp:	pop dx
	or dx, 30h
	mov ah, 02h
	int 21h
	loop disp
    ret 
    display endp
end main