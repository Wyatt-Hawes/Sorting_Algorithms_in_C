#include "mtrand.h"
#include <stdio.h>
#include <ctype.h>
#include "stats.h"
#include "shell.h"
#include <string.h>
#include <stdlib.h>


void quick_sort(Stats *stats, uint32_t *arr, uint32_t n_elements){
	//printf("n:%d\n", n_elements);
	uint32_t SMALL = 8;
	if (n_elements < SMALL){
		
		shell_sort(stats,arr,n_elements);
		return;
		
	}

	uint32_t pivot = (arr[0] + arr[n_elements / 2] + arr[n_elements-1]) / 3;
	
	uint32_t *lower_arr = calloc(n_elements, sizeof(uint32_t));
	uint32_t *upper_arr = calloc(n_elements, sizeof(uint32_t));
	uint32_t *mid_arr = calloc(n_elements, sizeof(uint32_t));
	
	int lower = 0;
	int upper = 0;
	int mid = 0;
	
	for (uint32_t i = 0; i < n_elements; i++){
		
		
		switch (cmp(stats, arr[i], pivot)){
		
		case -1:
		
			lower_arr[lower] = move(stats, arr[i]);
			lower++;
			break;
		
		case 0:
			mid_arr[mid] = move(stats, arr[i]);
			mid++;
			break;
		case 1:
		
			upper_arr[upper] = move(stats, arr[i]);
			upper++;
			break;
		
		}
	}
	quick_sort(stats, lower_arr, lower);
	quick_sort(stats, upper_arr, upper);
	//int index = 0;
	//printf("Applying\n");
	memcpy(arr, lower_arr, sizeof(uint32_t) * lower);
	//for (int a = 0; a < lower; a++){
	//	arr[index] = move(stats,lower_arr[a]);
	//	index++;
	//}
	memcpy(&arr[lower], mid_arr, sizeof(uint32_t) * mid);
	//for (int x = 0; x < mid; x++){
	//	arr[index] = move(stats, mid_arr[x]);
	//	index++;
	//}
	memcpy(&arr[lower + mid], upper_arr, sizeof(uint32_t) * upper);
	//for (int b = 0; b < upper; b++){
	//	arr[index] = move(stats, upper_arr[b]);
	//	index++;
	//}
	free(lower_arr);
	free(upper_arr);
	free(mid_arr);
}


