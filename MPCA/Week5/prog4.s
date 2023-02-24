;write a program to find the product of 2 matrices
.DATA
A: .WORD 1, 1, 1, 2, 2, 2, 3, 3, 3
B: .WORD 4, 4, 4, 5, 5, 5, 6, 6, 6
C: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
LDR R0, =A
LDR R1, =B
LDR R2, =C

LOOP2:
    LOOP1:
        LOOP:
            LDR R3, [R0], #4
            LDR R4, [R1], #12
            MUL R6, R3, R4
            ADD R5, R5, R6
            ADD R8, R8, #1
            CMP R8, #3
        BLT LOOP
        STR R5, [R2], #4
        MOV R5, #0
        SUB R0, R0, #12
        SUB R1, R1, #32
        MOV R8, #0
        ADD R9, R9, #1
        CMP R9, #3
    BLT LOOP1
    MOV R9, #0
    ADD R0, R0, #12
    SUB R1, R1, #12
    ADD R10, R10, #1
    CMP R10, #3
BLT LOOP2

SWI 0X011
.END