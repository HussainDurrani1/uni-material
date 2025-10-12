.model small

.data
    val1 DW 1000h
    val2 DW 4000h
    val3 DW 2000h
    finalVal DW ?
    
.code
    main PROC
        mov AX, @data
        mov ds, AX
        
        mov BX, val1
        add BX, val2
        sub BX, val3
        mov finalVal, BX
        
        
        MOV AH, 4CH
        int 21h
        
    main ENDP