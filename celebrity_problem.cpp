#include<bits/stdc++.h>
#include<list>

using namespace std;

#define N 8

bool MATRIX[N][N] = {{0,0,1,0},
                     {0,0,1,0},         
                     {0,0,0,0},
                     {0,0,1,0}};

bool knows(int a,int b)
{
	return MATRIX[a][b];
}

int findCelebrity(int n)
{
	stack<int> s;
	int C;

	for(int i=0;i<n;i++)
		s.push(i);

	while(s.size()>1)
	{
		int A = s.top();
		s.pop();
		int B = s.top();
		s.pop();
		if(knows(A,B))
		{
			s.push(B);
		}
		else
		{
			s.push(A);
		} 
	}


	if(s.empty())
		return -1;

	C=s.top();
	s.pop();


	for(int i=0;i<n;i++)
	{
		if((i!=C) && (knows(C,i)||!knows(i,C)))
			return -1;
		
	}

	return C;
}

int main()
{
	int n = 4;
	int id = findCelebrity(n);
	id==1 ? cout<<"No Celebrity found " : cout<<"Celebrity ID is "<<id;

	return 0;
}