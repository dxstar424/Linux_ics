/*
*IEEE754标准构造浮点数
*选择double类型
*/
#include <stdio.h>
#include<stdint.h>

void print_binary_64_double(uint64_t num){
    for(int i = 63 ; i >= 0 ; i--){
        printf("%ld",(num>>i)&1);
        if(i==63||i==52){
            printf("|");
        }
    }
    printf("\n");
}
double construct_double(uint64_t sign,uint64_t exp,uint64_t frac){
    uint64_t bits = (sign<<63|exp<<52|frac);
    double f;
    *(uint64_t *)&f=bits;
    return f;
}

void print_constrcut_num(uint64_t sign,uint64_t exp,uint64_t frac){
    double f = construct_double(sign,exp,frac);
    printf("浮点数%f \n二进制表示:",f);
    print_binary_64_double(f);
}

int main(){
    //20250309 sign=0; exp= 24+1023 =1047; frag = 0b1001101001111111011000101
    print_constrcut_num(0,1047, 0b1001101001111111011000101);
    double f=20250309;
    print_binary_64_double(f);

    print_constrcut_num(1,1047, 0b1001101001111111011000101);
    print_constrcut_num(1,0x3FB, 0x0000000000000);
    print_constrcut_num(0, 0x7FF, 0x0000000000000);
    print_constrcut_num(0, 0x7FF, 0x8000000000000);
    
    return 0;
}