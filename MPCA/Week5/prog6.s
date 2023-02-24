;write a program to find the sum of 2 matrices
.DATA
A: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
B: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
C: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
LDR R0, =A
LDR R1, =B
LDR R2, =C

MOV R9, #0
MOV R10, #0

SUB R0, R0, #4
SUB R1, R1, #4
SUB R2, R2, #4

LOOP1:
    LOOP:
        LDR R3, [R0, #4]!
        LDR R4, [R1, #4]!
        ADD R5, R3, R4
        STR R5, [R2, #4]!
        ADD R9, R9, #1
        CMP R9, #3
    BLT LOOP
    MOV R9, #0
    ADD R10, R10, #1
    CMP R10, #3
BLT LOOP1

SWI 0X011
.END