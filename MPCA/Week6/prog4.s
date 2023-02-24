;Write a program in ARM7TDMI-ISA to find the sum of all the digits in an 32bit number
.DATA
NUMBER: .WORD 0X12341234

.TEXT
LDR R1, =NUMBER
LDR R2, [R1]
MOV R10, #0

LOOP:
    AND R3, R2, #0x0000000F
    ADD R4, R4, R3
    MOV R2, R2, LSR #4
    ADD R10, R10, #1
    CMP R10, #32
BNE LOOP

SWI 0X11
.END