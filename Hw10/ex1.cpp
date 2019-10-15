//Reference: https://www.youtube.com/watch?v=E6us4nmXTHs
// I have implemented the algorithm described in the video above
#include <bits/stdc++.h> 
using namespace std; 
 
// a- is the initial vector result- will carry the long.inc.sub 
void longest_sub(vector<int> &a, vector<int> &result) 
{ 
    int n = a.size();
    /* the list will be used for 
       backtracking in the end */
    list<int> l;
    int len[n], s[n];
    for(int i = 0; i<n; i++)
    {
        len[i] = 1;
        s[i]   = 0;
    }
    if(n == 1)//case only one value is entered
    {
        result.push_back(a[0]);
        return;
    }else
    {
        int i = 1;
        while(i < n)
        {
            int j = 0;
            while(j < i)
            {
                if(a[j] < a[i])
                {
                    len[i] = max(len[i], 1 + len[j]);
                    if(len[i] == (1+len[j]))
                        s[i] = j;
                }   
                j++;
            }
            i++;
        }
    }
    int count = 0;
    int max = len[0], maxindex = 0;
    //find max value and its index
    for(int i = 1; i<n; i++)
    {
        if(len[i] > max)
        {
            max = len[i];
            maxindex = i;
        }
    }
    //going back in s from end to front
    for(int h = s[maxindex], p = maxindex; p >0; p = h, h=s[h])
    {
        l.push_front(a[p]);
        count++;
    }
    if (count< max)
        l.push_front(a[0]);
    //pushing the final sequece to result
    for(int g : l)
        result.push_back(g);
} 
  
int main() 
{ 
    /*
        I have used a stringstream to read 
        the input as a whole line and then 
        decompose it into integers
    */
    int count = 1;
    string line;
    getline(cin,line);
    for(int i = 0; i<(int)line.length(); i++)
    {
        if(line[i] == ' ')
            count++;
    }

    const int arrSize = count;
    int arr[arrSize] = {0}; //initialize arr zeros
    vector<int> vec;
   
    stringstream ss (line);

    int i = 0;
    while ( ss>>arr[i++] ); 

    for (int i =0; i < arrSize; i++) 
        vec.push_back(arr[i]);

    vector<int> lis;
    longest_sub(vec, lis);

    for (size_t i = 0; i < lis.size(); i++)
        cout << lis[i]<<" ";
    cout << "\n";    

    return 0;
} 