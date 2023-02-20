TITLE Display a String
	.MODEL SMALL
	.STACK 32
	.DATA
MESSAGE DB "Programming is Fun", '$'
	.CODE
Main proc
	MOV AX, @data
	MOV DS, AX
	LEA DX, MESSAGE
	MOV AH, 09H ; DOS print string function
	;MOV DX, offset MESSAGE
	
	INT 21H
	MOV AH, 4CH
	INT 21H
Main endp
	End Main