#include "master.h"
#include "SuraSieveV5.c"

unsigned long pairFind(unsigned long even, bool print){

    unsigned long size = even+1;
    unsigned long pairCount = 0;

    bool *primes = malloc(size);

    printf("Generating primes...\n");

    priminatorv8(primes,size,false);

    printf("Finding pairs...\n");
    
    unsigned long i = 0;

    while(i<size/2){

        if(!primes[i]){

            unsigned long val = i + 2;

            if(!primes[even-val-2]){

                if(print){printf("(%lu,%lu)\n",val,even-val);}
                
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

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");

    unsigned long pairCount = pairFind(num,print);

    printf("G(%lu): %lu\n",num,pairCount);

    return 0;

}