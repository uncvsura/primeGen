#include "../header/algos.h"

int main(void){

    uint32_t num;

    int power;
    printf("Enter power of 10:\n");
    scanf("%d", &power);

    num = pow(10,power);

    bool *primes = malloc(num-1);
    
    uint32_t p_count;

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");
    
    p_count = priminatorv8(primes,num,print);

    printf("\n\u03C0(%d) = %d\n", num, p_count);

    free(primes);
    primes = NULL;


    return 0;
    
}