#include "algos.h"

#include "algos.h"

void setBit(uint8_t *x, int i){*x = *x | (1<<i);}

void clearBit(uint8_t *x, int i){*x = *x & ~(1<<i);}

uint8_t checkBit(uint8_t *x, int i){return *x & (1<<i);}

uint64_t priminatorv10(uint8_t *primes, uint64_t n, bool print){

    uint64_t prime = 0;

    clearBit(&primes[0], 0); clearBit(&primes[0], 1);

    uint64_t p_count = 6;

    uint64_t size = (n/8)+1;

    uint64_t mult_bound = (int)(sqrt(n)/8) + 1;

    uint64_t count_bound = size-1;

    clock_t two_s,two_e,three_s,three_e,five_s,five_e,seven_s,seven_e,eleven_s,eleven_e,thirteen_s,thirteen_e,major_s,major_e,check_s,check_e;
    double twotime,threetime,fivetime,seventime,eleventime,thirteentime,majortime,checktime;

    two_s = clock();

    for(uint64_t i = 2; i < n/2+1; i++){
        clearBit(&primes[i>>2], (i<<1)&7);
    }
    two_e = clock();

    three_s = clock();

    for(uint64_t i = 3; i < n/3 + 1; i+=2){
        clearBit(&primes[(3*i)>>3], (i*3)&7);
    }
    three_e = clock();

    five_s = clock();

    for(uint64_t i = 5; i < n/5 + 1; i+=2){
        clearBit(&primes[(5*i)>>3], (i*5)&7);
    }

    // for(uint64_t i = 7; i < n/5 + 1; i+=6){
    //     clearBit(&primes[(5*i)>>3], (i*5)&7);
    // }
    five_e = clock();

    seven_s = clock();
    // for(uint64_t i = 7; i < n/7 + 1; i+=2){
    //     clearBit(&primes[(7*i)>>3], (i*7)&7);
    // }

    for(uint64_t pseudo = 7; pseudo < 32; pseudo += 2){
        if(checkBit(&primes[pseudo>>3],pseudo&7)){
            for(uint64_t i = pseudo; i < n/7 + 1; i+=30){
                clearBit(&primes[(7*i)>>3], (i*7)&7);
            }
        }
    }
    seven_e = clock();

    // eleven_s = clock();
    for(uint64_t i = 11; i < n/11 + 1; i+=2){
        clearBit(&primes[(11*i)>>3], (i*11)&7);
    }
    // for(uint64_t pseudo = 11; pseudo < 212; pseudo += 2){
    //     if(checkBit(&primes[pseudo>>3],pseudo&7)){
    //         for(uint64_t i = pseudo; i < n/11 + 1; i+=210){
    //             clearBit(&primes[(11*i)>>3], (i*11)&7);
    //         }
    //     }
    // }
    // eleven_e = clock();

    // thirteen_s = clock();
    for(uint64_t i = 13; i < n/13 + 1; i+=2){
        clearBit(&primes[(13*i)>>3], (i*13)&7);
    }
    // for(uint64_t pseudo = 2310+1; pseudo > 12; pseudo -= 2){
    //     if(checkBit(&primes[pseudo>>3],pseudo&7)){
    //         for(uint64_t i = pseudo; i < n/13 + 1; i+=2310){
    //             clearBit(&primes[(13*i)>>3], (i*13)&7);
    //         }
    //     }
    // }
    // thirteen_e = clock();

    // for(uint64_t pseudo = (2730 + 12)/13; pseudo < 2730 + 2; pseudo++){
    //     if(checkBit(&primes[pseudo>>3],pseudo&7)){
    //         for(uint64_t i = pseudo; i < n/13 + 1; i+=2730){
    //             clearBit(&primes[(13*i)>>3], (i*13)&7);
    //         }
    //     }
    // }
    // for(uint64_t pseudo = 13; pseudo < (2730 + 12)/13 + 1; pseudo+=2){
    //     if(checkBit(&primes[pseudo>>3],pseudo&7)){
    //         for(uint64_t i = pseudo; i < n/13 + 1; i+=2730){
    //             clearBit(&primes[(13*i)>>3], (i*13)&7);
    //         }
    //     }
    // }

    major_s = clock();
    for(uint64_t i = 2; i < mult_bound; i++){

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
    major_e = clock();

    check_s = clock();
    for(uint64_t i = mult_bound; i < count_bound; i++){

            for(int p = 1; p < 8; p+=2){

                if(checkBit(&primes[i],p)){

                    p_count++;

                }
            }
    }
    check_e = clock();

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

    // twotime = ((double)(two_e - two_s))/CLOCKS_PER_SEC;
    // threetime = ((double)(three_e - three_s))/CLOCKS_PER_SEC;
    // fivetime = ((double)(five_e - five_s))/CLOCKS_PER_SEC;
    // seventime = ((double)(seven_e - seven_s))/CLOCKS_PER_SEC;
    // eleventime = ((double)(eleven_e - eleven_s))/CLOCKS_PER_SEC;
    // thirteentime = ((double)(thirteen_e - thirteen_s))/CLOCKS_PER_SEC;
    // majortime = ((double)(major_e - major_s))/CLOCKS_PER_SEC;
    // checktime = ((double)(check_e - check_s))/CLOCKS_PER_SEC;

    // printf("2's time: %f\n", twotime);
    // printf("3's time: %f\n", threetime);
    // printf("5's time: %f\n", fivetime);
    // printf("7's time: %f\n", seventime);
    // printf("11's time: %f\n", eleventime);
    // printf("13's time: %f\n", thirteentime);
    // printf("major's time: %f\n", majortime);
    // printf("check's time: %f\n", checktime);
    // printf("sum = %f\n", twotime+threetime+fivetime+seventime+eleventime+thirteentime+majortime+checktime);

    return p_count;
}