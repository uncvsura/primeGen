#include "master.h"
#include "EratBoolArray.c"
#include "Naive.c"
#include "EBAMinorOptimization.c"
#include "SuraSieveV1.c"
#include "SuraSieveV2.c"
#include "SuraSieveV3.c"
#include "SuraSieveV4.c"
#include "SuraSieveV5.c"



int main(void){

    unsigned long num;
    bool *primes = malloc(num-1);

    int power;
    printf("Enter power of 10:\n");
    scanf("%d", &power);

    num = pow(10,power);

    unsigned long p_count;

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");
    
    p_count = priminatorv8(primes,num,print);

    printf("\n\u03C0(%lu) = %lu\n", num, p_count);


    free(primes);
    primes = NULL;


    return 0;
    
}