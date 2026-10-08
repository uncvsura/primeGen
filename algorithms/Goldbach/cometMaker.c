#include "algos.h"

void cometMaker(uint32_t n){

    bool *primes = malloc(n+1);

    priminatorv8(primes,n,false);

    #pragma omp parallel for num_threads(10)

    for(uint32_t even=4; even <= n; even+=2){

        uint32_t pair = pairFind(primes,even,0);

        printf("%d %d\n",even,pair);

    }

    free(primes);
    primes=NULL;
}

