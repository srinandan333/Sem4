;Write a program in ARM7TDMI-ISA to find the number of occurrences of a given character in a string
.DATA 
A: .ASCIZ "MY NAME IS BOND"
B: .ASCIZ "N"

.TEXT
LDR R0, =A
LDR R1, =B
LDRB R2, [R1]

LOOP:
    LDRB R3, [R0], #1
    CMP R2, R3
    ADDEQ R9, R9, #1
    ADD R10, R10, #1
    CMP R10, #15
BNE LOOP

SWI 0X11
.END