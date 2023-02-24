;Program to search for an element in an array using binary search technique
.DATA
A: .WORD 1,2,3,4,5,6,7,8
B: .ASCIZ "SUCCESSFUL SEARCH"
C: .ASCIZ "UNSUCCESSFUL SEARCH"

.TEXT
LDR R8, =A
LDR R1, [R8]
MOV R2, #9
MOV R3, #8
MOV R7, #-1
MOV R9, #4

L1:
    ADD R7, R7, #1
    CMP R7, #4
    BEQ NRES
    MOV R3, R3, LSR #1
    MUL R4, R3, R9
    ADD R5, R8, R4
    LDR R6, [R5]
    CMP R6, R2
    BGT L1
    BLT L2
    BEQ RES
L2: 
    ADD R8, R8, R4
    B L1
RES: 
    LDR R0, =B
    SWI 0X02
    B END
NRES:
    LDR R0, =C
    SWI 0X02
    B END
END:
    SWI 0X011
    .END
