;program to add 5 numbers assuming that they are present in registers
MOV R1, #1
MOV R2, #2
MOV R3, #3
MOV R4, #4
MOV R5, #5

ADD R6, R1, R2
ADD R7, R3, R4
ADD R8, R6, R7
ADD R9, R8, R5
SWI 0X011