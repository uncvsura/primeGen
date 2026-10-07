#include "algos.h"

uint32_t pairFind(uint32_t even, bool print){

    uint32_t size = even+1;
    uint32_t pairCount = 0;

    bool *primes = malloc(size);

    priminatorv8(primes,size,false);
    
    uint32_t i = 0;

    while(i+2<even/2){

        if(!primes[i]){

            uint32_t val = i + 2;

            if(!primes[even-val-2]){

                if(print){printf("(%d,%d)\n",val,even-val);}
                
                pairCount++;

            }
        }
        i++;
    }

    free(primes);
    primes = NULL;

    return pairCount;
}