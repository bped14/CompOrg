#include <stdbool.h>

#ifndef DECLARATIONS_H
#define DECLARATIONS_H


//opcode hex definitions
#define j       0x0002
#define jal     0x0003
#define beq     0x0004
#define bne     0x0005
#define addi    0x0008
#define addiu   0x0009
#define slti    0x000A
#define sltiu   0x000B
#define andi    0x000C
#define ori     0x000D
#define xori    0x000E
#define lui     0x000F
#define lb      0x0020
#define lh      0x0021
#define lw      0x0023
#define lbu     0x0024
#define lhu     0x0025
#define sb      0x0028
#define sw      0x002B

//function hex definitions
#define sll     0x0000
#define srl     0x0002
#define jr      0x0008
#define mult    0x0018
#define multu   0x0019
#define div     0x001a
#define divu    0x001b
#define add     0x0020
#define addu    0x0021
#define sub     0x0022
#define subu    0x0023
#define and     0x0024
#define or      0x0025
#define xor     0x0026
#define nor     0x0027
#define slt     0x002A
#define sltu    0x002B




typedef struct{
    unsigned int Opcode;
    unsigned int Rs;
    unsigned int Rt;
    unsigned int Rd;
    unsigned int shamt;
    unsigned int funct;
    short int immediate;
    unsigned long jumpaddress;
    unsigned int PCinc;
} IFID_Reg;


typedef struct{
    bool regWrite;//regWrite
    //memread
    //memtoreg
    unsigned int ALUop;
    unsigned int Rd; //destination reg
    unsigned int Rs; //regRs
    unsigned int Rt; //regRt
    unsigned long RsValue; //regRsValue
    unsigned long RtValue; //regRtValue
    unsigned int shamt;
    short int immediate;
    unsigned int PCinc;

} IDEX_Reg;

typedef struct{
    bool regWrite;//regWrite
    //memread
    //memtoreg
    unsigned int ALUop;
    unsigned long ALUresult;
    unsigned int Rd; //destination reg r type
    unsigned int Rt; //destination reg i type
    short int immediate;
    unsigned int PCinc;

} EXMEM_Reg;




#endif //DECLARATIONS_H
