; display a string on the screen character-wise
.DATA
MSG: .ASCIZ "HELLO WORLD"

.TEXT
LDR R1, =MSG

LOOP:
    LDRB R0, [R1], #1
    CMP R0, #0 
    SWINE 0X00
BNE LOOP

SWI 0X011
.END