;display a number on the screen
.DATA
A: .WORD 0X56

.TEXT
LDR R2, =A
LDRB R3, [R2]

AND R0, R3, #0XF0
MOV R0, R0, LSR #4
ORR R0, R0, #0X30
SWI 0X00

AND R4, R3, #0X0F
ORR R0, R4, #0X30
SWI 0X00

SWI 0X011
.END