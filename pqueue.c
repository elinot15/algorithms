#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Heap{
    int *heap;
    int allocated, used;
} Heap;

typedef Heap PriorityQueue;

Heap *heap_create(int size){
    Heap *heap = malloc(sizeof(Heap));
    heap->allocated = size;
    heap->used = 0;
    heap->heap = calloc(size, sizeof(int));

    return heap;
}

void heapify_up(Heap *heap, int i){
    if( i > 0 ){
        int father = (i-1) / 2;

        if( heap->heap[i] < heap->heap[father] ){
            int temp = heap->heap[i];
            heap->heap[i] = heap->heap[father];
            heap->heap[father] = temp;

            heapify_up(heap, father);
        }
    }
}

void heapify_down(Heap *heap, int i){
    if( 2 * i + 1 < heap->used ){
        int min_child = (i*2)+1;
        if( heap->used != i ){
            min_child = heap->heap[min_child] < heap->heap[min_child+1] ? min_child : min_child + 1;
        }

        if( heap->heap[i] > heap->heap[min_child] ){
            int t = heap->heap[i];
            heap->heap[i] = heap->heap[min_child];
            heap->heap[min_child] = t;

            heapify_down(heap, min_child);
        }
    }
}

void heap_insert(Heap *heap, int value){
    if( heap->allocated == heap->used ){
        heap->allocated *= 2;
        heap->heap = realloc(heap->heap, heap->allocated * sizeof(int));
    }
    heap->heap[heap->used] = value;
    heapify_up(heap, heap->used);
    heap->used++;
}

void heap_delete(Heap *heap, int i){
    heap->heap[i] = heap->heap[heap->used - 1];
    heap->used--;
    int father = (i-1) / 2;
    if( father >= 0 && heap->heap[father] > heap->heap[i] ){
        heapify_up(heap, i);
    }

    int min_child = 2*i+1;
    if( (min_child < heap->used && heap->heap[min_child] < heap->heap[i]) || 
        (min_child+1 < heap->used && heap->heap[min_child+1] < heap->heap[i]) ){
        
        heapify_down(heap, i);
    }
}

void heap_destroy(Heap *heap){
    if( heap != NULL ){
        free(heap->heap);
        free(heap);
    }
}

PriorityQueue *pqueue_create(int size){
    return heap_create(size);
}

void pqueue_destroy(PriorityQueue *pqueue){
    heap_destroy(pqueue);
}

int pqueue_length(PriorityQueue *pqueue){
    return pqueue->used;
}

void pqueue_insert(PriorityQueue *pqueue, int value){
    heap_insert(pqueue, value);
}

int pqueue_extract(PriorityQueue *pqueue){
    int v = pqueue->heap[0];
    heap_delete(pqueue, 0);

    return v;
}

int pqueue_min(PriorityQueue *pqueue){
    return pqueue->heap[0];
}

void pqueue_sort(int *array, int l, int r){
    PriorityQueue *q = pqueue_create(10);
    for(int i = l; i < r; i++){
        pqueue_insert(q, array[i]);
    }
    int x = l;
    while(pqueue_length(q) != 0){
        array[x++] = pqueue_extract(q);
    }
}

void heap_print(Heap *heap){
    for(int i = 0; i < heap->used; i++){
        printf("%d ", heap->heap[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    srand(time(NULL));
    
    int array[20];
    for(int i = 0; i < 20; i++){
        array[i] = rand() % 200;
        printf("%d ", array[i]);
    }
    printf("\n");

    pqueue_sort(array, 0, 20);
    for(int i = 0; i < 20; i++){
        printf("%d ", array[i]);
    }
    return 0;
}
