;Write a program in ARM7TDMI-ISA for string matching
.DATA 
A: .ASCIZ "MY NAME IS BOND"
B: .ASCIZ "JAMES"
C: .ASCIZ "STRING PRESENT"
D: .ASCIZ "STRING ABSENT"

.TEXT
LDR R1, =A
LDR R2, =B
MOV R9, #-1
MOV R10, #0

LOOP:
    ADD R9, R9, #1
    CMP R9, #5
    BEQ RES
    LDRB R3, [R1], #1
    LDRB R4, [R2], #1
    CMP R3, R4
    BEQ LOOP
    MOV R9, #0
    ADD R1, R1, #1
    ADD R10, R10, #1
    LDR R1, =A
    ADD R1, R1, R10
    LDR R2, =B
    CMP R10, #15
    BNE LOOP
    BEQ NRES
RES:
    LDR R0, =C
    SWI 0X02
    B END
NRES: 
    LDR R0, =D
    SWI 0X02
    B END
END:
    SWI 0X11
    .END