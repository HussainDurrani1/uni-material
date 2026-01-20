.model small
.stack 100h

.data
string dB "Hello, World!", 0

.code
MAIN PROC FAR
    MOV AX, @data
    MOV DS, AX
    
    MOV AX, 0XB800
    MOV ES, AX
    MOV SI, 1990 
    MOV AX, 0
    
    MOV BX, offset string
    MOV CX, 13
    mov DI, 0
    
    DISPLAY:
        MOV AL, [BX+DI]
        INC DI
        MOV ES:[SI], AL
        INC SI
        MOV ES: [SI], 07h
        INC SI
        LOOP DISPLAY
        
    END:      
        MOV AH, 4Ch
        INT 21H
    
MAIN ENDP
.exit