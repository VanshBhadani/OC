ASSUME CS:CODE,DS:DATA
DATA SEGMENT
NL1 DB 10, "Enter the number:$"
NL2 DB 10, "EVEN $"
NL3 DB 10, "ODD $"
DATA ENDS
CODE SEGMENT
START:
MOV AX,DATA
MOV DS,AX
LEA DX,NL1
MOV AH,09H
INT 21H
MOV AH,01H
INT 21H
SUB AL,30H
TEST AX,01H
JE L1
LEA DX,NL3
MOV AH,09H
INT 21H
MOV AH,4CH
INT 21H
 L1:
LEA DX,NL2
MOV AH,09H
INT 21H
MOV AH,4CH
INT 21H
CODE ENDS
END START

