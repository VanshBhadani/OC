ASSUME CS:CODE
CODE SEGMENT
START:
MOV CX,4H
MOV AX,1H
L1:
MUL CX
DEC CX
CMP CX,0
JNZ L1
MOV BX,10
MOV CX,0
L2:
MOV DX,0
DIV BX
PUSH DX
INC CX
CMP AX,0
JNZ L2
L3:
POP DX
ADD DL,'0'
MOV AH,02H
INT 21H
MOV AH,4CH
INT 21H
CODE ENDS
END START