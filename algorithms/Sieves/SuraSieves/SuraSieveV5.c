#include "algos.h"

uint32_t priminatorv8(bool *primes, uint32_t n, bool print){

    uint32_t p_count = 0;
    uint32_t i = 0;

    uint32_t size = n-1;

    while(i<size){

        if(!primes[i]){

            uint32_t val = i+2;
            p_count++;

            if(print){printf("%d ",val);}


            if(val<sqrt(n)+1){

                uint32_t k = val;
                if(val==2){
                    while(k<<1<n+1){
                        primes[(k<<1)-2]=true;
                        k++;
                    }
                }else if (val==3){
                    while(k*val<n+1){
                        primes[k*3-2]=true;
                        k+=2;
                    }
                }else if(val==5){
                    while(k*val<n+1){
                        primes[val*k-2]=true;
                        if(k%6==1){
                            k+=4;
                        }else{
                            k+=2;
                        }
                    }
                }else{
                    while(k*val<n+1){
                        primes[val*k-2]=true;
                        if(k%30==1||k%30==23){
                            k+=6;
                        }
                        else if(k%6==1){
                            k+=4;
                        }else{
                            k+=2;
                        }
                    }
                }
            }

        }
        i++;
    }

    return p_count;
}