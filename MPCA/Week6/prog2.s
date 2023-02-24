;write a program in ARM7TDMI to check the parity of 32 bit number using a function "PARITYCHECK"
;display appropriate appropriate messages as odd parity or even parity number

.DATA
A: .ASCIZ "EVEN PARITY"
B: .ASCIZ "ODD PARITY"
NUMBER: .WORD 0X00000004

.TEXT
LDR R1, =NUMBER
LDR R2, [R1]
MOV R10, #0
MOV R9, #0

B LOOP1
PARITYCHECK:
    LOOP:
        AND R3, R2, #1
        CMP R3, #1
        BNE L
        ADD R8, R8, #1
        L:
            MOV R2, R2, LSR #1
            ADD R10, R10, #1
            CMP R10, #32
    BNE LOOP
MOV PC, LR

LOOP1:
    BL PARITYCHECK
    AND R9, R8, #1
    CMP R9, #0
    BEQ L1
    BNE L2
    L1: 
        LDR R0, =A
        SWI 0X02
        B L3
    L2:
        LDR R0, =B
        SWI 0X02
        B L3
    L3:
        SWI 0X11
        .END

