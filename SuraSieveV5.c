#include "master.h"

unsigned long priminatorv8(bool *primes, unsigned long n, bool print){

    unsigned long p_count = 0;
    unsigned long i = 0;

    unsigned long size = n-1;

    while(i<size){

        if(!primes[i]){

            unsigned long val = i+2;
            p_count++;

            if(print){printf("%lu ",val);}


            if(val<sqrt(n)+1){

                unsigned long k = val;
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