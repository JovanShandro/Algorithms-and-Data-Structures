#include <bits/stdc++.h>

using namespace std;

//the matrix that will be used to store the numbers

int matrix[100][100];
void find_max_path(int m[100][100], int size, int& sum, vector<int>& path);

int main()
{
	string str;
	int nrlines = 0, sum, nr_per_line, h;
	vector<int> path;

	while(getline(cin, str))
	{
		if (str == "")
			break;
		nr_per_line = 0;
		nrlines++;
		stringstream s(str);
		//check for symbols
		
		for(int f = 0; str[f]; f++)
		{
			if(!isdigit(str[f]) && str[f] != ' ' && (str[f] == '-' && !isdigit(str[f+1])))
			{
				cout<<"A character other than a number is entered!!!" << endl;
				exit(1);
			}
		}
		//check for numbers not in range
		
		while(s>>h)
		{
			nr_per_line++;
			if(h<1 || h>10000)
			{
				cout<<"Number out of range entered!!!" << endl;
				exit(2);
			}
		}	
		
    	if(nr_per_line != nrlines)
    	{
    		cout<<"Wrong amount of numbers entered on the line!!!" << endl;
			exit(3);
    	}
    	//read the matrix row from the entered line
		stringstream ss(str);
		for(int m = 0; m < nrlines; m++)
		{
			ss>>matrix[nrlines-1][m];
		}
		if(nrlines == 100)
			break;
	}
	//find the path
	find_max_path(matrix, nrlines, sum, path);
	//print sum and path
	cout << sum<<endl;
	for(int i = 0; i<(int)path.size(); i++)
	{
		cout<<path[i];
		if(i!= (int)path.size()-1)
			cout<<" ";
	}
	cout<<endl;
	return 0;
}

void find_max_path(int m[100][100], int size, int& sum, vector<int>& path)
{
	int a = size-2;//second last row
	while(a >=0)
	{
		for(int i = 0; i<=a; i++)
		{
			m[a][i] += max(m[a+1][i], m[a+1][i+1]);
		}
		a--;
	}	
	//getting sum
	sum =m[0][0];
	//getting the path
	int row = 0, col = 0;
	while(path.size() != size)
	{
		if(path.size() == size-1)
		{
			path.push_back(m[row][col]);	
			continue;		
		}
		path.push_back(m[row][col] - max(m[row+1][col],m[row+1][col+1]));

		if(m[row+1][col] < m[row+1][col+1])
			col++;
		row++;
	}
}

