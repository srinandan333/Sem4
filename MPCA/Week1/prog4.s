;program to check if a number is even or odd
MOV R0, #7
AND R1, R0, #1
CMP R1, #0
BEQ L1
BNE L2
L1: MOV R1, #0x00000000
    B L3
L2: MOV R1, #0xFFFFFFFF
    B L3
L3: SWI 0X011
    

