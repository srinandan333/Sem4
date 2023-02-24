;Program to search for an element in an array using binary search technique
.DATA
A: .WORD 1,2,3,4,5,6,7,8,9

.TEXT
LDR R0, =A
LDR R1, [R0]
MOV R2, #13
MOV R3, #9
MOV R7, #0
MOV R9, #4
L1:
    ADD R7, R7, #1
    CMP R7, #4
    BEQ END
    MOV R3, R3, LSR #1
    MUL R4, R3, R9
    ADD R5, R0, R4
    LDR R6, [R5]
    CMP R6, R2
    BGT L1
    BLT L2
    BEQ RES
L2: 
    ADD R0, R0, R4
    B L1
RES: 
    MOV R8, #1
    B END
END:
    SWI 0X011
    .END
