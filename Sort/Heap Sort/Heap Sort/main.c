//
//  main.c
//  Heap Sort
//
//  Created by 박재현 on 2024/05/22.
//

#include <stdio.h>
#include <math.h>

#define INT_MAX 99999
#define HEAP_SIZE 100

void uphead(int a[], int k) {
    int v = a[k];
    
    a[0] = INT_MAX;
    while(a[k/2] <= v) {
        a[k] = a[k/2];
        k /= 2;
    }
    a[k] = v;
}

void downheap(int a[], int n, int k) {
    int i;
    int v = a[k];
    
    while(k <= n/2) {
        i = k * 2;
        if(a[i + 1] > a[i] && i < n)
            i++;
        
        if(v >= a[i])
            break;
        
        a[k] = a[i];
        k = i;
    }
    a[k] = v;
}

void insert(int a[], int *n, int v) {
    a[++(*n)] = v;
    uphead(a, *n);
}

int extract(int a[], int *n) {
    int v = a[1];
    a[1] = a[(*n)--];
    downheap(a, *n, 1);
    return v;
}

void heap_sort(int a[], int n) {
    int i;
    int hn = 0;
    
    for(i = 1; i <= n; i++)
        insert(a, &hn, a[i]);
    for(i = hn; i >= 1; i--)
        a[i] = extract(a, &hn);
}

void heap_sort2(int a[], int n) {
    int k, t;
    
    for(k = n/2; k >= 1; k--)
        downheap(a, n, k);
    
    while(n > 1) {
        t = a[1];
        a[1] = a[n];
        a[n] = t;
        downheap(a, --n, 1);
    }
}

void print_heap(int a[], int n) {
    int cnt = 0;
    int goal = 1;
    int level = (int)sqrt(n) + 1;
    
    for(int i = 1; i <= n; i++) {
        cnt++;
        
        for(int j = 0; j < level; j++)
            printf(" ");
        
        printf("%d", a[i]);
        
        if(cnt == goal) {
            printf("\n");
            goal = cnt * 2;
            cnt = 0;
            level--;
        }
    }
    printf("\n\n");
}

void print_array(int a[], int n) {
    for(int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int node = 0;
    int heap[HEAP_SIZE];
    int heap2[11] = {INT_MAX, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    
    for(int i = 1; i <= 10; i++) {
        insert(heap, &node, i);
    }
    
    printf("Insert data into heap from 1 to 10\n");
    print_heap(heap, node);
    heap_sort(heap, node);
    printf("After sorting\n");
    print_heap(heap, node);
    
    printf("Before sorting\n");
    print_array(heap2, 10);
    heap_sort2(heap2, 10);
    printf("After sorting\n");
    print_array(heap2, 10);
    
    return 0;
}
