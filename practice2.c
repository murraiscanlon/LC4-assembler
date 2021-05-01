//#include <string.h>
//#include <stdio.h>
//
//
//
//int main(){
//    char instr[] = "ADD R1, R0, R1";
//    char instr_bin[] = {0};
//    int regCounter = 0;
//
//    if(*instr == 'A') {
//        //printf("instr = %s \n", instr);
//        printf("instr-bin1 = %s \n", instr_bin);
//
//        //call parse_add()
//        sscanf("0001", "%s", instr_bin); //src_string first
//        printf("instr-bin2 = %s \n", instr_bin);
//        sscanf("AAA", "%s", instr_bin+10); //src_string first
//        printf("instr-bin2.a = %s \n", instr_bin);
//
//
//        //call parse_reg
//        int reg = 0;
//        int i = 4;
//        while (i < 17){
//            //printf("instr[i]: %c - instr[i+1]: %c \n", instr[i], instr[i+1]);
//            //printf("In the while: ");
//
//            switch(instr[i]){
//
//
//                case '0': strcat(instr_bin, "000");
//                    break;
//                case '1': strcat(instr_bin, "001");
//                    break;
//                case '2': strcat(instr_bin, "010");
//                    break;
//                case '3': strcat(instr_bin, "011");
//                    break;
//                case '4': strcat(instr_bin, "100");
//                    break;
//                case '5': strcat(instr_bin, "101");
//                    break;
//                case '6': strcat(instr_bin, "110");
//                    break;
//                case '7': strcat(instr_bin, "111");
//                    break;
//                case 'R': regCounter++;
//                     break;
//                default:
//                    break;
//
//            }
//
//            if (regCounter == 3){
//                strcat(instr_bin, "000");
//            }
//            i++;
//
//        }
//
//        //printf("regBin = %s\n", regBin);
//        printf("instr_bin3 = %s\n", instr_bin);
//
//
//
//
//
//
//    }
//
//
//}
////
////switch (n)
////{
////case 1: // code to be executed if n = 1;
////break;
////case 2: // code to be executed if n = 2;
////break;
////default: // code to be executed if n doesn't match any cases
////}