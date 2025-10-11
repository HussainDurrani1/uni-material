.model small
org 100h
.data

msg db "HELLO WORLD$"
.code
Main proc
    mov ah,09h
    lea dx, msg
    int 21h
    
    mov ah, 4ch
    int 21h
    
    Main endp
End main
