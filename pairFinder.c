#include "master.h"
#include "SuraSieveV5.c"

unsigned long pairFind(unsigned long even){

    unsigned long size = even+1;
    unsigned long pairCount = 0;

    bool *primes = malloc(size);

    priminatorv8(primes,size);

    unsigned long i = 0;

    while(i<size/2){

        if(!primes[i]){

            unsigned long val = i + 2;

            if(!primes[even-val-2]){

                printf("(%lu,%lu)\n",val,even-val);
                pairCount++;

            }
        }
        i++;
    }

    free(primes);
    primes = NULL;

    return pairCount;
}

int main(void){

    unsigned long num;

    printf("Enter even number:\n");
    scanf("%lu", &num);

    unsigned long pairCount = pairFind(num);

    printf("G(%lu): %lu\n",num,pairCount);

    return 0;

}