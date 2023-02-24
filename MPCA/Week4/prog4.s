;introduction to swap instruction
.DATA
A: .WORD 0X56

.TEXT
LDR R2, =A
MOV R1, #10

SWP R1, R1, [R2]

SWI 0X011
.END