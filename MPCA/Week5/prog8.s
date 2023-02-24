;write a program to find the row sum of a matrix
.DATA
A: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
B: .WORD 0, 0, 0

.TEXT
LDR R0, =A
LDR R1, =B
MOV R3, #0
MOV R9, #0
MOV R10, #0
SUB R0, R0, #4

LOOP1:
    LOOP:
        LDR R2, [R0, #4]!
        ADD R3, R3, R2
        ADD R10, R10, #1
        CMP R10, #3
    BLT LOOP
    STR R3, [R1], #4
    MOV R3, #0
    MOV R10, #0
    ADD R9, R9, #1
    CMP R9, #3
BLT LOOP1

SWI 0X011
.END