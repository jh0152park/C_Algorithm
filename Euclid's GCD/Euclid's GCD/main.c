//
//  main.c
//  Euclid's GCD
//
//  Created by 박재현 on 2024/04/09.
//

#include <stdio.h>

int get_gcd(int u, int v) {
    if(u < 0 || v < 0) {
        return 0;
    }
    
    int t;
    while (v) {
        t = u % v;
        u = v;
        v = t;
    }
    return u;
}

int main(int argc, const char * argv[]) {
    printf("280 and 30's GCD is %d\n", get_gcd(280, 30));
    printf("170 and 15's GCD is %d\n", get_gcd(170, 15));
    return 0;
}
