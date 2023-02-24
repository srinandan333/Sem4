;To find GCD of 2 numbers aassuming operands are in registers.
MOV R0, #28
MOV R1, #49
GCD:
    CMP R0, R1
    BEQ RES
    BLT L1
    BGT L2
L1: 
    SUB R1, R1, R0
    B GCD
L2: 
    SUB R0, R0, R1
    B GCD
RES: 
    MOV R2, R0
    SWI 0X011