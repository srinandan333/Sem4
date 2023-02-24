; display a string on the screen at a time
.DATA
MSG: .ASCIZ "HELLO WORLD"

.TEXT
LDR R0, =MSG

SWI 0X02

SWI 0X011
.END