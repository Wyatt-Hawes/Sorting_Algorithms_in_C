#include "mtrand.h"
#include <stdio.h>

#include "shell.h"
#include "bubble.h"
#include "quick.h"
#include "heap.h"
#include "stats.h"
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include "set.h"
#include "mtrand.h"

void printArr(uint32_t *arr, char* name, int s, Stats *stats, int elements){
	printf("%s Sort, %d elements, %lu moves, %lu compares\n", name, s, stats->moves, stats->compares);
	int i = 0;
	for (i = 0; i < elements && i < s; i ++){
		printf("%13d", arr[i]);
		if (i%5 == 4){
			printf("\n");	
		}
		
	}
	if (i%5 != 0){
		printf("\n");
	}
}



int main(int argc, char **argv){
	
	//extern int opterr;
	//opterr = 0;
	
	int value;
	int seed = 13371453;
	int size = 100;
	int elements = 100;
	Set settings = set_empty();
	
	Set do_shell = set_insert(set_empty(), 1);
	Set do_bubble = set_insert(set_empty(), 2);
	Set do_quick = set_insert(set_empty(), 3);
	Set do_heap = set_insert(set_empty(), 4);
	Set usage = set_insert(set_empty(), 5);
	
	while ((value = getopt(argc, argv, "asbqhr:n:p:H")) != -1){
	
		switch(value){
		
		case 'a':
			//Enable all
			settings = set_union(settings, do_shell);
			settings = set_union(settings, do_bubble);
			settings = set_union(settings, do_quick);
			settings = set_union(settings, do_heap);
			break;
		
		case 's':
			//Enable Shell: 1
			settings = set_union(settings, do_shell);
			break;
		case 'b': 
			//Enable Bubble: 2
			settings = set_union(settings, do_bubble);
			break;
		case 'q':
			//Enable Quick: 3
			settings = set_union(settings, do_quick);
			break;
		case 'h':
			//Enable Heap: 4
			settings = set_union(settings, do_heap);
			break;
		case 'r':
			//Set seed
			seed = atol(optarg);
			break;
		case 'n':
			//Set size
			size = atoi(optarg);
			break;
		case 'p':
			//set number of printed elements
			elements = atoi(optarg);
			break;
		case 'H':
			//Pring program usage
			settings = set_union(settings, usage);
			break;
		default:
			//Invalid input
			printf("SYNOPSIS\n"
		"   A collection of comparison-based sorting algorithms.\n\n"

		"USAGE\n"
		"   ./sorting [-Hasbhq] [-n length] [-p elements] [-r seed]\n\n"

		"OPTIONS\n"
		"   -H              Display program help and usage.\n"
		"   -a              Enable all sorts.\n"
		"   -b              Enable Bubble Sort.\n"
		"   -h              Enable Heap Sort.\n"
		"   -q              Enable Quick Sort.\n"
		"   -s              Enable Shell Sort.\n"
		"   -n length       Specify number of array elements (default: 100).\n"
		"   -p elements     Specify number of elements to print (default: 100).\n"
		"   -r seed         Specify random seed (default: 13371453).\n");
		
			
			return 1;
			break;

		}
	}

	//Check if size is 1<= n <= 250,000,000
	//seed
	if (!(1 <= size && size <= 250000000)){
		//Invalid input
		return 1;
	}
	
	
	mtrand_seed(seed);
	
	uint32_t *orig_arr = calloc(size, sizeof(uint32_t));
	
	for(int i = 0; i < size; i++){
		//1073741823 is 30 1's in binary
		orig_arr[i] = mtrand_rand64() & 1073741823;
		
	}
	
	
	
	Stats shell_stats;
    	Stats bubble_stats;
    	Stats quick_stats;
    	Stats heap_stats;
	
	uint32_t *to_sort = calloc(size, sizeof(uint32_t));
	

	
	shell_stats.compares = 0;
	shell_stats.moves = 0;
	
	bubble_stats.compares = 0;
	bubble_stats.moves = 0;
	
	quick_stats.compares = 0;
	quick_stats.moves = 0;
	
	heap_stats.compares = 0;
	heap_stats.moves = 0;
	
	if (set_intersect(settings, usage) == usage){
		printf("SYNOPSIS\n"
		"   A collection of comparison-based sorting algorithms.\n\n"

		"USAGE\n"
		"   ./sorting [-Hasbhq] [-n length] [-p elements] [-r seed]\n\n"

		"OPTIONS\n"
		"   -H              Display program help and usage.\n"
		"   -a              Enable all sorts.\n"
		"   -b              Enable Bubble Sort.\n"
		"   -h              Enable Heap Sort.\n"
		"   -q              Enable Quick Sort.\n"
		"   -s              Enable Shell Sort.\n"
		"   -n length       Specify number of array elements (default: 100).\n"
		"   -p elements     Specify number of elements to print (default: 100).\n"
		"   -r seed         Specify random seed (default: 13371453).\n");
		free(to_sort);
		free(orig_arr);
		return 0;
	}
	
	
	
	if (set_intersect(settings, do_bubble) == do_bubble){
	memcpy(to_sort, orig_arr, size * sizeof(uint32_t));
	bubble_sort(&bubble_stats, to_sort, size);
	printArr(to_sort, "Bubble", size,&bubble_stats, elements);
	}
	if (set_intersect(settings, do_heap) == do_heap){
	memcpy(to_sort, orig_arr, size * sizeof(uint32_t));
	heap_sort(&heap_stats, to_sort, size);
	printArr(to_sort, "Heap", size, &heap_stats, elements);
	}
	if (set_intersect(settings, do_quick) == do_quick){
	memcpy(to_sort, orig_arr, size * sizeof(uint32_t));
	quick_sort(&quick_stats, to_sort, size);
	printArr(to_sort, "Quick",size, &quick_stats, elements);
	}
	if (set_intersect(settings, do_shell) == do_shell){
	memcpy(to_sort, orig_arr, size * sizeof(uint32_t));
	shell_sort(&shell_stats, to_sort, size);
	printArr(to_sort, "Shell", size,&shell_stats, elements);
	}
	
	free(to_sort);
	free(orig_arr);
	return 0;
}
