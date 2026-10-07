#include "algos.h"

void cometMaker(uint32_t n){

    bool *primes = malloc(n+1);

    priminatorv8(primes,n,false);

    uint32_t even=4;

    while(even<=n){
        uint32_t pair = pairFind(primes,even,0);

        printf("%d %d\n",even,pair);

        even+=2;
    }

    free(primes);
    primes=NULL;
}

