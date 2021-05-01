//#include <string.h>
//#include <stdio.h>
//
//
//
//
//int main() {
//    char instr[] = "ADD R0, R2, R1";
//    char instr_bin[] = {0};
//
//
//    printf("instr: %s\n", instr);
//    printf("instr_bin: %s\n", instr_bin);
//
//    /*****************************INCOMING DATA ABOVE*****************************/
//
//    //storage locations for parsing out the instruction string
//    char op[4];
//    char rd[3];
//    char rs[3];
//    char subop[3] = {'\0'};
//    char rt[3];
//
//    //testing
//    printf("subop1: %s\n", subop);
//    //printf("rd1: %s\n", rd);
//
//    //parsing out the instruction string
//    char *token;
//
//    //get the first token
//    token = strtok(instr, ", "); //use a literal for right now. . .no problems
//    sscanf(token, "%s", op);
//    printf("op: %s\n", op);
//
//    //get second token
//    token = strtok(NULL, ", ");
//    sscanf(token, "%s", rd);
//    //printf("token: %s\n", token);
//    printf("rd: %s\n", rd);
//
//    //get third token
//    token = strtok(NULL, ", ");
//    sscanf(token, "%s", rs);
//    //printf("token: %s\n", token);
//    //printf("rs: %s\n", rs);
//
//    //get fourth token
//    token = strtok(NULL, ", ");
//    sscanf(token, "%s", rt);
//    //printf("token: %s\n", token);
//    //printf("rt: %s\n", rt);
//
//    /*********************************MATCH OP AND SUBOP*******************************************/
//    if(strstr(instr, "ADD")){
//        //printf("ADD it is!!");
//        //op = {'0', '0', '0', '1'}; This doesn't work,not sure why
//        op[0] = '0';
//        op[1] = '0';
//        op[2] = '0';
//        op[3] = '1';
//        subop[0] = '0'; //THIS IS NOT PRINTING OUT CORRECTLY AS %S
//        subop[1] = '0';
//        subop[2] = '0';
//    }
//
//
//    printf("op: %s\n", op);
//    printf("subop: %c%c%c \n", subop[0], subop[1], subop[2]);
//
//    /**********************MATCH REGISTERS*****************************/
//    int regCounter = 0;
//    if(*rd == 'R') {
//        //printf("rd[0] = R yay!!\n");
//        regCounter++;
//        switch(rd[1]){
//            case '0':
//                rd[0] = '0';
//                rd[1] = '0';
//                rd[2] = '0';
//                break;
//            case '1':
//                rd[0] = '0';
//                rd[1] = '0';
//                rd[2] = '1';
//                break;
//            case '2':
//                rd[0] = '0';
//                rd[1] = '1';
//                rd[2] = '0';
//                break;
//            case '3':
//                rd[0] = '0';
//                rd[1] = '1';
//                rd[2] = '1';
//                break;
//            case '4':
//                rd[0] = '1';
//                rd[1] = '0';
//                rd[2] = '0';
//                break;
//            case '5':
//                rd[0] = '1';
//                rd[1] = '0';
//                rd[2] = '1';
//                break;
//            case '6':
//                rd[0] = '1';
//                rd[1] = '1';
//                rd[2] = '0';
//                break;
//            case '7':
//                rd[0] = '1';
//                rd[1] = '1';
//                rd[2] = '1';
//                break;
//            default:
//                printf("error in register number");
//
//        }
//
//    }
//
//    printf("rd2: %c%c%c ", rd[0], rd[1], rd[2]);
//    char *add = strstr(instr, "ADD"); //needle in haystack
//    //printf("add_bool: %p \n", add);//returns address of 'A' if match, otherwise 0000000's
//
//
//    //char registers[10];
//
//
//
//
//
//    //walk through the other tokens
////    printf("entering the while: \n");
////    while(token != NULL){
////        printf("token: %s\n", token);
////        strcat(registers, token);
////        printf("registers: %s\n", registers);
////
////        token = strtok(NULL, ", ");
////    }
//
//    //printf("op: %s \n", op);
//    //printf("op: %s \n", registers);
//
////    sscanf(instr, "%s", op);
////    printf("op: %s \n", op);
//
//    //printf("*(token): %c", *token);
//
//    return 0;
//
//
//}