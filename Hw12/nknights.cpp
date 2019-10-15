#include <iostream>

using namespace std;

bool nknights(int**& board, int x, int y,int knights, int n);
void print(int**& board, int n);
bool is_free(int**& board, int x, int y, int n);
void allocate(int**& m, int n);
void deallocate(int**& m, int n);
int nr=1;

int main()
{
    int** board;
    int** visited, n;
    cout<<"Please enter the size of the board:"<<endl;
    cin>>n;
    // allocate memory
    allocate(board, n);
    // solve the n knights problem
    nknights(board, 0, 0, n, n);
    // deallocate mem 
    deallocate(board, n);

    return 0;
}

bool nknights(int**& board, int x, int y, int knights, int n)
{   
    //if no more knights to set
    if(knights == 0)
    {
        cout << nr << "-"<<endl;
        print(board, n);
        nr++;
        return true;
    }
    bool res = false;
    for(int row = x; row < n; row++)
    {
        if(row == x)
        {
            for(int col = y; col<n; col++)
            {
                // if position is save and has not been visited
                if(is_free(board, row, col, n))
                {
                    board[row][col] = 1;
                    res = (nknights(board, row, col, knights-1, n)) || res;
                    board[row][col] = 0;
                }
            }
        }else
        {
            for(int col = 0; col<n; col++)
            {
                // if position is save and has not been visited
                if(is_free(board, row, col, n))
                {
                    board[row][col] = 1;
                    res = (nknights(board, row, col, knights-1, n)) || res;
                    board[row][col] = 0;
                }
            }
        }
    }
    return res;
}

void print(int**& board, int n)
{
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            cout<<board[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool is_free(int**& board, int x, int y, int n)
{
    int r[] = {0 ,-2, -2, -1, -1, 1,  1,  2, 2};
    int c[] = {0 ,-1,  1, -2,  2, 2, -2, -1, 1};

    for(int i = 0; i<9; i++)
    {
        int row = x + r[i];
        int col = y + c[i];
        if(row < n && row >=0 && col <n && col>=0)
        {
            if(board[row][col] == 1)
                return false;
        }       
    }
    return true;
}

void allocate(int**& m, int n)
{
    m = new int*[n];
    for(int i = 0; i<n; i++)
    {
        m[i] = new int[n];
    }
    // initialize
    for(int i = 0; i< n; i++)
        for(int j = 0; j<n; j++)
            m[i][j] = 0;
}

void deallocate(int**& m, int n)
{
    for(int i = 0; i<n; i++)
    {
        delete[] m[i];
    }
    delete[] m;
}
