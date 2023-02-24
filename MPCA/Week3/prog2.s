;To find GCD of 2 numbers assuming operands are in memory locations.
.DATA
A: .WORD 123
B: .WORD 23

.TEXT
LDR R3, =A
LDR R4, =B

LDR R0, [R3]
LDR R1, [R4]

GCD:
    CMP R0, R1
    BEQ RES
    BLT L1
    BGT L2
L1: 
    SUB R1, R1, R0
    B GCD
L2: 
    SUB R0, R0, R1
    B GCD
RES: 
    MOV R2, R0
    SWI 0X011
    .END