/*
	For better time complexity the algorithm
	usually uses more complex hashing function
	but since we just want to make a simple
	implementation without specifications on time
	complexity, I have chosen a simple hash function
	which just takes the sum of the ASCII codes of the chars
*/

//REFERENCE : https://www.youtube.com/watch?v=qQ8vS2btsxI
#include <bits/stdc++.h>

using namespace std;


void rabin_karp(string t, string p);

int main()
{
	string text("Hello world. I love this wonderful world!!");
	string patt("world");
	rabin_karp(text, patt);
	return 0;
}

void rabin_karp(string t, string p)
{
	int tsize = t.length();
	int psize = p.length();
	int a = 0, b = 0, j;// a is hash value for pattern, b for text

	cout << "Pattern found at indeces: ";
	//we calculate the hash function of the first psize chars in text
	for(int i = 0; i<psize; i++)
	{
		a+=p[i];
		b+=t[i];
	}
	//moving pattern over the text to make comparisons
	for(int i = 0; i<= tsize - psize; i++)
	{
		//if we have a match
		if(a == b)
		{
			//compare the patterns
			for(j = 0; j< psize; j++)
			{
				if(t[i+j] != p[j])
					break;
			}
			//we found an occurence of the pattern
			if(j == psize)
				cout << i <<" ";
		}
		if(i!= tsize - psize)
		{
			b = b- t[i] + t[i+psize];
		}
	}

	cout << endl;
}
