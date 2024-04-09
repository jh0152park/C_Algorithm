//
//  main.c
//  PrimeNumber
//
//  Created by 박재현 on 2024/04/10.
//

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int is_prime_number(int n) {
    for(int i = 2; i <= (int)sqrt(n); i++) {
        if(!(n % i)) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    printf(is_prime_number(299) ? "true" : "false");
    printf("\n");
    printf(is_prime_number(823) ? "true" : "false");
    printf("\n");
    return 0;
}
