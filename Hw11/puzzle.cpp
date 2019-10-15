#include <bits/stdc++.h>

using namespace std;

//this pair will be helpful when implementing dijkstra for the priority queue
typedef pair<int, int> intpair;

struct position
{
	int i;
	int j;
};

//class PuzzleBoard;

class PuzzleBoard {
	private:
	// your choice
	int ** maze;
	int ** graph;
	int graphsize;
	int mazesize;
	position current;
	public:
	// Subpoint (b)
	PuzzleBoard(int boardSize, int** fields = nullptr);
	/* constructor should create the
	graph (as you defined it in subpoint (a) with the values from fields.
	If fields is null, then initialize the fields of the board with
	random values between 1 and boardSize-1. */
	bool makeMove(int direction);
	/* makes the move (if valid), direction is 0 for up, 1
	for right, 2 for down, 3 for left. Returns true if the move was
	valid, false otherwise. */
	bool getResult();
	/* Returns false if game is not over yet, true if puzzle was solved */
	friend ostream &operator<<(ostream &os, PuzzleBoard const &m);
	/* in Python, this is the __str__ method. */
	// Subpoint (c)
	int solve();
	/* returns the minimum number of moves needed to solve the puzzle,
	and -1 if it is not solvable. */
	~PuzzleBoard();
	/* destructor to deallocate the memory for the graph and board*/
};


PuzzleBoard::PuzzleBoard(int boardSize, int** fields)
{
	mazesize = boardSize;
	graphsize = boardSize*boardSize;
	//set position to first entry
	current.i=0;
	current.j=0;

	maze = new int*[mazesize];
	for(int i = 0; i<mazesize; i++)
	{
		maze[i] = new int[mazesize];
	}

	graph = new int*[graphsize];
	for(int i = 0; i<graphsize; i++)
	{
		graph[i] = new int[graphsize];
	}
	//copying the maze
	for(int i = 0; i<boardSize; i++)
		for(int j = 0; j<boardSize; j++)
			maze[i][j] = fields[i][j];
	//creating the graph
	for(int i = 0; i<mazesize; i++)
	{
		for(int j = 0; j<mazesize; j++)
		{
			int value = maze[i][j];
			if(i-value >= 0)
			{
				int x = i*mazesize+j;
				int y = (i-value)*mazesize+j;
				graph[x][y] = 1;
			}

			if(j-value>=0)
			{
				int x = i*mazesize+j;
				int y = i*mazesize+(j-value);
				graph[x][y] = 1;
			}

			if(i+value < mazesize)
			{
				int x = i*mazesize+j;
				int y = (i+value)*mazesize+j;
				graph[x][y] = 1;
			}

			if(j+value < mazesize)
			{
				int x = i*mazesize+j;
				int y = (i)*mazesize+(j+value);
				graph[x][y] = 1;	
			}

		}
	}
}

PuzzleBoard::~PuzzleBoard()
{
	//maze
	for(int i = 0; i<mazesize; i++)
		delete []maze[i];
	delete []maze;
	//graph
	for(int i = 0; i<graphsize; i++)
		delete []graph[i];
	delete []graph;		
}

bool PuzzleBoard::getResult()
{
	if(current.i == mazesize-1 && 
	   current.j == mazesize-1)
		return true;
	else
		return false;
}

ostream &operator<<(ostream &os, PuzzleBoard const &m)
{
	os<<"Printing number maze:" << endl;
	for(int i = 0; i<m.mazesize; i++)
	{
		for(int j = 0; j<m.mazesize; j++)
		{
			os<<m.maze[i][j]<<" ";
		}
		os<<endl;
	}
	os<<"Printing graph representation:"<<endl;
	for(int i = 0; i<m.graphsize; i++)
	{
		for(int j = 0; j<m.graphsize; j++)
		{
			os<<m.graph[i][j]<<" ";
		}
		os<<endl;
	}
	return os;
}

//I have used the same algorithm from last time
int PuzzleBoard::solve()
{
	int source = 0;
	int target = graphsize-1;

	int d[graphsize];
	for(int i =0; i<graphsize; i++)
		d[i] = 1000000;

	priority_queue<intpair, vector<intpair>, greater<intpair>> q;
	q.push(make_pair(0,source));
	d[source] = 0;

	while(!q.empty())
	{
		int node = q.top().second;
		q.pop();
		for(int i = 0; i<graphsize; i++)
		{
			int weight = graph[node][i];
			if((d[i] > d[node] + weight) && (weight!=0))
			{
				d[i] = d[node] + weight;
				q.push(make_pair(d[i],i));
			}
		}
	}
	if(d[target] == 1000000)//if no solution found
		return -1;
	else
		return d[target];
}

bool PuzzleBoard::makeMove(int direction)
{
	int i = current.i;
	int j = current.j;
	int value = maze[i][j];
	switch(direction)
	{
		case 0:
			if(i-value >= 0)
			{
				current.i = (i-value);
				return true;
			}
			break;
		case 1:
			if(j+value < mazesize)
			{
				current.j = j+value;	
				return true;
			}
			break;
		case 2:
			if(i+value < mazesize)
			{
				current.i = i+value;
				return true;
			}
			break;
		case 3:
			if(j-value>=0)
			{
				current.j = j-value;	
				return true;
			}
			break;
	}
		
	return false;
}


int main()
{ 
	int n;
	cin >> n;
	int **m;
	m = new int*[n];
	for(int i = 0; i<n; i++)
	{
		m[i] = new int[n];
	}
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin>>m[i][j];
	PuzzleBoard a(n, m);
	cout<<a;
	cout << a.solve()<<endl;

	for(int i = 0; i<n; i++)
		delete []m[i];
	delete []m;

	return 0;
}