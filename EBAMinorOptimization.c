#include "master.h"

unsigned long priminatorv3(bool *primes, unsigned long n){

    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;


    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;
            printf("%lu\n", val);

            if(val<sqrt(n)+1){
                unsigned long k = val;
                while(val*k<n+1){
                    primes[k*val-2]=true;
                    k++;
                }
            }
        }
        i++;
    }
    return p_count;
}