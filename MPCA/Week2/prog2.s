;program to copy n 16-bit numbers
.DATA
    A: .HWORD 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000
    B: .HWORD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
    LDR R1, =A
    LDR R2, =B
    MOV R4, #0

LOOP:
    LDRH R3, [R1]
    STRH R3, [R2]
    ADD R1, R1, #2
    ADD R2, R2, #2
    ADD R4, R4, #1
    CMP R4, #10
BNE LOOP

SWI 0X011
.END