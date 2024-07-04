//
//  main.c
//  MergeSort
//
//  Created by 박재현 on 2024/07/04.
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

void merge_sort(int array[], int length) {
    int i, j, k;
    int first, second;
    int *merged_array;
    
    merged_array = (int *)malloc(sizeof(int) * length);
    for(int size = 1; size < length; size *= 2) {
        first = -2 * size;
        second = first + size;
        
        // next second가 배열을 넘어가지 않는다면
        while((size * 2) + second < length) {
            first += size * 2;
            second += size * 2;
            i = first;
            j = second;
            k = first;
            
            // 병합해야할 배열 [A] 와 [B]가 있을때, A와 B 배열에 합칠 배열에 저장해야할 요소가 남아있는 경우
            // 즉 배열 [A], [B]의 병합이 완료되지 않았을 경우
            // 여기서 배열 [A]는 First 구간을 의미하고, 배열 [B]는 Second 구간을 의미
            while((i < first + size) || (j < second + size && j < length)) {
                // [A] 배열의 요소가 B배열의 요소보다 작을경우
                if(array[i] <= array[j]) {
                    // A배열에 있는 작은 요소를 머지 배열에 추가
                    if(i < first + size) {
                        merged_array[k++] = array[i++];
                    }
                    // A배열에 요소가 없기는경우, 즉 A배열은 정렬이 완료 되었으니 B배열 요소를 추가
                    else {
                        merged_array[k++] = array[j++];
                    }
                }
                // 반대로 B배열에 있는 요소가 A배열의 요소보다 작을경우
                else {
                    // B배열의 요소가 남아있고, 인덱스가 배열을 초과하지 않았다면
                    if(j < second + size && j < length) {
                        merged_array[k++] = array[j++];
                    }
                    // B배열에 요소가 없는경우, 즉 B는 정렬이 완료되었으니 A배열 요소를 추가
                    else {
                        merged_array[k++] = array[i++];
                    }
                }
            }
        }
        for(i = 0; i < length; i++) {
            array[i] = merged_array[i];
        }
    }
    free(merged_array);
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
    
    printf("Before MergeSorting.\n");
    print_array(array, length);
    merge_sort(array, length);
    printf("After MergeSorting.\n");
    print_array(array, length);
    
    return 0;
}
