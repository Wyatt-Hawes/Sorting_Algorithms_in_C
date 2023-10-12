#include "mtrand.h"
#include <stdio.h>
#include <ctype.h>
#include "stats.h"


void bubble_sort(Stats *stats, uint32_t *arr, uint32_t n_elements){
	
	//range from 0 to len - 1
	for (int i = 0; i < (int)n_elements - 1; i ++){
	//printf("One\n");
		int swapped = 0;
		
		//range from len - 1 to i, decrementing by 1
		for (int j = n_elements - 1; j > i; j--){
			
			//Comparison occurs
			if((cmp( stats,arr[j], arr[j-1])) == -1){
				//Swap occurs
				swap(stats, &arr[j], &arr[j-1]);
				swapped = 1;
			}
		}
		//If no changes happened, list is sorted
		if (swapped == 0){
		break;
		}
	}
}
