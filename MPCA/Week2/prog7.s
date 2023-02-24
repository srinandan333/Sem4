;program to find the sum of n natural numbers
.DATA
    SUM: .WORD 0

.TEXT
    LDR R1, =SUM
    MOV R5, #0
    MOV R4, #1

LOOP:
    ADD R5, R5, R4
    ADD R4, R4, #1
    CMP R4, #11
BNE LOOP

STR R5, [R1]

SWI 0X011
.END