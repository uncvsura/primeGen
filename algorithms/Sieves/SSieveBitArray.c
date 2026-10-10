#include "algos.h"

void setBit(uint8_t *x, int i){*x = *x | (1<<i);}

void clearBit(uint8_t *x, int i){*x = *x & ~(1<<i);}

uint8_t checkBit(uint8_t *x, int i){return *x & (1<<i);}

uint64_t priminatorv9(uint8_t *primes, uint64_t n, bool print){

    uint64_t prime = 0;

    clearBit(&primes[0], 0); clearBit(&primes[0], 1);

    uint64_t p_count = 0;

    uint64_t size = (n/8)+1;

    for(uint64_t i = 0; i < size-1; i++){

        if(primes[i]){

            for(int p = 0; p < 8; p++){

                if(checkBit(&primes[i],p)){

                    prime = (i<<3)+p;

                    if(prime<sqrt(n)+1){

                        uint64_t max_bound = n/prime + 1;

                        if(prime == 2){

                            for(uint64_t k = prime; k < max_bound; k++){

                                clearBit(&primes[k>>2],(k<<1)&0x7);
                            }
                        }else{

                            for(uint64_t k = prime; k < max_bound; k+=2){

                                clearBit(&primes[(prime*k)>>3],(prime*k)&0x7);
                            }
                        }

                    }

                    p_count++;
                }
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
    }

    return p_count;
}