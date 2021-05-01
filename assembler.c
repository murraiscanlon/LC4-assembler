/**
 * This program will assemble a .ASM file into a .OBJ file
 * This program will use the "asm_parser" library to achieve
 * its functionality.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "asm_parser.h"
#include <errno.h>


int countRows(char* filename, char program [ROWS][COLS]);//helper function to count rows in program


int main(int argc, char** argv) {

    char* filename = NULL ;					// name of ASM file
    char  program [ROWS][COLS] ; 			// ASM file line-by-line
    char  program_bin_str [ROWS][17] ; 		// instructions converted to a binary string
    unsigned short int program_bin [ROWS] ; // instructions in binary (HEX)
    int *input_len = {0};
    int filestatus = 0;

    memset(program, 0, sizeof(program));
    memset(program_bin_str, 0, sizeof(program_bin_str));
    memset(program_bin, 0, sizeof(program_bin));

    /************************************* PROBLEM 1 ***********************************************/
    //Parse main args to get filename provided by user
    if(argc < 2){
        printf("error1: usage: ./assembler <assembly_file.asm>\n");
        printf("%s", argv[0]); //testing
        return 1;
    } else {
        filename = argv[1];
    }


    //Open and read the file provided through main() args
    filestatus = read_asm_file (filename, program);
    if (filestatus != 0){
        printf("error2: read_asm_file() failed.\n");
        printf((const char *) filestatus, program);
        return 2;
    }

    /************************************* PROBLEMS 2,3,4 ***********************************************/
    //Use helper function to count the number of rows in the input file
    int numRows = {0};
    numRows = (countRows(filename, program)-1);
    //printf("numRows = %d\n", numRows);


    //Loop through the rows of input calling parse_instruction() and str_to_bin; convert assembler input to binary
    int i = 0;
    for(; i < numRows; i++){
        filestatus = parse_instruction(program[i], program_bin_str[i]);
        if(filestatus == 3){
            printf("error3: parse_instruction() failed.\n");
            return 3;
        }
        if(filestatus == 4){
            return 4;
        }
        unsigned short int num = str_to_bin (program_bin_str[i]) ; //returns bin number and should be put into program_bin appropriate row
        //printf("int num: %d \n", num);
        program_bin[i] = num;
        //printf("program_bin[i]: 0x%x \n", program_bin[i]);

    }

    /************************************* PROBLEM 5 ***********************************************/
    //Write binary to output file
    filestatus = write_obj_file(filename, program_bin);
    if(filestatus != 0){
        //printf("error3: parse_instruction() failed.\n");
        return 7;
    }

    return 0;
}

//Helper function to count rows in input file
int countRows(char* filename, char program [ROWS][COLS]){
    FILE *file;
    file = fopen(filename, "r");

    int rowNum = 0;
    int colNum = 0;


    while(!feof(file)){
        char c;
        fscanf(file, "%c", &c);
        if(c == '\n'){
            program[rowNum][colNum] = '\0';
            rowNum++;
            colNum = 0;
        }   else {
            program[rowNum][colNum] = c;
            colNum++;
        }
    }

    fclose(file);
    return rowNum;
}
