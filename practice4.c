//#include <stdio.h>
//#include <string.h>
//
//unsigned short int swap_endian(unsigned short int number){
//    unsigned short int byte0, byte1;
//    byte0 = (number & 0x00FF) >> 0;
//    byte1 = (number & 0xFF00) >> 8;
//    return ((byte0 << 8) | (byte1<< 0));
//}
//
//int main()
//{
//
//    unsigned short int swapped_value;
//    swapped_value = swap_endian(4609);
//    printf("swapped_value = %d", swapped_value);
//
//
////    unsigned short int data=0x1234;
////    printf("\ndata before swapping : %04X",data);
////    data= ((data<<8u)&0xff00)|((data>>8u)&0x00ff);
////    printf("\ndata after swapping  : %04X",data);
//
//
//        return 0;
//    }
