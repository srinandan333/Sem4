;write a program to transfer a block of 256 words stored at memory location x to memory location y 
;using LDM and STM instructions (the rate of transfer is 32 bytes)
.DATA
X: .WORD 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 
Y: .WORD 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0, 0

.TEXT
LDR R0, =X
LDR R9, =Y
MOV R10, #0

LOOP:
    LDMIA R0!, {R1-R8}
    STMIA R9!, {R1-R8}
    ADD R10, R10, #1
    CMP R10, #2
BNE LOOP

SWI 0X011
.END