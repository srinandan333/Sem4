;write a program to generate diagonal matrix 
;initialize the array with 0

.DATA 
M: .WORD 0,0,0,0,0,0,0,0,0

.TEXT
LDR R0, =M
MOV R7, #0
MOV R8, #0
MOV R2, #1
SUB R0, R0, #4

LOOP1:
    LOOP:
        LDR R1, [R0], #4
        CMP R8, R7
        BNE L
        ADD R7, R7, #4
        STR R2, [R0]
        L:
            ADD R8, R8, #1
            ADD R9, R9, #1
            CMP R9, #3
    BLT LOOP
    MOV R9, #0
    ADD R10, R10, #1
    CMP R10, #3
BLT LOOP1

SWI 0X11
.END