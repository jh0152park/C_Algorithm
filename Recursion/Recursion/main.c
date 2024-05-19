//
//  main.c
//  Recursion
//
//  Created by 박재현 on 2024/05/19.
//

#include <stdio.h>

int fact(int num) {
    if(num == 1)    return 1;
    return num * fact(num - 1);
}

int main(int argc, const char * argv[]) {
    printf("%d\n", fact(5));
    return 0;
}
