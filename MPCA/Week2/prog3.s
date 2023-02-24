;program to copy n 8-bit numbers
.DATA
    A: .BYTE 10, 20, 30, 40, 50, 60, 70, 80, 90, 100
    B: .BYTE 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
    LDR R1, =A
    LDR R2, =B
    MOV R4, #0

LOOP:
    LDRB R3, [R1]
    STRB R3, [R2]
    ADD R1, R1, #1
    ADD R2, R2, #1
    ADD R4, R4, #1
    CMP R4, #10
BNE LOOP

SWI 0X011
.END