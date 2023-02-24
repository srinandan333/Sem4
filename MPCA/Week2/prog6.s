;program to find sum of n 8-bit numbers
.DATA
    A: .BYTE 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    SUM: .BYTE 0

.TEXT
    LDR R1, =A
    LDR R2, =SUM
    MOV R5, #0
    MOV R4, #0

LOOP:
    LDRB R3, [R1]
    ADD R5, R5, R3
    ADD R1, R1, #1
    ADD R4, R4, #1
    CMP R4, #10
BNE LOOP

STRH R5, [R2]

SWI 0X011
.END