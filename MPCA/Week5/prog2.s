;to find the minimum element in an array
.DATA
A: .WORD 39,14,36,13,64,33,17,41,32,16

.TEXT
LDR R0, =A
LDR R1, [R0]
MOV R9, R1
MOV R5, #0; count register
MOV R4, #10
LOOP:
    LDR R1, [R0], #4
    CMP R9, R1
    BGT L1
    B L2
    BEQ EXIT
    L1:
        MOV R9, R1
    L2:
        ADD R5, R5, #1
        CMP R5, R4
BLT LOOP   

EXIT:
    SWI 0X011
    .END