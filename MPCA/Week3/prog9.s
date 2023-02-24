;program to search for an element in an array using linear search technique
.DATA
A: .WORD 10, 20, 30, 40, 50

.TEXT
LDR R0, =A
MOV R2, #60
MOV R4, #0

LOOP:
    LDR R1, [R0], #4
    CMP R1, R2
    BEQ RES
    ADD R4, R4, #1
    CMP R4, #5
    BEQ END
BNE LOOP

RES:
    MOV R3, #1
    B END
END:
    SWI 0X011
    .END

