;considering a number, program to display 1 if 0, 2 if positive than and 3 if negative
MOV R0, #-3
CMP R0, #0
BEQ L1
BGT L2
BLT L3
L1: MOV R1, #1
    B L4
L2: MOV R1, #2
    B L4
L3: MOV R1, #3
    B L4
L4: SWI 0X011
    
