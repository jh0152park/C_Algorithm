//
//  main.c
//  Insertion Sort
//
//  Created by 박재현 on 2024/05/31.
//  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void print_array(int a[], int n, char option) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        if(option == 'c') {
            printf("%c ", a[i]);
        } else if(option == 'd') {
            printf("%d ", a[i]);
        } else if(option == 'b') {
            printf("%c(%d) ", a[i], a[i]);
        } else if(option == 'i') {
            printf("%c(%d) ", a[i], i);
        }
    }
    printf("\n\n");
}

void insert_sort(int a[], int n) {
    int j;
    int temp;
    
    for(int i = 1; i < n; i++) {
        j = i;
        temp = a[i];
        
        while(j > 0 && a[j-1] > temp) {
            // 배열의 모습이 [3, 2] 이라고 할때
            // 3을 한칸 뒤로 밀어서 2가 있는 자리로 위치 시킴
            a[j] = a[j-1];
            j--;
        }
        // 결과적으로 j는 0부터 i까지 중에서 가장 작은 값이 있는 위치가 됨
        a[j] = temp;
    }
}

void sentinel_insert_sort(int a[], int n) {
    int j;
    int temp;
    
    for(int i = 2; i < n; i++) {
        j = i;
        temp = a[i];
        
        while(a[j-1] > temp) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = temp;
    }
}

void indirect_insert_sort(int a[], int index[], int n) {
    int j;
    int temp;
    
    for(int i = 0 ; i < n; i++) {
        index[i] = i;
    }
    
    for(int i = 1; i < n; i++) {
        j = i;
        temp = index[i];

        while(a[index[j-1]] > a[temp] && j > 0) {
            index[j] = index[j-1];
            j--;
        }
        index[j] = temp;
    }
}

void re_arrange(int a[], int index[], int n) {
    int *p;
    
    p = (int *)malloc(sizeof(int) * n);
    
    for(int i = 0; i < n; i++) {
        p[i] = a[index[i]];
    }
    for(int i = 0; i < n; i++) {
        a[i] = p[i];
    }
}


int main(int argc, const char * argv[]) {
    int length;
    int *index;
    int *array;
    int *sentinel_array;
    int *indirect_array;
    char *str = "TOLEARNSORTALGORITHM";
    
    length = (int)strlen(str);
    array = (int *)malloc(sizeof(int) * length);
    index = (int *)malloc(sizeof(int) * length);
    indirect_array = (int *)malloc(sizeof(int) * length);
    sentinel_array = (int *)malloc(sizeof(int) * (length + 1));
    
    sentinel_array[0] = -1;
    for(int i = 0; i < length; i++) {
        array[i] = str[i];
        index[i] = i;
        indirect_array[i] = str[i];
        sentinel_array[i+1] = str[i];
    }
    
    
    
    printf("Before Insert Sort about normal array");
    print_array(array, length, 'c');
    
    insert_sort(array, length);
    
    printf("After Insert Sort about normal array");
    print_array(array, length, 'c');
    
    printf("Before Insert Sort about sentinel array");
    print_array(sentinel_array, length+1, 'b');
    
    sentinel_insert_sort(sentinel_array, length+1);
    
    printf("After Insert Sort about sentinel array");
    print_array(sentinel_array, length+1, 'b');
    
    printf("Before Indirect Insert Sort");
    printf("Array");
    print_array(indirect_array, length, 'i');
    printf("Index");
    print_array(index, length, 'd');
    
    indirect_insert_sort(indirect_array, index, length);
    
    printf("After Indirect Insert Sort");
    printf("Array");
    print_array(indirect_array, length, 'i');
    printf("Index");
    print_array(index, length, 'd');
    
    re_arrange(indirect_array, index, length);
    
    printf("After Re Arrange");
    printf("Array");
    print_array(indirect_array, length, 'i');
    printf("Index");
    print_array(index, length, 'd');
    
    return 0;
}
