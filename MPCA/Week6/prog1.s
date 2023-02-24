;write a program in ARM7TDMI to find the sum of all the positive numbers in an array
.DATA
A: .WORD -1,1,-2,2,-3,3,-4,4,-5,5

.TEXT
LDR R0, =A
MOV R2, #0
MOV R10, #0

LOOP:
    LDR R1, [R0], #4
    CMP R1, #0
    BLT L
    ADD R2, R2, R1
    L:
        ADD R10, R10, #1
        CMP R10, #10
BNE LOOP

SWI 0X11
.END