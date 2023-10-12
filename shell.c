#include "mtrand.h"
#include <stdio.h>
#include <ctype.h>
#include "stats.h"

int n = 0;


int next_gap(int n){
	if (n == 1){
		return 0;
	}
	if (n <= 2){
		return 1;
		}
	return (int)((5 * n)/11);
}


void shell_sort(Stats *stats, uint32_t *arr, uint32_t n_elements){
	
	//int start = n_elements / 2;
	//for step in gap(length)
	for(int step = next_gap(n_elements); step > 0; step = next_gap(step)) {
		//range from step ---> length 
   		for(uint32_t i = step; i < n_elements; i += 1) {
   			
   			//range backwards from i ---> step, decrementing by size step
   			int j = move(stats,i);
   			uint32_t temp = move(stats,arr[i]);
			while (j >= step && cmp(stats, temp , arr[j-step]) < 0){
				arr[j] = move(stats,arr[j-step]);
				j -= move(stats,step);
			
			}
			arr[j] = move(stats,temp);
		}
	}

}



