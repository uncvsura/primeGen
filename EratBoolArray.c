#include "master.h"

unsigned long priminatorv2(bool *arr, unsigned long n){

    unsigned long size = n-1;
    unsigned long i = 0;
    unsigned long prime_count = 0;

    while(i<size){
        if(!arr[i]){
            unsigned long val = i+2;
            // printf("%lu\n", val);
            prime_count++;
            if(val<n/2+1){
                unsigned long k = 2;
                while(val*k<n+1){
                    arr[k*val-2]=true;
                    k++;
                }
            }
        }
        i++;
    }

    return prime_count;
}