;write a program to find the norm of a matrix
.DATA
A: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
B: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0 

.TEXT
LDR R0, =A
LDR R1, =B
MOV R3, #0
MOV R4, #0
MOV R10, #0

LOOP:
    LDR R2, [R0], #4
    MLA R3, R2, R2, R3
    STR R3, [R1], #4
    ADD R10, R10, #1
    CMP R10, #9
BLT LOOP

LOOP1:
    ADD R4, R4, #1
    MUL R5, R4, R4
    CMP R5, R3
BLT LOOP1

SWI 0X011
.END