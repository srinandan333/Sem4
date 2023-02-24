;program to add if 2 numbers are equal, to subtract if not
MOV R0, #5
MOV R1, #3
CMP R0, R1
BEQ L1
BNE L2
L1: ADD R2, R0, R1
    B L3
L2: SUB R2, R0, R1
    B L3
L3: SWI 0X011
    

