;program to find the factorial of a number
.DATA
    FACT: .WORD 0

.TEXT
    LDR R1, =FACT
    MOV R5, #1
    MOV R4, #1

LOOP:
    MUL R5, R4, R5
    ADD R4, R4, #1
    CMP R4, #6
BNE LOOP

STR R5, [R1]

SWI 0X011
.END