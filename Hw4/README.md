# Solution Walkthrough
___
The problem solved in the pdf file requires us to write the pseudocode for bubble sort algorithm, determine and prove the asymptotic worst-case, average-case, and best-case time complexity of the sort, determine which of the following are stable and adaptive: Insertion Sort, Merge Sort, Heap Sort, and Bubble Sort.
___

The java file is an implementation of the Heap Sort algorithm, and also an implementation of a variant of the Heap Sort that works as follows: It first builds a max heap, then in every step it always floats the new root all the way until the leafs and it checks if the move was correct, and if not it starts moving upwards until the right place is found.