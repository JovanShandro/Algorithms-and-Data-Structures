#include <iostream>
#include <vector>

using namespace std;

/*
	The main idea behind this greedy algorithm is
	as follows: We first iterate through all 
	the activities to find the one with max start time
	and then we push this the the results vector and
	pop it from the first container. The we keep track
	of the previous max, and we iterate again to find the 
	activity with the largest starting time out of the 
	remaining activities. We check if the final time
	of this one is smaller then the start time of the 
	previous max and if so we push it to the results,
	pop it from the initial container and make it 
	a previous max. This algorithm will always find a 
	globally optimal solution as the idea behind it
	is similar to the example we did in class.
	And most importantly as stated by the problem,
	it does not just sort and select the activity.
*/

class Activity
{
	public:
		int s;
		int f;
		Activity(int st, int fi) : s(st), f(fi){}
		Activity& operator=(Activity a){
			s = a.s;
			f = a.f;
			return *this;
		}
};

vector <Activity> greedy_selector(vector<Activity> v);
void print(vector<Activity> v);

int main()
{
	cout << "\nRunning problem 9.2\n" <<endl;

	Activity a1(1,4), a2(3,5), a3(0,6), a4(3,8);
	Activity a5(5,7), a6(5,9), a7(6,10), a8(8,11);
	Activity a9(8,12), a10(2,13), a11(12,14);

	vector<Activity> a = {a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11};

	vector <Activity> result = greedy_selector(a);
	cout << "The biggest subset of mutually compatible activites is:" << endl;
	print(result);

	return 0;
}

vector <Activity> greedy_selector(vector<Activity> v)
{
	int n = (int)v.size();	
	vector<Activity> result;
	vector<Activity>::iterator maxit;//will keep track of what should be erased
	Activity max(-1,-1), prevmax(-1,-1);
	while(v.size())
	{
		max = v[0];
		for(auto iter = v.begin(); iter!=v.end(); iter++)
		{
			if((*iter).s >= max.s)
			{
				max = *iter;
				maxit = iter;
			}
		}
		if(prevmax.s == -1 && prevmax.f == -1)
		{
			result.push_back(max);
			prevmax = max;	
			v.erase(maxit);
		}
		else
		{
			if(max.f <= prevmax.s)
			{
				result.push_back(max);
				prevmax = max;

			}
			v.erase(maxit);
		}
	}

	return result;
}

void print(vector<Activity> v)
{
	int i = 1;
	cout << "{ ";
	for(auto it = v.begin(); it != v.end(); it++, i++)
	{
		cout << "("<<(*it).s << ","<< (*it).f << ")";
		if(it != v.end()-1)
			cout<<", ";
	}
	cout<<" }"<<endl;
}
