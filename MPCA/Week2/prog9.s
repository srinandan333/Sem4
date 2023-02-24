;program to execute multiple instructions with multiple conditions
.DATA
    A: .WORD 6
    B: .WORD 5
    C: .WORD 4
    D: .WORD 0
    E: .WORD 0

.TEXT   
    LDR R5, =A
    LDR R6, =B
    LDR R7, =C
    LDR R8, =D
    LDR R9, =E

    LDR R0, [R5]
    LDR R1, [R6]
    LDR R2, [R7]
    LDR R3, [R8]
    LDR R4, [R9]

CMP R0, R1
BEQ L1
BNE L2
L1: ADD R2, R0, R1
    STR R2, [R7]
    B L5
L2: CMP R1, R2
    BEQ L3
    BNE L4
L3: SUB R3, R0, R1
    STR R3, [R8]
    B L5
L4: MUL R4, R0, R1
    STR R4, [R9]
    B L5
L5: SWI 0X011
    .END
