;program to find the product of 2 numbers using barrel shifter
.DATA
    A: .WORD 0X12345678
    B: .WORD 0

.TEXT   
    LDR R1, =A
    LDR R4, =B
    LDR R2, [R1]

ADD R3, R2, R2, LSL #6
STR R3, [R4]

SWI 0X011
.END