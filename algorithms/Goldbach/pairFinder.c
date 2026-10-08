#include "algos.h"

uint32_t pairFind(bool *primes, uint32_t even, bool print){

    uint32_t pairCount = 0;

    // #pragma omp parallel for num_threads(4)

    for(uint32_t val = 2; val <= even/2; val++){

        if(!primes[val-2]){

            if(!primes[even-val-2]){

                if(print){printf("(%d,%d)\n",val,even-val);}
                
                pairCount++;

            }
        }
    }

    return pairCount;
}