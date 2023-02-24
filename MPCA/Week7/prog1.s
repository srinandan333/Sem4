;light up the 2 red lights
MOV R0, #0
LOOP: 
    SWI 0X201
    MOV R4, #64000
    DELAY:
        SUB R4, R4, #1
        CMP R4, #0
    BNE DELAY
    ADD R0, R0, #1
    CMP R0, #3
BLE LOOP
SWI 0X011