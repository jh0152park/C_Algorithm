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
    printf("\n");
}

int main(int argc, const char * argv[]) {
    int node = 0;
    int heap[HEAP_SIZE];
    
    for(int i = 1; i <= 10; i++) {
        insert(heap, &node, i);
    }
    
    print_heap(heap, node);
    heap_sort(heap, node);
    print_heap(heap, node);
    return 0;
}
