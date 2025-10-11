; ===== EMU8086 Boilerplate =====

.model small
.stack 100h

.data
    ; declare variables here

.code
main proc
    mov ax, @data
    mov ds, ax

    ; ==== your code here ====

    mov ah, 4Ch
    int 21h
main endp
end main
