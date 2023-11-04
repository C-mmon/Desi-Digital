LDR R0,=0xE000ED08 ; Set R0 to VTOR address
LDR R1,=0x00010000 ; User’s flash memory based address
STR R1, [R0] ; Define beginning of user’s flash memory
; as vector table
LDR R0,[R1] ; Load initial MSP value
MOV SP, R0 ; Set SP value (assume MSP is selected)
LDR R0,[R1, #4] ; Load reset vector
BX R0 ; Branch to reset handler in user’s flash