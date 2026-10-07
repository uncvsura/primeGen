#include "algos.h"

uint32_t pairFind(bool *primes, uint32_t even, bool print){

    uint32_t pairCount = 0;
    
    uint32_t i = 0;

    while(i+2<=even/2){

        if(!primes[i]){

            uint32_t val = i + 2;

            if(!primes[even-val-2]){

                if(print){printf("(%d,%d)\n",val,even-val);}
                
                pairCount++;

            }
        }
        i++;
    }

    return pairCount;
}