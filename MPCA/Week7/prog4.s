; Streaming left to right
.DATA  
STR:   .ASCIZ  "HELLO WORLD" 
NUM:  .WORD  15000

.TEXT
MOV R0 , #0  
MOV R1 , #7    
MOV R7 , #0

LDR R8 , =NUM
LDR R8 , [R8]
LDR R2 , =STR

LOOP:		
    SWI 0X204    
    BL SUM
    CMP R0 , #30
    ADDNE R0 , R0 , #1
    SWIEQ 0X11  
B LOOP

SUM: 
    CMP R7 , R8
    ADDNE R7 , R7 , #1
    BNE SUM
    SWI 0X206   
   	MOV R7 , #0
    MOV PC , LR  		
