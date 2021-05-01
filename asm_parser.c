/**
 * The functions are declared in asm_parser.h
 * The intention of this library is to parse an .ASM file
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"



/************************************ PROBLEM 5 ********************************************/
//helper function to swap bytes
unsigned short int swap_endian(unsigned short int number){
    //printf("number before swap = 0%x\n", number);
    unsigned short int byte0, byte1, swap;
    byte0 = (number & 0x00FF) >> 0;
    byte1 = (number & 0xFF00) >> 8;
    swap = ((byte0 << 8) | (byte1<< 0));
    //printf("number after swap = 0%x\n", swap);
    return swap;
}


int write_obj_file (char* filename, unsigned short int program_bin[ROWS] ) {

    //STEP 1: read in filename and change the last 3 letters to "obj"
    //printf("filename = %s", filename);
    int len = strlen(filename);
    int num1 = strlen(filename)-3;

    char newname[200];
    memset(newname, '\0', 200);

    for(int i = 0; i < num1; i++){
        newname[i] = filename[i];
    }

    strcat(newname, "obj");



    //STEP 2: open up the newfile name for writing
    FILE* fp;

    fp = fopen(newname, "wb");
    if(fp == NULL){
        printf("error7: Unable to open output file.\n");
        return 7;
    }


    //write 0xCADE directive to file
    unsigned short int cade[1] = {0};
    cade[0] = 0xCADE;
    unsigned short int *cadePtr = &cade[0];
    *cadePtr = swap_endian(cade[0]);
    fwrite((void *) cadePtr, sizeof(unsigned short int), 1, fp);

    //write address directive 0x0000 to file
    unsigned short int addr[1] = {0};
    addr[0] = 0x0000;
    unsigned short int *addrPtr = &addr[0];
    *addrPtr = swap_endian(addr[0]);
    fwrite((void *) addrPtr, sizeof(unsigned short int), 1, fp);

    int i = 0; //this is the number of rows in program_bin
    for(; program_bin[i];i++);
    //printf("i = %d", i);
    int p = i;

    //write the n = number of rows, to the file
    unsigned short int n[1] = {0};
    n[0] = (unsigned short int) i;
    unsigned short int *nPtr = &n[0];
    *nPtr = swap_endian(n[0]);
    fwrite((void *) nPtr, sizeof(unsigned short int), 1, fp);


    unsigned short int  swapped_value;  //OMG THIS IS WORKING

    //Call helper function to swap bytes in each row, then write to output file
    unsigned short int binArr[i];
    int counter = 0;
    while (i > 0){
        swapped_value = swap_endian(program_bin[counter]);
        binArr[counter] = swapped_value;
        i--;
        counter++;
    }

    fwrite((void *) binArr, sizeof(unsigned short int), p, fp);

    fclose(fp);

    return 0;
}

/************************************ PROBLEM 4 ********************************************/
//Converts one row of string binary to binary and returns it to appropriate row in program_bin[]
unsigned short int str_to_bin (char* instr_bin_str){

    unsigned short int bin_number = strtol(instr_bin_str, 0x0, 2);
    //printf("the converted number is: 0x%X\n ", bin_number);

    return bin_number;
}


/************************************ PROBLEM 3 ********************************************/
//helper function for parse_instruction().  Parses the number data in registers 1-7 from string number to string binary
int parse_reg (char reg_num, char* instr_bin_str) {
    //printf("in the parse_reg\n");

    if(reg_num == '0'){
        strcat(instr_bin_str, "000");
    } else if(reg_num == '1'){
        strcat(instr_bin_str, "001");
    } else if(reg_num == '2'){
        strcat(instr_bin_str, "010");
    } else if(reg_num == '3'){
        strcat(instr_bin_str, "011");
    } else if(reg_num == '4'){
        strcat(instr_bin_str, "100");
    } else if(reg_num == '5'){
        strcat(instr_bin_str, "101");
    } else if(reg_num == '6'){
        strcat(instr_bin_str, "110");
    } else if(reg_num == '7'){
        strcat(instr_bin_str, "111");
    } else {
        printf("error4: error in the register load.\n");
        return 4;
    }

    return 0;
}

//helper functions for parse_instruction(). Parses the arithmetic signal into appropriate op/subop codes and calls
//parse_reg to parse register data
int parse_add(char* instr , char* instr_bin_str){
    //printf("in the parse_add\n");

    sscanf("0001", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "000");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_add() failed.\n");
        return 4;
    }
    return 0;
}
int parse_mul(char* instr , char* instr_bin_str){
    //printf("in the parse_mul\n");

    sscanf("0001", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "001");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_mul() failed.\n");
        return 4;
    }
    return 0;
}
int parse_sub(char* instr , char* instr_bin_str){
    //printf("in the parse_sub\n");

    sscanf("0001", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "010");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_sub() failed.\n");
        return 4;
    }
    return 0;
}
int parse_div(char* instr , char* instr_bin_str){
    //printf("in the parse_div\n");

    sscanf("0001", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "011");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_div() failed.\n");
        return 4;
    }
    return 0;
}
int parse_and(char* instr , char* instr_bin_str){
    //printf("in the parse_and\n");

    sscanf("0101", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "000");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_and() failed.\n");
        return 4;
    }
    return 0;
}
int parse_not(char* instr , char* instr_bin_str){
    //printf("in the parse_not\n");

    sscanf("0101", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "001");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_not() failed.\n");
        return 4;
    }
    return 0;
}
int parse_or(char* instr , char* instr_bin_str){
    //printf("in the parse_or\n");

    sscanf("0101", "%s", instr_bin_str);
    if(*(instr+3) == 'R'){
        parse_reg(*(instr+4), instr_bin_str);
        parse_reg(*(instr+8), instr_bin_str);
        strcat(instr_bin_str, "010");
        parse_reg(*(instr+12), instr_bin_str);
    } else {
        printf("error4: parse_or() failed.\n");
        return 4;
    }
    return 0;
}
int parse_xor(char* instr , char* instr_bin_str){
    //printf("in the parse_xor\n");

    sscanf("0101", "%s", instr_bin_str);
    if(*(instr+4) == 'R'){
        parse_reg(*(instr+5), instr_bin_str);
        parse_reg(*(instr+9), instr_bin_str);
        strcat(instr_bin_str, "011");
        parse_reg(*(instr+13), instr_bin_str);
    } else {
        printf("error4: parse_xor() failed.\n");
        return 4;
    }
    return 0;
}


/************************************ PROBLEM 2 ********************************************/
//reads each row of the assembler instruction and calls helper functions to parse opcodes/subopcodes and registers
int parse_instruction (char* instr , char* instr_bin_str) {
    //printf("in the parse_instructions\n");

    // printf("%s\n", instr );

    if(strstr(instr, "ADD")){
        parse_add(instr, instr_bin_str);
    } else if(strstr(instr, "MUL")){
        parse_mul(instr, instr_bin_str);
    } else if(strstr(instr, "SUB")){
        parse_sub(instr, instr_bin_str);
    } else if(strstr(instr, "DIV")){
        parse_div(instr, instr_bin_str);
    } else if(strstr(instr, "AND")){
        parse_and(instr, instr_bin_str);
    } else if(strstr(instr, "NOT")){
        parse_not(instr, instr_bin_str);
    } else if(strstr(instr, "X") && strstr(instr, "OR")){
        parse_xor(instr, instr_bin_str);
    } else if(strstr(instr, "OR")){
        parse_or(instr, instr_bin_str);
    } else {
        return 3;
    }

    //printf("newArr = %s\n ", newArr);
    //printf("instr_bin_str = %s\n ", instr_bin_str);
    //printf("instr = %s ", instr);
//    for(int i = 0; i < 15; i++){
//        //printf("%c", instr[i] );
//
//    }

    return 0;

}

/************************************ PROBLEM 1 ********************************************/
//read in the .asm file data and put it into program[][] array. Each row is an assembler instruction
int read_asm_file (char* filename, char program [ROWS][COLS] ) {
    FILE *src_file;
    src_file = fopen(filename, "r");
    if(src_file == NULL){
        return 2;
    }

    int rowNum = 0;
    int colNum = 0;


    while(!feof(src_file)){
        char c;
        fscanf(src_file, "%c", &c);
        if(c == '\n'){
            program[rowNum][colNum] = '\0';
            rowNum++;
            colNum = 0;
        }   else {
            program[rowNum][colNum] = c;
            colNum++;
        }
    }

    fclose(src_file);
    return 0;
}