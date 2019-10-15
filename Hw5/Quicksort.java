import java.util.Random;

public class Quicksort
{
	public static void main( String []args)
	{
		//initialize the variables used to store total time in all algorithms
		double sum_l=0.0, sum_h=0.0, sum_m=0.0, i;
		Random rand = new Random();
		long start, stop;
		double time, avg_l, avg_h, avg_m;

		for(i = 0; i< 100_000; i++)
		{
			//three equal arrays to get measure
			//time taken each iteration
			int [] a = new int[1000];
			int [] b = new int[1000];
			int [] c = new int[1000];

			for(int j = 0; j < 1000; j++)
				a[j] = rand.nextInt(2000);
			for(int j = 0; j < 1000; j++)
				b[j] = a[j];
			for(int j = 0; j < 1000; j++)
				c[j] = a[j];
			//for lomutos partition
			start = System.nanoTime();
			lomuto_quicksort(a,0,a.length-1);
			stop = System.nanoTime();
			time = (stop - start);
			sum_l += time;
			//for hoares partition
			start = System.nanoTime();
			hoare_quicksort(b,0,b.length);
			stop = System.nanoTime();
			time = (stop - start);
			sum_h += time;
			//for median of three 
			start = System.nanoTime();
			medianofthree_quicksort(a,0,a.length-1);
			stop = System.nanoTime();
			time = (stop - start);
			sum_m += time;

		}
		avg_m = sum_m/100_000;
		avg_l = sum_l/100_000;
		avg_h = sum_h/100_000;
		System.out.println("Average running times: ");
		System.out.println("Lumoto partition: " + avg_l + " nanoseconds");
		System.out.println("Hoare partition: " + avg_h + " nanoseconds");
		System.out.println("Median of three partition: " + avg_m + " nanoseconds");
	}

	public static void lomuto_quicksort(int[] A, int l, int r)
	{
		if(r-l<2)return;
		
			int m = lomuto_partition(A, l, r);
			lomuto_quicksort(A, l, m-1);
			lomuto_quicksort(A, m+1, r);
		
	}

	public static int lomuto_partition (int[] A, int l, int r)
	{
		int x = A[l];
		int i = l;
		for( int j = i+1; j<=r; j++)
		{
			if(A[j] <=x)
			{
				i++;
				swap(A, i, j);
			}
		}
		swap(A, l, i);
		return i;
	}
	
	public static void hoare_quicksort(int[] A, int l, int r)
	{
		if(l<r){
			int m = hoare_partition(A, l, r);
			hoare_quicksort(A, l, m);
			hoare_quicksort(A, m+1, r);
		}				
	}

	public static int hoare_partition (int [] A, int l, int r)
	{ 		
			int pivot = A[l];
			int i = l, j = r;
			while(i<j)
			{
				while(i<j && A[--j] >= pivot);
				if(i<j)
				{
					A[i] = A[j];
				}

				while(i<j && A[++i] <=pivot);
				if(i<j)
				{
					A[j] = A[i];
				}
			}	
			A[j] = pivot;
			return j;		
	}

	public static void medianofthree_quicksort(int []A, int l, int r)
	{
		if(l<r)
		{
			int pivot = get_pivot(A, l, r);
			int m = medianofthree_partition(A, l, r, pivot);
			medianofthree_quicksort(A, l, m-1);
			medianofthree_quicksort(A, m+1, r);
		}
	}

	public static int medianofthree_partition (int[] A, int l, int r, int pivot)
	{
		int i = l-1;
		int j = r;
		while(i<j)
		{
			i++;
			while(A[i] < pivot)
				i++;
			j--;
			while(j > 0 && A[j] > pivot)
				j--;
			if(i >= j)
				break;
			else
				swap(A, i, j);
		}
		swap(A, i, r);
		return i;
	}
	//uses median of three method to choose the pivot
	public static int get_pivot(int[] A, int l, int r)
	{
		int m = l + (r-l)/2;
		if(A[l] > A[m])
			swap(A, l, m); 	
		if(A[l] > A[r])
			swap(A,l, r);
		if(A[m] > A[r])
			swap(A, m, r);
		swap(A, m, r);
		return A[r];
	}
	//helper function for swapping
	public static void swap(int A[], int i, int j)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
	
}
