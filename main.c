#include "master.h"
#include "EratBoolArray.c"
#include "Naive.c"
#include "EBAMinorOptimization.c"
#include "SuraSieveV1.c"
#include "SuraSieveV2.c"
#include "SuraSieveV3.c"
#include "SuraSieveV4.c"


int main(void){

    unsigned long num;
    bool *primes = calloc(num-1,1);

    int power;
    printf("Enter power of 10:\n");
    scanf("%d", &power);

    num = pow(10,power);

    unsigned long p_count;

    printf("Calculating...\n");
    clock_t start = clock();
    
    p_count = priminatorv7(primes,num);

    printf("\u03C0(%lu) = %lu\n", num, p_count);

    clock_t end = clock();
    double time = ((double) (end - start))/CLOCKS_PER_SEC;

    printf("Time taken: %.2f seconds\n", time);

    free(primes);
    primes = NULL;


    return 0;
    
}