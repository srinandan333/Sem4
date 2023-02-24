;write a program to generate fibonacci series and store it in an array
.DATA
RES: .WORD 0, 0, 0, 0, 0, 0, 0, 0, 0, 0

.TEXT
LDR R2, =RES
MOV R0, #0
MOV R1, #1
MOV R9, #10
LOOP:
    ADD R3, R0, R1
    STR R3, [R2], #4
    ADD R4, R4, #1
    MOV R1, R0
    MOV R0, R3
    CMP R4, R9
BNE LOOP

SWI 0X011
.END    