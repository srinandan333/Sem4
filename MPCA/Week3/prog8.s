;To find sum of N data items at alternate position using post-indexing mode
.DATA
A: .WORD 1,2,3,4,5,6,7,8,9,10
SUM: .WORD 0

.TEXT
MOV R2, #0
LDR R1, =A
LDR R3, =SUM
MOV R5, #8
MOV R6, #1

LOOP:
    LDR R4, [R1], R5
    ADD R2, R2, R4
    ADD R6, R6, #1
    CMP R6, #6
BNE LOOP

STR R2, [R3]
SWI 0X011
.END


