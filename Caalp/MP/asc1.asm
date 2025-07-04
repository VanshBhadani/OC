ASSUME CS:CODE,DS:DATA
DATA SEGMENT
ARR DB 3,5,6,2,1
LEN DW $-ARR
DATA ENDS
CODE SEGMENT
START:
    MOV AX,DATA
    MOV DS,AX
    MOV CX,LEN
    DEC CX
LOOP1:
    MOV BX,0
LOOP2:
    MOV AL,ARR[BX]
    CMP AL,ARR[BX+1]
    JLE LOOP3
    XCHG AL,ARR[BX+1]
    MOV ARR[BX],AL
LOOP3:
    INC BX
    CMP BX,CX
    JL LOOP2
    LOOP LOOP1
    MOV CX,LEN
    MOV BX,0
PRINT:
    MOV DL,ARR[BX]
    ADD DL,30H
    MOV AH,02H
    INT 21H
    INC BX
    LOOP PRINT
    MOV AH,4CH
    INT 21H
CODE ENDS
END START