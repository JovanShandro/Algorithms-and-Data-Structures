#include <bits/stdc++.h>
using namespace std;

deque<int> cylinders;
int tmax, amax,	solution[1001][22][80], t[1000], w[1000], a[1000];

int find_min(int i, int o, int n)
{
	if(o ==0 && n ==0)
		solution[i][o][n] = 0;
	else if(i == 0)
	{
		//assuming the diver is not Hulk, we set the following upper bound
		solution[i][o][n] = 10000000;
	}
	else
	{
		solution[i][o][n] = min(find_min(i-1, o, n), 
			find_min(i-1, max(o-t[i-1],0), max(n-a[i-1], 0))+ w[i-1]);
	}
	
	return	solution[i][o][n];
}

void find_cyl(int i, int o, int n)
{
	int k = i;
	int l = o;
	int m = n;
	int weight =solution[i][o][n];
	while(k>0 && weight>0)
	{
		if(	solution[k][l][m] != solution[k-1][l][m])
		{
			weight -= w[k-1];
			if(l > t[k-1])
				l-= t[k-1];
			else 
				l = 0;
			if(m > a[k-1])
				m-= a[k-1];
			else 
				m = 0;
			cylinders.push_front(k);
			k--;
		}
		else
		{
			k--;

		}
	}
}


int main()
{
	int c, n;
	cin >> c;
	deque<int> cyl;

	while(c--)
	{
		//get t
		cin >> tmax;
		while(tmax < 1 || tmax >21)
		{
			cout<<"Entered t is out of range"<<endl;
			exit(1);
		}
		//get a
		cin >> amax;
		while(amax < 1 || amax >79)
		{
			cout<<"Entered a is out of range"<<endl;
			exit(2);
		}
		//get n
		cin >> n;
		while(n < 1 || n >1000)
		{
			cout<<"Entered n is out of range"<<endl;
			exit(3);
		}
		//get all the values TODO ke raste pa marre
		for(int i = 0; i<n; i++)
		{
			cin>>t[i] >> a[i] >> w[i];
			while(t[i] < 1 || t[i] >21)
			{
				cout<<"Entered value of t["<< i <<"] is out of range"<<endl;
				exit(4);
			}
			while(a[i] < 1 || a[i] >79)
			{
				cout<<"Entered value of a["<< i <<"] is out of range"<<endl;
				exit(5);
			}while(w[i] < 1 || w[i] >800)
			{
				cout<<"Entered value of w["<< i <<"] is out of range"<<endl;
				exit(6);
			}
		}

		cout<<find_min(n, tmax, amax) << endl;
		find_cyl(n, tmax, amax);

		for(int i = 0; i<(int)cylinders.size(); i++)
		{
			cout<<cylinders[i];
			if(i != (int)cylinders.size()-1)
 				cout<<" ";
		}

	}
	return 0;
}