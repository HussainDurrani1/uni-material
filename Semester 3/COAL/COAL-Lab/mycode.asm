.model small
.data
    DATA1 db 12H
    DATA2 db 09H
    SUM db ?
    message db 'Hello, Assembly!' '$'
    
.code
    main proc FAR
        MOV AX, @data
        MOV DS, AX
        
        MOV AL, DATA1
        MOV BL, DATA2
        ADD AL, BL
        MOV SUM, AL
        
        MOV AH, 4CH
        int 21h  
        
     MAIN ENDP
