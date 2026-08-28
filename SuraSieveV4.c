#include "master.h"

unsigned long priminatorv7(bool *primes, unsigned long n){
    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;
    int j;

    unsigned long prev_p;
    bool incr = true;

    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;

            // printf("%lu\n", val);

            if(val<sqrt(n)+1){

                unsigned long k = val;
                
                while(k*val<n+1){
                    primes[val*k-2]=true;
                    if(val>3&&k%3==1){
                        k+=2;
                    }
                    k += val>2 ? 2:1;
                    
                }
            }
        }
        i++;
    }

    return p_count;
}