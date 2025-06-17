.model small
.stack 100h

.data
menu db "1. Burger - 5",13,10
     db "2. Pizza  - 8",13,10
     db "3. Soda   - 2",13,10
     db "Choose (1-3): $"

qtymsg db 13,10, "Quantity: $"
totalmsg db 13,10, "Total: $",13,10,'$'
invalidmsg db 13,10, "Invalid option selected.$"

prices dw 5, 8, 2

.code
start:
    mov ax, @data
    mov ds, ax

    ; Show menu
    mov dx, offset menu
    mov ah, 09h
    int 21h

    ; Read item choice
    mov ah, 01h
    int 21h
    sub al, '0'
    cmp al, 1
    jb invalid
    cmp al, 3
    ja invalid
    mov bl, al
    dec bl               ; bl = index 0–2

    ; Ask for quantity
    mov dx, offset qtymsg
    mov ah, 09h
    int 21h

    ; Read quantity
    mov ah, 01h
    int 21h
    sub al, '0'
    xor ah, ah           ; convert AL to AX (AX = quantity)
    mov cx, ax           ; CX = quantity (16-bit)

    ; Calculate total = price * quantity
    mov si, bx
    shl si, 1
    mov ax, [prices + si] ; AX = price
    mul cx                ; DX:AX = AX * CX

    ; Show total message
    mov dx, offset totalmsg
    mov ah, 09h
    int 21h

    call print_num

    ; Exit
    mov ah, 4Ch
    int 21h

invalid:
    mov dx, offset invalidmsg
    mov ah, 09h
    int 21h
    mov ah, 4Ch
    int 21h

; Print number in AX
print_num proc
    push ax
    push bx
    push cx
    push dx

    mov cx, 0
    mov bx, 10

divide_loop:
    xor dx, dx
    div bx
    push dx
    inc cx
    cmp ax, 0
    jne divide_loop

print_digits:
    pop dx
    add dl, '0'
    mov ah, 02h
    int 21h
    loop print_digits

    pop dx
    pop cx
    pop bx
    pop ax
    ret
print_num endp

end start