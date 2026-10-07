#include "header/algos.h"

void cometMaker(uint32_t n){
    uint32_t even=4;
    while(even<=n){
        uint32_t pair = pairFind(even,0);
        printf("%d %d  ",even,pair);
        even+=2;
    }
}

int main(void){
    uint32_t num;
    printf("Enter even number:\n");
    scanf("%d",&num);

    cometMaker(num);

    return 0;
}