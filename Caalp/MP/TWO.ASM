ASSUME CS:CODE, DS:DATA
DATA SEGMENT
MSG1 DB "HELLO$"
MSG2 DB 0AH, "AESHA$"
DATA ENDS
CODE SEGMENT
START:
MOV AX,DATA
MOV DS,AX
MOV DX,OFFSET MSG1
MOV AH,09H
INT 21H
LEA DX,MSG2
MOV AH,09H
INT 21H
MOV AH,4CH
INT 21H
CODE ENDS
END START

