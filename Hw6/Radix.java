import java.util.*;
public class Radix
{
	public static final int R  = 10;
	public static void main(String[] args)
	{
		int [] a = {870, 45, 75, 90, 802, 24, 2, 66};
		int [] b = {234,232,52,134,2,111,342};
		int [] c = {234,6,34,63,2,34,5,2432};
		System.out.println("\nBefore radix_msd sort: \n" + Arrays.toString(a));
		radix_msd(a);
		System.out.println("After radix_msd sort: \n" + Arrays.toString(a));
		
		System.out.println("\nBefore sort in point c : \n" + Arrays.toString(b));
		point_c_sort(b, b.length);
		System.out.println("After sort in point c : \n" + Arrays.toString(b));
		//i have also implemented lsd version of radix sort
		System.out.println("\nBefore radix_lsd in point c : \n" + Arrays.toString(c));
		radix_lsd(c);
		System.out.println("After radix_lsd in point c : \n" + Arrays.toString(c));

	}
	//the radix sort
	public static void radix_lsd(int[] a)
	{
		int m = max(a);
		int k = 0;
		for(int p_of_10 = 1; m/p_of_10>0; p_of_10*=10)
			k++;
		radix_lsd(a, a.length-1, (int)Math.pow(10,k-1));
	}
	//counting sort used for sorting array based on specific 
	//digit (digit specified via exponent which is a power of 10)
	public static void radix_lsd(int[] a, int hi ,int power_10)
	{
		int n = hi+1;
		int [] count = new int[10+1];
		int [] sorted = new int[n];
		int counter = 0, k=-1;
		//counting sort algorithm based on a single digits
		for(int i = 0; i<n; i++)
			count[(a[i]/power_10)%10]++;
		for(int i =1; i<10; i++)
			count[i] += count[i-1];
		for(int i = n-1; i>=0; i--)
		{
			sorted[count[(a[i]/power_10)%10]-1] = a[i];
			count[(a[i] / power_10)%10]--;
		}
		//calculate k for recursive call
		for(int i =0; i<n; i++)
		{
			a[i] = sorted[i];
			if((sorted[i]/power_10)%10 >0 && counter <1)
			{
				k = i-1;
				counter++;
			}
		}
		if(k<0)
			k = hi;		
		if(power_10>=10)
			radix_lsd(a, k, power_10/10);
	}

	public static void radix_msd(int[] a)
	{
		int m = max(a);
		int k = -1;
		for(int p_of_10 = 1; m/p_of_10>0; p_of_10*=10)
			k++;
		radix_msd(a,(int)Math.pow(10,k));
	}

	public static void radix_msd(int[] a, int power_10)
	{
		if(power_10 == 0)
			return;
		int n = a.length;
		//initialize the buckets
		ArrayList <ArrayList<Integer>> buckets = new ArrayList<ArrayList<Integer>>(10);
		for(int i = 0; i<10; i++)
			buckets.add(new ArrayList<Integer>());
		//put elements in proper buckets
		for(int i = 0; i<n; i++)
			buckets.get(digit(a[i],power_10)).add(a[i]);
		//sort each bucket recursively
		for(int i =0; i<10; i++)
		{	
			if(buckets.get(i).size()>=1)
			{
				radix_msd(buckets.get(i),power_10/10);
			}
		}				
		//merging the buckets
		int ind = 0;
    	for(int j = 0; j<10; j++)
    	{
    		if(buckets.get(j).size()>=1)
    		{
    			for(int i =0; i < buckets.get(j).size(); i++)
	    		{
	    			Object b = buckets.get(j).get(i);
	    			a[ind++] = ((Integer)b).intValue();
	    		}	
    		}	
    	}	
	}
	//same function but just with arraylists so that w can use recursion on buckets
	public static void radix_msd(ArrayList<Integer> a, int power_10)
	{	
		if(power_10 == 0)
			return;
		//initialize the buckets
		int n = a.size();
		ArrayList <ArrayList<Integer>> buckets = new ArrayList<ArrayList<Integer>>(10);
		for(int i = 0; i<10; i++)
			buckets.add(new ArrayList<Integer>());
		//put every element in the proper bucket
		for(int i = 0; i<n; i++)
			buckets.get(digit(a.get(i),power_10)).add(a.get(i));
		//recursively sort all buckets
		for(int i =0; i<10 ;i++)
		{
			if(buckets.get(i).size()>=1)
			{
				radix_msd(buckets.get(i),power_10/10);
			}
		}
		//merge the buckets
		int ind = 0;
    	for(int j = 0; j<10; j++)
    	{
    		if(buckets.get(j).size() >=1)
    		{
    			for(int i =0; i < buckets.get(j).size(); i++)
	    		{	
	    			Object b = buckets.get(j).get(i);
	    			a.set(ind++, ((Integer)b).intValue());	
	    		}
    		}
    	}
	}

    public static int digit(int n, int d)
    {
    	int a = ((n / d)%10);
    	return a;
    }

    //POINT C    
    public static void countSort(int arr[], int n, int exp) 
    { 
        int output[] = new int[n]; // output array 
        int i, count[] = new int[n] ; 
        for (i=0; i < n; i++) 
           count[i] = 0; 
  
        // Store count of occurrences in count[] 
        for (i = 0; i < n; i++) 
            count[ (arr[i]/exp)%n ]++; 
  
        // Change count[i] so that count[i] now contains actual 
        // position of this digit in output[] 
        for (i = 1; i < n; i++) 
            count[i] += count[i - 1]; 
  
        // Build the output array 
        for (i = n - 1; i >= 0; i--) 
        { 
            output[count[ (arr[i]/exp)%n] - 1] = arr[i]; 
            count[(arr[i]/exp)%n]--; 
        } 
  
        // Copy the output array to arr[], so that arr[] now 
        // contains sorted numbers according to curent digit 
        for (i = 0; i < n; i++) 
            arr[i] = output[i]; 
    } 
  
  
    // The main function to that sorts arr[] of size n using Radix Sort 
    public static void point_c_sort(int arr[], int n) 
    { 
        // Performs counting for the first digit in base n  
        countSort(arr, n, 1); 
        //Performs counting for the second digit in base n 
        countSort(arr, n, n); 
		//Performs counting for the third digit in base n 
		countSort(arr,n, n*n);
    } 

	public static int max(int[] a)
    {
    	int mx = a[0];
    	for(int i=1; i<a.length; i++)
    		if(a[i]>mx)
    			mx = a[i];

    	return mx;
    }
}