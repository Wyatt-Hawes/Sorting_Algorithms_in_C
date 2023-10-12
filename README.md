# View WRITEUP.pdf to view sort statistics
- All code except .h header files were written by myself

How to run and use sorting.c
================================


What does it do?
----------------
> Sorts a randomly generated array with 4 sorting methods, Bubble, Heap, Quick, Shell
> 


Command Line Options
--------------------
> 
>"USAGE\n"
>./sorting [-Hasbhq] [-n length] [-p elements] [-r seed]
>
>OPTIONS\n"
>	-H              Display program help and usage.
>	-a              Enable all sorts."
>	-b              Enable Bubble Sort.
>	-h              Enable Heap Sort.
>	-q              Enable Quick Sort.
>	-s              Enable Shell Sort.
>	-n length       Specify number of array elements (default: 100).
>	-p elements     Specify number of elements to print (default: 100).
>	-r seed         Specify random seed (default: 13371453).


How to build and run the program.
=================================

Step One:
---------
> Ensure that the files:

> "bubble.c"
> "bubble.h"
> "heap.c"
> "heap.h"
> "shell.c"
> "shell.h"
> "quick.c"
> "quick.h"
> "set.c"
> "set.h"
> "stats.c"
> "stats.h"
> "mtrand.c"
> "mtrand.h"
> "sorting.c"
>

> Are all inside the same directory.
>
Step Two:
---------
> Open the terminal in the directory and type "make"
>
Step Three:
-----------
> typing "./sorting <args>"

> Replace the <args> with the corresponding inputs you would like from the above section

> You can include multiple inputs in a single run through of the function! (EX: "./sorting -p 10 -n 4 -r 12345678")
