#include "master.h"

unsigned long priminatorv5(bool *primes, unsigned long n){

    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;


    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;
            // printf("%lu\n", val);
            unsigned long k = val;

            if(val<sqrt(n)+1){
                
                while(k*val<n+1){
                    if(!primes[k-2]){
                        if(k*val>n/val){
                            // printf("%lu\n", k*val-2);
                            primes[k*val-2]=true;
                        }
                        if(k%val==0){
                            primes[k-2]=true;
                        }
                    }

                    k++;
                    
                }
            }

        }
        i++;
    }

    return p_count;
}

