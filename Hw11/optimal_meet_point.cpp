#include <bits/stdc++.h>
# define INF 10000000
using namespace std;


int find_meetup_city(int** adj_matrix, int your_city, int friend_city);
int sum_of_path(int **adj_matrix, int source, int target);

int* d;
int n;
//will be used in priority queue
typedef pair<int, int> intpair;

int main()
{
	cout<<"Enter n: "<<endl;
	cin >> n;
	int **m, mycity, friendcity;
	m = new int*[n];
	for(int i = 0; i<n; i++)
	{
		m[i] = new int[n];
	}
	cout<<"Enter adj_matrix: "<<endl;
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>m[i][j];

	cout<<"Enter my city: "<<endl;
	cin >> mycity;

	cout<<"Enter friend city: "<<endl;
	cin >> friendcity;
	
	cout << "The optimal meeting point is : "<<find_meetup_city(m,mycity, friendcity);

	for(int i = 0; i<n; i++)
		delete []m[i];
	delete []m;

	return 0;
}

//finds sum of weights down a path
int sum_of_path(int **adj_matrix, int source, int target)
{
	if(source == target)
		return 0;

	int dist[n];
	//array of predecessors
	int pred[n];
	pred[source] = -1;
	//will keep track of the path
	deque<int> de;

	for(int i = 0; i < n; i++)
		dist[i] = INF;

	priority_queue<intpair, vector<intpair>, greater<intpair>> q;
	q.push(make_pair(0, source));
	dist[source]= 0;
	/*Dijkstra Algorithm*/
	while(!q.empty())
	{
		int node = q.top().second;
		q.pop();
		for(int i = n-1; i>=0; i--)
		{
			int weight = adj_matrix[node][i];
			if((dist[i] > dist[node] + weight) && weight!=0)
			{
				dist[i] = dist[node] + weight;
				pred[i] = node;
				q.push(make_pair(dist[i],i));
			} 
		}
	}
	
	for(int i = pred[target]; i!=source; i = pred[i])
		de.push_front(i);
	de.push_front(source);
	de.push_back(target);
	
	int i = 0, j = (int)de.size()-1;
	int sum=0;
	while(i<j)
	{
		sum+= adj_matrix[de[i]][de[1+(i++)]];
	}
	
	return sum;
}


int find_meetup_city(int** adj_matrix, int your_city, int friend_city)
{
	intpair ip[n];
	for(int i = 0; i<n; i++)
	{
		int a = sum_of_path(adj_matrix, i, your_city);
		int b = sum_of_path(adj_matrix, i, friend_city);
		ip[i].first = i;
		ip[i].second = max(a, b);
	}
	intpair optimal = ip[0];
	for(int i =1; i<n; i++)
	{
		if(ip[i].second < optimal.second)
			optimal = ip[i];
	}

	return optimal.first;
}