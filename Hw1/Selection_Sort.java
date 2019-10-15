
import java.util.Random;


/*
 * Briefly explaining the code:
 * I have created arrays of sizes 10 50 100 500 1000 5_000 and 10_000
 * to measure the time the algorithm takes to sort them
 * in the average, best, and worst cases
 * and then printing the times in second in the end of each calculation  
 * To generate the random sequences depending on the size of 
 * the array, I have filled it with random values from 1 to twice the size of the array itself
 * to increase the chances of all entries being different from each other.
 * for the best cases, the arrays are filled with increasing numbers from 1 to their size and 
 * in the worst case using the same numbers but inversely sorted (from largest to smallest) 
 * I have also used assertions to make sure to check the algorithm is actually correct
 */

public class Selection_Sort {
	
	public static void selectionSort(int[] array) {
		int minIndex, temp, length = array.length;
		
		for(int startIndex = 0; startIndex <=length-2; startIndex++) 
		{
			minIndex = startIndex;
			
			for(int i =startIndex+1; i<=length-1; i++) 
			{
				if(array[i]<array[minIndex])
					minIndex = i;
			}
			
			temp = array[startIndex] ;
			array[startIndex] = array[minIndex];
			array[minIndex] = temp;
			
			assert minStart(array, startIndex):
				"Error: " + array[startIndex] + 
				" at position " + startIndex +
				" is not the smallest compared"
		        + " to teh numbers on the right";
		}
		assert isSorted(array):
			"Error, the array is not sorted";
	}
	
	public static void main(String[] args)
	{
		int i,a;
		double time1, time2, time3, time4, time5, time6, time7, time8, time9, time10;
		long starttime, endtime;
		Random rand = new Random();

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
		selectionSort(array1);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		selectionSort(array2);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		selectionSort(array3);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		selectionSort(array4);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		selectionSort(array5);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		selectionSort(array6);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(array7);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 20_000 array
		starttime = System.nanoTime();
		selectionSort(array8);
		endtime = System.nanoTime();
		time8 = (endtime-starttime)/1_000_000.0;
		//time to sort size 50_000 array
		starttime = System.nanoTime();
		selectionSort(array9);
		endtime = System.nanoTime();
		time9 = (endtime-starttime)/1_000_000.0;

		//time to sort size 100_000 array
		starttime = System.nanoTime();
        selectionSort(array10);
		endtime = System.nanoTime();
		time10 = (endtime-starttime)/1_000_000.0;
				
		System.out.println("Time for random array of size 10: " + time1 + " s");
		System.out.println("Time for random array of size 50: " + time2 + " s");
		System.out.println("Time for random array of size 100: " + time3 + " s");
		System.out.println("Time for random array of size 500: " + time4 + " s");
		System.out.println("Time for random array of size 1000: " + time5 + " s");
		System.out.println("Time for random array of size 5000: " + time6 + " s");
		System.out.println("Time for random array of size 10000: " + time7 + " s");
		System.out.println("Time for random array of size 20000: " + time8 + " s");
		System.out.println("Time for random array of size 50000: " + time9 + " s");
		System.out.println("Time for random array of size 100000: " + time10 + " s");
		
		
		///////////SORTING AND TIMING  for pre-ordered values - best cases////////////
		
		//time to sort size 10 array
		starttime = System.nanoTime();
		selectionSort(best1);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		selectionSort(best2);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		selectionSort(best3);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		selectionSort(best4);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		selectionSort(best5);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		selectionSort(best6);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(best7);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		starttime = System.nanoTime();
		selectionSort(best8);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		starttime = System.nanoTime();
		selectionSort(best9);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		starttime = System.nanoTime();
		selectionSort(best10);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;
				
		System.out.println("\n\nTime for ordered array of size 10: " + time1 + " s");
		System.out.println("Time for ordered array of size 50: " + time2 + " s");
		System.out.println("Time for ordered array of size 100: " + time3 + " s");
		System.out.println("Time for ordered array of size 500: " + time4 + " s");
		System.out.println("Time for ordered array of size 1000: " + time5 + " s");
		System.out.println("Time for ordered array of size 5000: " + time6 + " s");
		System.out.println("Time for ordered array of size 10000: " + time7 + " s");
		System.out.println("Time for ordered array of size 10000: " + time8 + " s");
		System.out.println("Time for ordered array of size 10000: " + time9 + " s");
		System.out.println("Time for ordered array of size 10000: " + time10 + " s");

		
///////////SORTING AND TIMING  for pre-ordered values - best cases////////////
		
		//time to sort size 10 array
		starttime = System.nanoTime();
		selectionSort(worst1);
		endtime = System.nanoTime();
		time1 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 50 array
		starttime = System.nanoTime();
		selectionSort(worst2);
		endtime = System.nanoTime();
		time2 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 100 array
		starttime = System.nanoTime();
		selectionSort(worst3);
		endtime = System.nanoTime();
		time3 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 500 array
		starttime = System.nanoTime();
		selectionSort(worst4);
		endtime = System.nanoTime();
		time4 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 1000 array
		starttime = System.nanoTime();
		selectionSort(worst5);
		endtime = System.nanoTime();
		time5 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 5_000 array
		starttime = System.nanoTime();
		selectionSort(worst6);
		endtime = System.nanoTime();
		time6 = (endtime-starttime)/1_000_000.0;
		
		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(worst7);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(worst8);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(worst9);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;

		//time to sort size 10_000 array
		starttime = System.nanoTime();
		selectionSort(worst10);
		endtime = System.nanoTime();
		time7 = (endtime-starttime)/1_000_000.0;
				
		System.out.println("\n\nTime for inverse ordered array of size 10: " + time1 + " s");
		System.out.println("Time for inverse ordered array of size 50: " + time2 + " s");
		System.out.println("Time for inverse ordered array of size 100: " + time3 + " s");
		System.out.println("Time for inverse ordered array of size 500: " + time4 + " s");
		System.out.println("Time for inverse ordered array of size 1000: " + time5 + " s");
		System.out.println("Time for inverse ordered array of size 5000: " + time6 + " s");
		System.out.println("Time for inverse ordered array of size 10000: " + time7 + " s");
		System.out.println("Time for inverse ordered array of size 10000: " + time8 + " s");
		System.out.println("Time for inverse ordered array of size 10000: " + time9 + " s");
		System.out.println("Time for inverse ordered array of size 10000: " + time10 + " s");
		
	}
	
	private static boolean minStart(int[] number,int startIndex) 
	{
		for(int i = startIndex+1; i<number.length; i++) 
		{	
			if(number[startIndex]>number[i])
				return false;
		}
		return true;
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
