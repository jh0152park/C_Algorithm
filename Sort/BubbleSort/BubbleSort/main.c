//
//  main.c
//  BubbleSort
//
//  Created by 박재현 on 2024/06/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_array(int arr[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n\n");
}

void bubble_sort(int arr[], int length) {
    int t;
    
    for(int i = 0; i < length - 1; i++) {
        for(int j = 1; j < length - i; j++) {
            if(arr[j - 1] > arr[j]) {
                t = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = t;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int *arr;
    int str_length;
    char *str = "TOLEARNSORTALGORITHM";
    
    str_length = (int)strlen(str);
    arr = (int *)malloc(sizeof(int) * str_length);
    
    for(int i = 0; i < str_length; i++) {
        arr[i] = str[i];
    }
    
    printf("Before Bubble Sorting.\n");
    print_array(arr, str_length);
    
    bubble_sort(arr, str_length);
    printf("After Bubble Sorting.\n");
    print_array(arr, str_length);
    
    return 0;
}
