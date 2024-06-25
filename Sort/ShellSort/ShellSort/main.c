//
//  main.c
//  ShellSort
//
//  Created by 박재현 on 2024/06/25.
//

#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_array(int array[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%c ", array[i]);
    }
    printf("\n");
}

void shell_sort(int array[], int length) {
    int target;
    int target_index;
    
    for(int h = length / 2; h > 0; h /= 2) {
        for(int i = 0; i < h; i++) {
            for(int j = i + h; j < length; j += h) {
                target = array[j];
                target_index = j;
                
                while(target_index > h - 1 && array[target_index - h] > target) {
                    array[target_index] = array[target_index - h];
                    target_index -= h;
                }
                array[target_index] = target;
            }
        }
    }
}

void shell_sort2(int array[], int length) {
    int h;
    int target;
    int target_index;
    
    for(h = 1; h < length; h = 3 * h + 1);
    for(h /= 3; h > 0; h /= 3) {
        for(int i = 0; i < h; i++) {
            for(int j = i + h; j < length; j += h) {
                target = array[j];
                target_index = j;
                
                while(target_index > h - 1 && array[target_index - h] > target) {
                    array[target_index] = array[target_index - h];
                    target_index -= h;
                }
                array[target_index] = target;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int length;
    int *array;
    int *array2;
    char *str = "TOLEARNSORTALGORITHM";
    
    clock_t start, end;
    
    length = (int)strlen(str);
    array = (int *)malloc(sizeof(int) * length);
    array2 = (int *)malloc(sizeof(int) * length);
    
    for(int i = 0; i < length; i++) {
        array[i] = str[i];
        array2[i] = str[i];
    }
    
    printf("Before shell sorting.\n");
    print_array(array, length);
    
    printf("\nAfter shell sorting.\n");
    start = clock();
    shell_sort(array, length);
    end = clock();
    
    print_array(array, length);
    printf("[run time: %f]\n", (float)(end - start)/CLOCKS_PER_SEC);
    
    
    printf("\nAfter shell sorting2.\n");
    start = clock();
    shell_sort2(array, length);
    end = clock();
    
    print_array(array, length);
    printf("[run time: %f]\n", (float)(end - start)/CLOCKS_PER_SEC);
    
    return 0;
}
