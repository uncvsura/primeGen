#include "../header/algos.h"

int main(void){
    uint64_t num;

    int power;
    printf("Enter power of 10:\n");
    scanf("%d", &power);

    num = pow(10,power);

    uint64_t size = num/8+1;

    uint8_t *primes = malloc(size);

    if(primes!=NULL){
        memset(primes,0xFF,size);
    }else{
        printf("malloc fail");
        return 1;
    }
    
    uint64_t p_count;

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");
    
    p_count = priminatorv9(primes,num,print);

    printf("\u03C0(%llu) = %llu\n", num, p_count);

    free(primes);
    primes = NULL;


    return 0;
}