;;UPDATE: It prints out the ASCII value of the largest number
;Final Update: It prints out the decimal value yayyyy
TITLE To find the largest number
.MODEL SMALL
.STACK 32
.DATA
ARRAY DB 20,04,55,66,23,12,78,99,45,33
GREAT DB ?
.CODE
MAIN PROC FAR
	MOV AX, @DATA
	MOV DS, AX

	MOV SI, OFFSET ARRAY
	MOV CX, 09H
	MOV BL, [SI]
	
AGAIN:	INC SI
	CMP BL, [SI]
	JNC NOCHANGE
	MOV BL, [SI]

NOCHANGE: LOOP AGAIN
	MOV GREAT, BL
mov ax, 0001h
mul bl
aam
add ax, 3030h

	mov dl, ah
	mov dh, al
	MOV AH, 02H
	INT 21H
	mov dl, dh
	int 21h

	MOV AH, 4CH
	INT 21H
MAIN ENDP
END MAIN