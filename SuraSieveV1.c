#include "master.h"

unsigned long priminatorv4(bool *primes, bool *helper, unsigned long n){

    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;
    // unsigned long helper_size = size/2+1;

    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;
            // printf("%lu\n", val);
            unsigned long k = val;

            if(val<sqrt(n)+1){
                
                while(k*val<n+1){
                    
                    if(!primes[k-2]){
                        if(k*val<n/val+1){
                            helper[k*val-2]=true;
                        }else{
                            primes[k*val-2]=true;
                        }
                    }
                    
                    if(helper[k-2]){
                        primes[k-2]=true;
                    }

                    k++;
                    
                }
            }

        }
        i++;
    }

    return p_count;
}

