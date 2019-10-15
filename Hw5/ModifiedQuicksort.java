import java.util.Random;

public class ModifiedQuicksort
{
	private static Random rand = new Random();
	public static void main(String [] args)
	{
		System.out.println("Testing the random modified version");
		int [] a = {25 ,37 ,157 ,78 ,95 ,9 ,-2};
		System.out.print("Before: ");
		for(int i =0; i<a.length; i++)
			System.out.print(a[i] + " ");
		//sorts the array
		random_mod_quicksor(a, 0, a.length-1);
		System.out.print("After: ");	
		for(int i =0; i<a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println();
		

		
		System.out.println("Testing the modified version");
		int [] b = {5 ,33 ,17 ,71 ,145 ,99 ,20};
		System.out.print("Before: ");
		for(int i =0; i<b.length; i++)
			System.out.print(b[i] + " ");
		//sorts the array
		modquick(b, 0, b.length-1);	
		System.out.print("After: ");
		for(int i =0; i<b.length; i++)
			System.out.print(b[i] + " ");
		System.out.println();
		
	}

	public static void modquick(int []A, int l, int r)
	{
		if(r-l == 1)
		{
			if(A[l] > A[r])
				swap(A, l, r);
			return;
		}

		if(l < r)
		{			
			if(A[l] > A[l+1])
				swap(A, l, l+1);
			int pivot1 = A[l], pivot2 = A[l+1];
			//will keep track of the end position of pivot 1
			int i = l;
			//will keep track of the end position of pivot 2
			int  j = l+1; 
			//will be used to iterate over the array
			int k = l+2;
			//will keep track of the current position of 
			//the value of pivot 2 
			int  pos = j;

			for(; k<=r; k++)
			{
				if(A[k] <= pivot2)
				{
					j++;
					swap(A, j, k);
					if(A[j] <= pivot1)
					{
						i++;
						swap(A, i, j);
						if(A[j] == pivot2)
						{
							pos = j;
						}
					}
				}
			}
			//make sure the pivots goes back to position i and j
			swap(A,j,pos);
			swap(A,l, i);
			//set k to the last value array
			k--;
			//recursive calls
			modquick(A, 0, i-1);
			modquick(A, i+1, j-1);
			modquick(A, j+1, k);
		}
	}

	public static void random_mod_quicksor(int []A, int l, int r)
	{
		int i = 0, j =0;
		//make sure i and j are different
		while(i==j)
		{
			i = rand.nextInt(r);
			j = rand.nextInt(r);
		}
		swap(A, l, i);
		swap(A, l+1, j);
		modquick(A,l,r);
	}	
	//helper function to swap to array values
	public static void swap(int A[], int i, int j)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}
