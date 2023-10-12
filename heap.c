#include "mtrand.h"
#include <stdio.h>
#include <ctype.h>
#include "stats.h"
#include <string.h>
#include <stdlib.h>

int l_child(int n){
	return (2 * n) + 1;
}

int r_child(int n){
	return (2 * n) + 2;
}

int parent(int n){
	return (int)((n-1)/ 2);
}


//1 cmp   1 swap
void up_heap(Stats *stats, uint32_t *a, int n){
			//35 compares
	while((n > 0) && (cmp(stats, a[n],a[parent(n)]) < 0)){
	//printf("up\n");
	
	swap(stats, &a[n], &a[parent(n)]);
	n = parent(n);
	}
}
//2 compares  //1 swap
void down_heap(Stats *stats, uint32_t *a, int heap_size){

	int n = 0;
	uint32_t smaller;
		//63 compares
	while (l_child(n) < heap_size){
		
			//46 compares
		if (r_child(n) == heap_size){
			smaller = l_child(n);
		}else{	//43 compares
			if (cmp(stats,a[l_child(n)] , a[r_child(n)]) < 0){
				smaller = l_child(n);
			}else{
				smaller = r_child(n);
			}
		}
			//46 compares
		if (cmp(stats,a[n] , a[smaller])<0){
			break;
		}
		swap(stats, &a[n], &a[smaller]);
		n=smaller;
	
	}
}


void build_heap(Stats *stats, uint32_t* a, int length){
	
	//uint32_t heap[length];
	uint32_t *heap = calloc(length, sizeof(uint32_t));
	
	for(int n = 0; n < length; n++){
		//1 more move
		heap[move(stats,n)] = move(stats,a[n]);
		up_heap(stats, heap, n);
	}
   	memcpy(a, heap, sizeof(uint32_t) * length);
   	free(heap);
}

void heap_sort(Stats *stats, uint32_t *arr, uint32_t n_elements){
	
	
	//getting the heap from function
	build_heap(stats, arr, n_elements);
	
	uint32_t *sorted = calloc(n_elements, sizeof(uint32_t));
	
	//This sorts it
	for(uint32_t n = 0; n < n_elements; n++){
		//printf("%d ",n);
		//2 more moves
		sorted[move(stats,n)] = move(stats,arr[0]);
		arr[move(stats,0)] = move(stats,arr[n_elements-n-1]);
		down_heap(stats, arr, n_elements-n);

		
	}
   	memcpy(arr, sorted, sizeof(uint32_t) * n_elements);
   	free(sorted);
   	 
}
