import java.util.Random;
import java.util.Scanner;

public class MergeSort 
{
	//we will try the values of k , ;in arrays of sizes 
	//the time in each array is calculated in milliseconds 
	//to facilitate seeing the difference and making
	//the plots easier to be made
	private static int k;
	private static Scanner scanner = new Scanner(System.in);

	public static void mergeSort(int[] array,int start, int end) 
	{
		
		if(end - start <= k) 
		{
			insertionSort(array, start, end);
			return;
		}

		int mid = (start + end)/2;
		mergeSort(array,start,mid);
		mergeSort(array,mid,end);
		merge(array,start,mid,end);
	}
	
	public static void merge(int[] array,int  start, int  mid,int  end ) 
	{
		if(array[mid-1] <= array[mid]) 
		{
			return;
		}
		
		int i = start, j = mid, tempindex = 0;
		
		int[] temp = new int[end-start];
		while(i < mid && j < end) 
		{
			temp[tempindex++] = array[i] <= array[j] ? array[i++] : array[j++];
		}
		
		System.arraycopy(array, i, array, start + tempindex,mid-i);
		System.arraycopy(temp, 0, array, start, tempindex);
	}
	
	public static int[] insertionSort(int[] array, int start, int end) 
	{
		int i,j,key;
		for(i=start+1; i<end; i++) 
		{
			key = array[i];
			j=i-1;
			while(j>=start && key<array[j]) 
			{
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = key;
		}
		return array;
	}

	public static void main(String[] args)
	{
		int i, a;
		double time1, time2, time3, time4, time5, time6, time7, time8, time9, time10;
		long starttime, endtime;
		Random rand = new Random();

		//getting k
		System.out.println("Please the value of k: ");
		k = scanner.nextInt();
		//the arrays named 'array#' are used to calculate average case
		//the ones named best# to calculate time in best case 
		//the ones named worst to calculate time in worst case
		int array1[] = new int[10], best1[] = new int[10], worst1[] = new int[10];
		int array2[] = new int[50], best2[] = new int[50], worst2[] = new int[50];
		int array3[] = new int[100], best3[] = new int[100], worst3[] = new int[100];
		int array4[] = new int[500], best4[] = new int[500], worst4[] = new int[500];
		int array5[] = new int[1_000], best5[] = new int[1_000], worst5[] = new int[1_000];
		int array6[] = new int[5_000], best6[] = new int[5_000], worst6[] = new int[5_000];
		int array7[] = new int[10_000], best7[] = new int[10_000], worst7[] = new int[10_000];
		int array8[] = new int[20_000], best8[] = new int[20_000], worst8[] = new int[20_000];
		int array9[] = new int[50_000], best9[] = new int[50_000], worst9[] = new int[50_000];
		int array10[] = new int[100_000], best10[] = new int[100_000], worst10[] = new int[100_000];

		//first arrays 
		for(i = 0; i<10; i++)
		{
			a = rand.nextInt(20) + 1;
			array1[i] = a;
			best1[i]  = i+1;
			worst1[i]  = 10-i;
		}
		//second arrays
		for(i = 0; i<50; i++)
		{
			a = rand.nextInt(100) + 1;
			array2[i]  = a;
			best2[i]   = i+1;
			worst2[i]  = 50-i;
		}
		//third arrays
		for(i = 0; i<100; i++)
		{
			a = rand.nextInt(200) + 1;
			array3[i]  = a;
			best3[i]   = i+1;
			worst3[i]  = 100-i;
		}
		//forth arrays 
		for(i = 0; i<500; i++)
		{
			a = rand.nextInt(1000) + 1;
			array4[i]  = a;
			best4[i]   = i+1;
			worst4[i]  = 500-i;
		}
		//fifth arrays 
		for(i = 0; i<1000; i++)
		{
			a = rand.nextInt(2_000) + 1;
			array5[i]  = a;
			best5[i]   = i+1;
			worst5[i]  = 1_000-i;
		}
		//sixth arrays
		for(i = 0; i<5_000; i++)
		{
			a = rand.nextInt(10_000) + 1;
			array6[i]  = a;
			best6[i]   = i+1;
			worst6[i]  = 5_000-i;
		}
		//seventh arrays
		for(i = 0; i<10_000; i++)
		{
			a = rand.nextInt(20_000) + 1;
			array7[i] = a;
			best7[i]  = i+1;
			worst7[i]  = 10_000-i;
		}
		//eightth arrays
		for(i = 0; i<20_000; i++)
		{
			a = rand.nextInt(40_000) + 1;
			array8[i] = a;
			best8[i]  = i+1;
			worst8[i]  = 20_000-i;
		}
		//nineth arrays
		for(i = 0; i<50_000; i++)
		{
			a = rand.nextInt(100_000) + 1;
			array9[i] = a;
			best9[i]  = i+1;
			worst9[i]  = 50_000-i;
		}
		//tenth arrays
		for(i = 0; i<100_000; i++)
		{
			a = rand.nextInt(200_000) + 1;
			array10[i] = a;
			best10[i]  = i+1;
			worst10[i]  = 100_000-i;
		}

		///////////SORTING AND TIMING Random for values////////////
		
		//time to sort size 10 array
		starttime = System.nanoTime();
		mergeSort(array1, 0, array1.length);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		mergeSort(array2, 0, array2.length);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		mergeSort(array3, 0, array3.length);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		mergeSort(array4, 0, array4.length);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		mergeSort(array5, 0, array5.length);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		mergeSort(array6, 0, array6.length);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		mergeSort(array7, 0, array7.length);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 20_000 array
		starttime = System.nanoTime();
		mergeSort(array8, 0, array8.length);
		endtime = System.nanoTime();
		time8 = (endtime-starttime)/1_000_000.0;
		//time to sort size 50_000 array
		starttime = System.nanoTime();
		mergeSort(array9, 0, array9.length);
		endtime = System.nanoTime();
		time9 = (endtime-starttime)/1_000_000.0;

		//time to sort size 100_000 array
		starttime = System.nanoTime();
		mergeSort(array10, 0, array10.length);
		endtime = System.nanoTime();
		time10 = (endtime-starttime)/1_000_000.0;
				
		System.out.println("Time for random array of size 10 for k = "+ k + ": " + time1 + " ms");
		System.out.println("Time for random array of size 50 for k = "+ k + ": " + time2 + " ms");
		System.out.println("Time for random array of size 100 for k = "+ k + ": " + time3 + " ms");
		System.out.println("Time for random array of size 500 for k = "+ k + ": " + time4 + " ms");
		System.out.println("Time for random array of size 1000 for k = "+ k + ": " + time5 + " ms");
		System.out.println("Time for random array of size 5000 for k = "+ k + ": " + time6 + " ms");
		System.out.println("Time for random array of size 10000 for k = "+ k + ": " + time7 + " ms");
		System.out.println("Time for random array of size 20000 for k = "+ k + ": " + time8 + " ms");
		System.out.println("Time for random array of size 50000 for k = "+ k + ": " + time9 + " ms");
		System.out.println("Time for random array of size 100000 for k = "+ k + ": " + time10 + " ms");

		///////////SORTING AND TIMING  for pre-ordered values - best cases////////////
		
		//time to sort size 10 array
		starttime = System.nanoTime();
		mergeSort(best1, 0, best1.length);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		mergeSort(best2, 0, best2.length);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		mergeSort(best3, 0, best3.length);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		mergeSort(best4, 0, best4.length);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		mergeSort(best5, 0, best5.length);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		mergeSort(best6, 0, best6.length);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		mergeSort(best7, 0, best7.length);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 20_000 array
		starttime = System.nanoTime();
		mergeSort(best8, 0, best8.length);
		endtime = System.nanoTime();
		time8 = (endtime-starttime)/1_000_000.0;

		//time to sort size 50_000 array
		starttime = System.nanoTime();
		mergeSort(best9, 0, best9.length);
		endtime = System.nanoTime();
		time9 = (endtime-starttime)/1_000_000.0;

		//time to sort size 100_000 array
		starttime = System.nanoTime();
		mergeSort(best10, 0, best10.length);
		endtime = System.nanoTime();
		time10 = (endtime-starttime)/1_000_000.0;
				
		System.out.println("\n\nTime for already ordered array of size 10 for k = "+ k + ": " + time1 + " ms");
		System.out.println("Time for already ordered array of size 50 for k = "+ k + ": " + time2 + " ms");
		System.out.println("Time for already ordered array of size 100 for k = "+ k + ": " + time3 + " ms");
		System.out.println("Time for already ordered array of size 500 for k = "+ k + ": " + time4 + " ms");
		System.out.println("Time for already ordered array of size 1000 for k = "+ k + ": " + time5 + " ms");
		System.out.println("Time for already ordered array of size 5000 for k = "+ k + ": " + time6 + " ms");
		System.out.println("Time for already ordered array of size 10000 for k = "+ k + ": " + time7 + " ms");
		System.out.println("Time for already ordered array of size 20000 for k = "+ k + ": " + time8 + " ms");
		System.out.println("Time for already ordered array of size 50000 for k = "+ k + ": " + time9 + " ms");
		System.out.println("Time for already ordered array of size 100000 for k = "+ k + ": " + time10 + " ms");

///////////SORTING AND TIMING  for pre-ordered values - best cases////////////
		
		//time to sort size 10 array
		starttime = System.nanoTime();
		mergeSort(worst1, 0, worst1.length);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		mergeSort(worst2, 0, worst2.length);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		mergeSort(worst3, 0, worst3.length);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		mergeSort(worst4, 0, worst4.length);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		mergeSort(worst5, 0, worst5.length);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		mergeSort(worst6, 0, worst6.length);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		mergeSort(worst7, 0, worst7.length);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;
				
		//time to sort size 20_000 array
		starttime = System.nanoTime();
		mergeSort(worst8, 0, worst8.length);
		endtime = System.nanoTime();
		time8 = (endtime-starttime)/1_000_000.0;

		//time to sort size 50_000 array
		starttime = System.nanoTime();
		mergeSort(worst9, 0, worst9.length);
		endtime = System.nanoTime();
		time9 = (endtime-starttime)/1_000_000.0;

		//time to sort size 100_000 array
		starttime = System.nanoTime();
		mergeSort(worst10, 0, worst10.length);
		endtime = System.nanoTime();
		time10 = (endtime-starttime)/1_000_000.0;

		System.out.println("\n\nTime for inversely ordered array of size 10 for k = "+ k + ": " + time1 + " ms");
		System.out.println("Time for inversely ordered array of size 50 for k = "+ k + ": " + time2 + " ms");
		System.out.println("Time for inversely ordered array of size 100 for k = "+ k + ": " + time3 + " ms");
		System.out.println("Time for inversely ordered array of size 500 for k = "+ k + ": " + time4 + " ms");
		System.out.println("Time for inversely ordered array of size 1000 for k = "+ k + ": " + time5 + " ms");
		System.out.println("Time for inversely ordered array of size 5000 for k = "+ k + ": " + time6 + " ms");
		System.out.println("Time for inversely ordered array of size 10000 for k = "+ k + ": " + time7 + " ms");
		System.out.println("Time for inversely ordered array of size 20000 for k = "+ k + ": " + time8 + " ms");
		System.out.println("Time for inversely ordered array of size 50000 for k = "+ k + ": " + time9 + " ms");
		System.out.println("Time for inversely ordered array of size 100000 for k = "+ k + ": " + time10 + " ms");
	}

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