import java.util.Random;
import java.util.Scanner;

public class Main 
{
	private static int heapsize;
	private static Scanner scanner = new Scanner(System.in);
	public static void main (String[] args) 
	{
		int size;
		//random heap generator
		Random rand = new Random();
		long starttime, endtime;
		double time;
		
		while(true)
		{
			System.out.println("Enter the size (negative int or 0 to exit):");
			size = scanner.nextInt();
			if(size <=0)
				break;
			int [] array = new int[size];
			//initialize the array with random values
			for(int i = 0; i<size; i++)
			{
				int a = rand.nextInt(2*size) + 1;
				array[i] = a;
			}
			//check the time for the heapsort from lecture
			starttime = System.nanoTime();
			heap_sort(array);
			endtime = System.nanoTime();
			time = (endtime-starttime)/1_000_000.0;
			if(isSorted(array))
				System.out.println("Time for normal heap sort: " + time + " ms");
			
			//reinitialize the array with random numbers
			for(int i = 0; i<size; i++)
			{
				int a = rand.nextInt(2*size) + 1;
				array[i] = a;
			}
			//measure time for the version in point b
			starttime = System.nanoTime();
			heap_sort2(array);
			endtime = System.nanoTime();
			time = (endtime-starttime)/1_000_000.0;
			if(isSorted(array))
				System.out.println("Time for the other heap sort: " + time + " ms");
		}
		
	}
	// FIRST VARIANT OF THE SORT
	/************************************************/
	//same method from lecture slides
	public static void max_heapify(int[] heap ,int i)
	{
		int l = 2*i + 1;
		int r = 2*i + 2;
		int largestChildIndex = i;
		//check current node with left child
		if(l < heapsize)
		{
			if(heap[l] > heap[i])
			{
				largestChildIndex = l;
			}
		}

		//check the current max with the right child
		if(r<heapsize)
		{
			if(heap[r] > heap[largestChildIndex])
			{
				largestChildIndex = r;
			}
		}
		
		if(largestChildIndex != i)
		{
			int temp = heap[i];
			heap[i] = heap[largestChildIndex];
			heap[largestChildIndex] = temp;
			max_heapify(heap, largestChildIndex);
		}
	}
	//same method from lecture slides
	public static void build_max_heap(int[] heap)
	{
		heapsize = heap.length;
		for(int i = (heap.length-2)/2; i>=0; i--)
			max_heapify(heap, i);
	}
	//same method from lecture slides
	public static void heap_sort(int[] heap)
	{
		build_max_heap(heap);
		for(int i = heap.length - 1; i>=1; i--)
		{
			int temp = heap[0];
			heap[0] = heap[i];
			heap[i] = temp;
			heapsize --;
			max_heapify(heap,0);
			assert !isValidHeap(heap, 0, heapsize): "Heap not valid 1";
		}
	}
	/********************************************/
	//SECOND (point b)
	// the heap sort version of point b
	public static void heap_sort2(int[] heap)
	{
		build_max_heap(heap);
		for(int i = heap.length - 1; i>=1; i--)
		{
			int temp = heap[0];
			heap[0] = heap[i];
			heap[i] = temp;
			heapsize --;
	     	//heapify2(heap, heapsize+1);
			float_elem(heap, heapsize);
			assert !isValidHeap(heap, 0, heapsize): "Heap not valid 2";
		}
	}
	//will search for the path with the biggest 
	//childrent that starts from root to leaves
	public static int search_till_leaves(int[] heap, int n)
	{
		int j = 0;
		while((2*j+2) < n)
		{
			if(heap[2*j+2] > heap[2*j+1])
				j = 2*j+2;
			else 
				j = 2*j+1;
		}
		if(2*j+1 < n)
		{
			j = 2*j+1;
		}
		return j;
	}
	
	public static void float_elem(int[] heap, int n)
	{
		int j = search_till_leaves(heap,n), i = 0;
		//fixing step
		while(heap[i] > heap[j])
			j = (int)((j-1)/2);
		int x = heap[j];
		heap[j] = heap[i];
		while(j>0)
		{
			int temp = x;
			x = heap[(int)((j-1)/2)];
			heap[(int)((j-1)/2)] = temp;
			j = (int)((j-1)/2);
		}
	}
	//to check if a heap is valid
	private static boolean isValidHeap(int[] heap ,int start, int end) 
	{
			
		for(int i = start; i< end/2; i++) {
			
			if(heap[i] < Math.max(heap[2*i+1],heap[2*i+2])) {
				return false;
			}
		}
		return true;
	}
	//to check if the arrays are really sorted
	private static boolean isSorted(int[] array) 
	{
		for(int i=0; i<array.length-1; i++) 
		{
			if(array[i] > array[i+1])
				return false;
		}
		return true;
	}
}
