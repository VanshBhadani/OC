ASSUME CS:CODE
CODE SEGMENT
START:
  MOV CX,5H
  MOV AX,1H
LOOP1:
  MUL CX
  DEC CX
  CMP CX,0
  JNZ LOOP1
  MOV BX,10
  MOV CX,0
CONVERT:
  MOV DX,0
  DIV BX
  INC CX
  PUSH DX
  CMP AX,0
  JNZ CONVERT
DISPLAY:
  POP DX
  ADD DL,'0'
  MOV AH,02H
  INT 21H
  LOOP DISPLAY
  MOV AH,4CH
  INT 21H
  CODE ENDS
  END START
  
 