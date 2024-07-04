//
//  main.c
//  QuickSort
//
//  Created by 박재현 on 2024/06/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_array(int array[], int length) {
    for(int i = 0; i < length; i++) {
        printf("%c ", array[i]);
    }
    printf("\n\n");
}


void quick_sort(int array[], int length) {
    int i,j;
    int temp;
    int pivot;
    
    if(length > 1) {
        pivot = array[length-1]; // 기준 값
        i = -1;         // i는 왼쪽부터 검색할 위치
        j = length-1;   // j는 오른쪽부터 검색할 위치
        
        // 분할
        while(1) {
            while(array[++i] < pivot);
            while(array[--j] > pivot);
            
            
            if(i >= j)  break;  // i와 j의 위치가 겹치거나 뒤바뀌면 분할 종료
            
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        
        // 배열의 가장 끝에 위치한 기준 값과, i위치의 값을 서로 교환함
        temp = array[i];
        array[i] = array[length-1];
        array[length-1] = temp;
        
        quick_sort(array, i);
        quick_sort(array+i+1, length-i-1);
    }
}

int main(int argc, const char * argv[]) {
    int length;
    int *array;
    char *str = "TOLEARNSORTALGORITHM";
    
    length = (int)strlen(str);
    array = (int *)malloc(sizeof(int) * length);
    
    for(int i = 0; i < length; i++) {
        array[i] = str[i];
    }
    
    printf("Before quick sorting.\n");
    print_array(array, length);
    
    quick_sort(array, length);
    printf("After quick sorting.\n");
    print_array(array, length);
    
    return 0;
}
