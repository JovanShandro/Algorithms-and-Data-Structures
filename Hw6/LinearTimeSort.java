import java.util.*;
import java.util.Collections;

public class LinearTimeSort
{
	public static final int ascii_size = 256;
	public static void main(String[] args)
	{
		int []a = {9, 1, 6, 7, 6, 2, 1};
		double []b = {0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1};
		String []s = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
		int k = max(a);

		////////*Point a*///////
		//print array before sort
		System.out.println("\nCounting sort: \nBefore :");
		for(int i=0; i<a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println();
		//sort
		counting_sort(a, k);
		//print after sort
		System.out.println("After: ");
		for(int i=0; i<a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println();

		/////////Point b////////
		//now use bucket sort in b
		System.out.println("\nBucket sort: \nBefore :");
		for(int i=0; i<b.length; i++)
			System.out.print(b[i] + " ");
		System.out.println();
		//sort
		bucket_sort(b);
		//after
		System.out.println("After: ");
		for(int i=0; i<b.length; i++)
			System.out.print(b[i] + " ");
		System.out.println();

		///////Point d//////
		//now use bucket sort in s
		System.out.println("\nString sort in linear time: \nBefore :");
		for(int i=0; i<s.length; i++)
			System.out.print(s[i] + " ");
		System.out.println();
		//sort
		string_sort(s);
		//after
		System.out.println("After: ");
		for(int i=0; i<s.length; i++)
			System.out.print(s[i] + " ");
		System.out.println();
	}

	public static void counting_sort(int a[], int k) 
    { 
    	int n = a.length;
    	//the array used for counting
    	int []c = new int[k+1];
    	//the array that will store the sorted version
    	int []b = new int[n];
    	//initialize c to all entries 0
    	for(int i =0; i<=k; i++)
    		c[i] = 0;
    	//increase counter
    	for(int j = 0; j<n; j++)
    		c[a[j]]++;
    	for(int j = 1; j<=k; j++)
    		c[j] += c[j-1];
    	for(int j = n-1; j>=0; j--)
    	{
    		b[c[a[j]]-1] = a[j];
    		c[a[j]]--;
    	}
    	//make a equal b
    	for(int i =0; i<n; i++)
    		a[i] = b[i];
    }

	public static void bucket_sort(double[] a)
    {
    	int n = a.length;
    	//create the buckets
    	ArrayList <ArrayList<Double>> buckets = new ArrayList<ArrayList<Double>>(10);
		for(int i = 0; i<10; i++)
			buckets.add(new ArrayList<Double>());
    	//adding the entries of the array to the buckets
		for(int i = 0; i<n; i++)
			buckets.get((int)(n*a[i])).add(a[i]);
       	//sort each bucket in O(nlgn) time
    	for(int i = 0; i<10; i++)
    		Collections.sort(buckets.get(i));
    	//merge the buckets in the original array
    	int ind = 0;
    	for(int j = 0; j<10; j++)
    	{
    		if(buckets.get(j).size() >=1)
    		{
    			for(int i =0; i < buckets.get(j).size(); i++)
	    		{	
	    			Object b = buckets.get(j).get(i);
	    			a[ind++]= ((Double)b).doubleValue();	
	    		}
    		}
    	}
    }
    // a recursive approach similar to the msd radix sort in problem 2
    public static void string_sort(String[] a)
    {
    	String b[] = new String[a.length];
    	string_sort(a, b, 0, a.length-1, 0);
    }

    public static void string_sort(String[] a, String[] b, int lo, int hi, int d)
    {
    	if(hi<=lo)return;
    	int[] count = new int[ascii_size+2];
    	for(int i = lo; i<=hi; i++)
    		count[at(a[i], d)+2]++;
    	for(int i = 0; i<ascii_size+1; i++)
    		count[i+1]+=count[i];
    	for(int i = lo; i<=hi; i++)
    		b[count[at(a[i], d) + 1]++] = a[i];
    	for(int i = lo; i<=hi; i++)
    		a[i] = b[i-lo];

    	for(int i = 0; i<ascii_size; i++)
    		string_sort(a,b,lo+count[i], lo+count[i+1] -1 ,d+1);
    }
    
    //helper functions
    public static int at(String s, int d)
    {
    	if(d < s.length()) return s.charAt(d);
    	else return -1; 
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