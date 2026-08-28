#include "master.h"

unsigned long priminatorv6(bool *primes, unsigned long n){

    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;


    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;

            unsigned long k = val;

            if(val<sqrt(n)+1){

                unsigned long thresh = n/pow(val,2);
                
                while(k*val<n+1){
                    if(!primes[k-2]){
                        if(k>thresh){
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

