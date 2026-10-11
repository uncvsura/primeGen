#include "algos.h"

void setBit(uint8_t *x, int i){*x = *x | (1<<i);}

void clearBit(uint8_t *x, int i){*x = *x & ~(1<<i);}

uint8_t checkBit(uint8_t *x, int i){return *x & (1<<i);}

uint64_t priminatorv9(uint8_t *primes, uint64_t n, bool print){

    uint64_t prime = 0;

    clearBit(&primes[0], 0); clearBit(&primes[0], 1);

    uint64_t p_count = 4;

    uint64_t size = (n/8)+1;

    uint64_t mult_bound = (int)(sqrt(n)/8) + 1;

    uint64_t count_bound = size-1;

    for(uint64_t i = 2; i < n/2+1; i++){
        clearBit(&primes[i>>2], (i<<1)&7);
    }

    for(uint64_t i = 3; i < n/3 + 1; i+=2){
        clearBit(&primes[(3*i)>>3], (i*3)&7);
    }

    for(uint64_t i = 5; i < n/5 + 1; i+=2){
        clearBit(&primes[(5*i)>>3], (i*5)&7);
    }

    for(uint64_t i = 7; i < n/7 + 1; i+=2){
        clearBit(&primes[(7*i)>>3], (i*7)&7);
    }

    for(uint64_t i = 1; i < mult_bound; i++){

        for(int p = 1; p < 8; p+=2){

            if(checkBit(&primes[i],p)){

                prime = (i<<3)+p;

                uint64_t max_bound = n/prime + 1;

                for(uint64_t k = prime; k < max_bound; k+=2){
                    clearBit(&primes[(prime*k)>>3],(prime*k)&7);
                }

                p_count++;
            }
        }
    }

    for(uint64_t i = mult_bound; i < count_bound; i++){

            for(int p = 1; p < 8; p+=2){

                if(checkBit(&primes[i],p)){

                    p_count++;

                }
            }
    }

    if(primes[size-1]){

        for(int p = 0; p < 8; p++){

            if(checkBit(&primes[size-1],p)){

                prime = (size-1)*8+p;

                if(prime<=n){
                    p_count++;
                }
            }
        }
    }

    if(print){

        for(uint64_t i = 0; i < size-1; i++){
            if(primes[i]){

                for(int p = 0; p < 8; p++){
    
                    if(checkBit(&primes[i],p)){
    
                        prime = i*8+p;
                        printf("%llu\n", prime);
                    }
                }
            }
        }

        if(primes[size-1]){
            for(int p = 0; p < 8; p++){

                if(checkBit(&primes[size-1],p)){
    
                    prime = (size-1)*8+p;
    
                    if(prime<=n){
                        printf("%llu\n", prime);
                    }
                }
            }
        }
    }

    return p_count;
}