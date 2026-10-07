#include "algos.h"

void cometMaker(uint32_t n){
    uint32_t even=4;
    while(even<=n){
        uint32_t pair = pairFind(even,0);
        printf("%d %d\n",even,pair);
        even+=2;
    }
}

