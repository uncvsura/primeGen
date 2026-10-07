#include "../header/algos.h"

int main(void){

    uint32_t num;

    printf("Enter even number:\n");
    scanf("%d", &num);

    bool *primes = malloc(num+1);

    priminatorv8(primes,num,false);

    int print;

    printf("Print? 1(Yes) 0(No):\n");
    scanf("%d", &print);

    printf("Calculating...\n");

    uint32_t pairCount = pairFind(primes, num,print);

    printf("G(%d): %d\n",num,pairCount);

    free(primes);
    primes=NULL;

    return 0;

}