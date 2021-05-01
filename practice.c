//#include <string.h>
//#include <stdio.h>
//
//
//
//int main(){
//    FILE *src_file = fopen("C://Users//Murrai.Scanlon//CLionProjects//593_Assignment12//test1.asm", "r");
//    FILE *des_file = fopen("C:/Users/Murrai.Scanlon/CLionProjects/593_Assignment12/output2.txt", "w");
//
//    if(src_file == NULL){
//        return 2;
//    }
//
//    if(des_file == NULL){
//        return 3;
//    }
//
//    //char str1[] = "hello AGAIN world, in C!";
//
//    do{
//        char c = fgetc(src_file);
//        if (feof(src_file)){
//            printf("done reading the file!\n");
//            break;
//        }
//
//        fputc(c, des_file);
//
//    }while(1);
//
////    for(int i = 0; str1[i] != '\0'; i++){
////        fputc(str1[i], des_file);
////    }
//
//    fclose(des_file);
//    fclose(src_file);
//
//
//    return 0;
//}
