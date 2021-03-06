#include "declarations.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

//create the 4 register structs
IFID_Reg IFID;
IDEX_Reg IDEX;
EXMEM_Reg EXMEM;
//MEMWB

//some test machine code
unsigned long efoff = 0xFFFFFFFF;
unsigned long testRtype = 0x02116022;
unsigned long testItype = 0x2088FF9C;
unsigned long testJtype = 0x0BF0F0F0;

//DEFINE REGISTERS
unsigned long reg[32] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

//tool used for debugging
void printInBinary(uint32_t num, int bit){
    if ( bit >= 8*sizeof(num) )
    {
        return;
    }

    printInBinary(num/2, bit+1);
    printf("%u", num%2);

    if ( bit%8 == 0 )
    {
        printf(" ");
    }
    if ( bit == 0 )
    {
        printf("\n");
    }
}

/*******************************************************************************
 █████╗ ██╗     ██╗   ██╗
██╔══██╗██║     ██║   ██║
███████║██║     ██║   ██║
██╔══██║██║     ██║   ██║
██║  ██║███████╗╚██████╔╝
╚═╝  ╚═╝╚══════╝ ╚═════╝
*******************************************************************************/

/********************J_TYPE_FUNCTIONS*******************

j
jal

*/

/********************I_TYPE_FUNCTIONS*******************/
/*

beq

bne

*/

unsigned long addImmed(unsigned int rs, short int immed){
    unsigned long result;
    result = rs + immed;
    return result;
}

unsigned long addImmediateUnsigned(unsigned int rs, short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = rs + (uint32_t)uImmed;
    return result;
}

unsigned long setLessThanImmed(unsigned int rs, short int immed){
    unsigned long result;
    result = (rs < immed)? 1 : 0;
    return result;
}

unsigned long setLessThanImmedUnsigned(unsigned int rs, short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = (rs < uImmed)? 1 : 0;
    return result;
}

unsigned long andImmed(unsigned int rs, short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = rs & (uint32_t)uImmed;
    return result;
}

unsigned long orImmed(unsigned int rs, short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = rs | (uint32_t)uImmed;
    return result;
}

unsigned long xorImmed(unsigned int rs, short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = rs ^ (uint32_t)uImmed;
    return result;
}

unsigned long loadUpperImmed(short int immed){
    unsigned short int uImmed = immed;
    unsigned long result;
    result = (uImmed << 16);
    return result;
}

/* CONFUSED BY THIS SHIT
unsigned long loadByte(unsigned int rs, short int immed){

    unsigned long result;

    return result;
}

unsigned long loadHalfWord(unsigned int rs, short int immed){

    unsigned long result;

    return result;
}

unsigned long loadWord(unsigned int rs, short int immed){
    unsigned long result;
     R[rt] = M[R[rs]+SignExtImm]
    return result;
}

unsigned long loadByteUnsigned(unsigned int rs, short int immed){
    unsigned long result;

    return result;
}

unsigned long loadHalfWordUnsigned(unsigned int rs, short int immed){
    unsigned long result;

    return result;
}

void storeByte(unsigned int rs, short int immed){
    unsigned long result;

    return;
}

void storeHalfWord(unsigned int rs, short int immed){
    unsigned long result;

    return;
}

void storeWord(unsigned int rs, short int immed){
    unsigned long result;

    return;
}

*/

void branchLessThanZero(unsigned int rs, short int immed){

}

void branchGreaterThanZero(unsigned int rs, short int immed){

}

void branchLessThanEqualZero(unsigned int rs, short int immed){

}

/********************R_TYPE_FUNCTIONS*******************/
unsigned long shiftLeftLogical(unsigned int rt, unsigned int shamt){
    unsigned long result;
    result = rt << shamt;
    return result;
}

unsigned long shiftRightLogical(unsigned int rt, unsigned int shamt){
    unsigned long result;
    result = rt >> shamt;
    return result;
}
/*
void jumpRegister(){

}
*/

unsigned long addition(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs + rt;
    return result;
}

unsigned long addUnsigned(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs + rt;
    return result;
}

unsigned long subtract(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs - rt;
    return result;
}

unsigned long subtractUnsigned(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs - rt;
    return result;
}

//cant use just the word and() because it gets mad about the predefined variable and
unsigned long andOperation(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs & rt;
    return result;
}

unsigned long orOperation(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs | rt;
    return result;
}

unsigned long xorOperation(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = rs ^ rt;
    return result;
}

unsigned long norOperation(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = !(rs | rt);
    return result;
}

unsigned long setLessThan(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = (rs < rt)? 1:0;
    return result;
}

unsigned long setLessThanUnsigned(unsigned int rs, unsigned int rt){
    unsigned long result;
    result = (rs < rt)? 1:0;
    return result;
}

/*
unsigned long moveNonZero(unsigned int rs, unsigned int rt, unsigned int rd){
    unsigned long result;
    if(rt != 0){
        result = rs;
    } else {
        result = rd;
    }
    return result;
}

unsigned long moveZero(unsigned int rs, unsigned int rt, unsigned int rd){
    unsigned long result;
    if(rt = 0){
        result = rs;
    } else {
        result = rd;
    }
    return result;
}
*/

/*******************************************************************************
██╗  ██╗███████╗██╗     ██████╗ ███████╗██████╗ ███████╗
██║  ██║██╔════╝██║     ██╔══██╗██╔════╝██╔══██╗██╔════╝
███████║█████╗  ██║     ██████╔╝█████╗  ██████╔╝███████╗
██╔══██║██╔══╝  ██║     ██╔═══╝ ██╔══╝  ██╔══██╗╚════██║
██║  ██║███████╗███████╗██║     ███████╗██║  ██║███████║
╚═╝  ╚═╝╚══════╝╚══════╝╚═╝     ╚══════╝╚═╝  ╚═╝╚══════╝
*******************************************************************************/

//sections up r type data
void rtype(unsigned long rtypeData){
    //bit masking and shifting for each part of the r type
    IFID.Opcode = (rtypeData & 0xFC000000) >> 26;
    IFID.Rs = (rtypeData & 0x03E00000) >> 21;
    IFID.Rt = (rtypeData & 0x001F0000) >> 16;
    IFID.Rd = (rtypeData & 0x0000F800) >> 11;
    IFID.shamt = (rtypeData & 0x000007C0) >> 6;
    IFID.funct = (rtypeData & 0x0000003F) >> 0;
    return;
}

//sections up i type data
void itype(unsigned long itypeData){
    //bit masking and shifting for each part of the i type
    IFID.Opcode = (itypeData & 0xFC000000) >> 26;
    IFID.Rs = (itypeData & 0x03E00000) >> 21;
    IFID.Rt = (itypeData & 0x001F0000) >> 16;
    IFID.immediate = (itypeData & 0x0000FFFF) >> 0;
    return;
}

//sections up j type data
void jtype(unsigned long jtypeData){
    //bit masking and shifting for each part of the i type
    IFID.Opcode = (jtypeData & 0xFC000000) >> 26;
    IFID.jumpaddress = (jtypeData & 0x03FFFFFF) >> 0;
    return;
}

//determine where to send the data based on the opcode
void typeSelect(unsigned long machCode){
    IFID.Opcode = (machCode & 0xFC000000) >> 26;

    switch(IFID.Opcode) {
        //every r type has a 0 for the opcode
        case 0x0000 :
            rtype(machCode);
            break;
        //only two functions use j type
        case 0x0002 : //jump
            jtype(machCode);
            break;
        case 0x0003 : //jump and link
            jtype(machCode);
            break;
        default :   //everything else will be an immidiate
            itype(machCode);
            break;
    }

    return;
}

//determine rs value
void rsRegDetermination(unsigned int rs){
    IDEX.Rs = IFID.Rs;
    IDEX.RsValue = reg[rs];
}

//determine rt values
void rtRegDetermination(unsigned int rt){
    IDEX.Rt = IFID.Rt;
    IDEX.RtValue = reg[rt];
}

//takes the information on I and R type instructions and figures out what its supposed to do
void executeDetermination(){
    //R Type
    if(IFID.Opcode == 0){
        //decide what to do with r type inst based on its funct
        //GOING IN THE ORDER LISTEN ON THE GREEN SHEET FIRST PAGE
        switch(IFID.funct){
            //add
            case add :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = add;

                break;
            //add unsigned
            case addu :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = addu;

                break;
            //and
            case and :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = and;

                break;
            //jr jump register
            case jr :
                //PC = R[rs] - this is what it says on the green sheet
                break;
            //nor
            case nor :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = nor;

                break;
            //or
            case or :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = or;

                break;
            //slt - set less than
            case slt :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = slt;

                break;
            //sltu - set less than unsigned
            case sltu :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = sltu;

                break;
            //sll - shift left logical
            case sll :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = sll;


                break;

            //srl - shift right logical
            case srl :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = srl;


                break;

            //sub - subtract
            case sub :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = sub;

                break;

            //subu - subtract unsigned
            case subu :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = subu;

                break;

            //movn - move conditional on not zero
            case movn :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = movn;

                break;

            //movz - move conditional on zero
            case movz :
                IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.Rd = IFID.Rd;
                IDEX.shamt = IFID.shamt;
                IDEX.ALUop = movz;

                break;

        }

    }
    //J Type
    else if(IFID.Opcode == 0x0002 || IFID.Opcode == 0x0003){
        //decide what to do with the J type inst based on its opcode
        switch(IFID.Opcode){


        }

    }
    //I Type
    else {
        //decide what to do with the I type inst based on its opcode
        switch(IFID.Opcode){
            //beq
            case beq :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = beq;
                IDEX.immediate = IFID.immediate;

                break;
            //bne
            case bne :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = bne;
                IDEX.immediate = IFID.immediate;

                break;
            //addi
            case addi :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = addi;
                IDEX.immediate = IFID.immediate;

                break;
            //addiu
            case addiu :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = addiu;
                IDEX.immediate = IFID.immediate;

                break;
            //slti
            case slti :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = slti;
                IDEX.immediate = IFID.immediate;

                break;
                //sltiu
            case sltiu :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = sltiu;
                IDEX.immediate = IFID.immediate;

                break;
                //andi
            case andi :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = andi;
                IDEX.immediate = IFID.immediate;

                break;
            //ori
            case ori :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = ori;
                IDEX.immediate = IFID.immediate;

                break;
            //xori
            case xori :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = xori;
                IDEX.immediate = IFID.immediate;

                break;
            //lui
            case lui :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lui;
                IDEX.immediate = IFID.immediate;

                break;
            //lb
            case lb :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lb;
                IDEX.immediate = IFID.immediate;

                break;
            //lh
            case lh :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lh;
                IDEX.immediate = IFID.immediate;

                break;
            //lw
            case lw :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lw;
                IDEX.immediate = IFID.immediate;

                break;
            //lbu
            case lbu :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lbu;
                IDEX.immediate = IFID.immediate;

                break;
            //lhu
            case lhu :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = lhu;
                IDEX.immediate = IFID.immediate;

                break;
            //sb
            case sb :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = sb;
                IDEX.immediate = IFID.immediate;

                break;
            //sh
            case sh :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = sh;
                IDEX.immediate = IFID.immediate;

                break;

            //sw
            case sw :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = sw;
                IDEX.immediate = IFID.immediate;

                break;

            //bgtz
            case bgtz :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = bgtz;
                IDEX.immediate = IFID.immediate;

                break;

            //bltz
            case bltz :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = bltz;
                IDEX.immediate = IFID.immediate;

                break;

            //blez
            case blez :
                //IDEX.regWrite = true;
                rsRegDetermination(IFID.Rs);
                rtRegDetermination(IFID.Rt);
                IDEX.ALUop = blez;
                IDEX.immediate = IFID.immediate;

                break;

        }
    }

    return;
}

void execute(){
    //determine the operation
    switch(IDEX.ALUop){
        //shift left logical
        case sll :
            EXMEM.ALUresult = shiftLeftLogical(IDEX.RtValue, IDEX.shamt);
            break;

        //shift right logical
        case srl :
            EXMEM.ALUresult = shiftRightLogical(IDEX.RtValue, IDEX.shamt);
            break;

        //jump register
        /*
        case jr :

            break;
        */

        //add
        case add :
            EXMEM.ALUresult = addition(IDEX.RsValue, IDEX.RtValue);
            break;

        //add unsigned
        case addu :
            EXMEM.ALUresult = addUnsigned(IDEX.RsValue, IDEX.RtValue);
            break;

        //subtract
        case sub :
            EXMEM.ALUresult = subtract(IDEX.RsValue, IDEX.RtValue);
            break;

        //subtract unsigned
        case subu :
            EXMEM.ALUresult = subtractUnsigned(IDEX.RsValue, IDEX.RtValue);
            break;

        //and
        case and :
            EXMEM.ALUresult = andOperation(IDEX.RsValue, IDEX.RtValue);
            break;

        //or
        case or :
            EXMEM.ALUresult = orOperation(IDEX.RsValue, IDEX.RtValue);
            break;

        //xor
        case xor :
            EXMEM.ALUresult = xorOperation(IDEX.RsValue, IDEX.RtValue);
            break;

        //nor
        case nor :
            EXMEM.ALUresult = norOperation(IDEX.RsValue, IDEX.RtValue);
            break;

        //set less than
        case slt :
            EXMEM.ALUresult = setLessThan(IDEX.RsValue, IDEX.RtValue);
            break;

        //set less than unsigned
        case sltu :
            EXMEM.ALUresult = setLessThanUnsigned(IDEX.RsValue, IDEX.RtValue);
            break;

        //move non zero
        case movn :
            //EXMEM.ALUresult = moveNonZero(IDEX.RsValue, IDEX.RtValue);
            break;

        //move zero
        case movz :
            //EXMEM.ALUresult = moveZero(IDEX.RsValue, IDEX.RtValue);
            break;
    }
    return;
}



/*******************************************************************************
██████╗ ██╗██████╗ ███████╗██╗     ██╗███╗   ██╗███████╗
██╔══██╗██║██╔══██╗██╔════╝██║     ██║████╗  ██║██╔════╝
██████╔╝██║██████╔╝█████╗  ██║     ██║██╔██╗ ██║█████╗
██╔═══╝ ██║██╔═══╝ ██╔══╝  ██║     ██║██║╚██╗██║██╔══╝
██║     ██║██║     ███████╗███████╗██║██║ ╚████║███████╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝╚═╝╚═╝  ╚═══╝╚══════╝
*******************************************************************************/

void IF(unsigned long machCode){
    //find data in memory

    //find out instruction type and decode that type
    typeSelect(efoff);
    return;
}

void ID(unsigned long machCode){
    //find out what we're supposed to do with the instruction
    executeDetermination();

    return;
}

void EX(){
    EXMEM.regWrite = IDEX.regWrite;
    EXMEM.ALUop = IDEX.ALUop;
    EXMEM.Rd = IDEX.Rd;
    EXMEM.Rt = IDEX.Rt;
    EXMEM.immediate = IDEX.immediate;
    EXMEM.PCinc = IDEX.PCinc;

    //do the ALU operation
    execute();

    return;
}

void MEM(){


    return;
}

void WB(){


    return;
}

/******************************************************************************
███╗   ███╗ █████╗ ██╗███╗   ██╗
████╗ ████║██╔══██╗██║████╗  ██║
██╔████╔██║███████║██║██╔██╗ ██║
██║╚██╔╝██║██╔══██║██║██║╚██╗██║
██║ ╚═╝ ██║██║  ██║██║██║ ╚████║
╚═╝     ╚═╝╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝
******************************************************************************/


int main(){

    ID(efoff);

    unsigned long res = 0x00000001;
    unsigned int val = 0x0002;
    printInBinary(res,0);
    res = res << val;
    printInBinary(res,0);

    unsigned long a = 0xaaaaaaaa;
    unsigned long b = 0x55555555;

    unsigned long c = setLessThan(b,a);
    printInBinary(a,0);
    printInBinary(b,0);
    printInBinary(c,0);

    short int immed = 0xffff;
    unsigned short int uImmed = immed;
    unsigned long result;
    result = (uImmed << 16);
    printInBinary(result, 0);




    /*
    printInBinary( (uint32_t) IFID.Opcode , 0 );
    printInBinary( (uint32_t) IFID.Rs , 0 );
    printInBinary( (uint32_t) IFID.Rt , 0 );
    printInBinary( (uint32_t) IFID.Rd , 0 );
    printInBinary( (uint32_t) IFID.shamt , 0 );
    printInBinary( (uint32_t) IFID.funct , 0 );
    printInBinary( (uint32_t) IFID.immediate , 0 );
    printInBinary( (uint32_t) IFID.jumpaddress , 0 );
    printInBinary( (uint32_t) IFID.PCinc , 0 );
    */


    return 0;
}
