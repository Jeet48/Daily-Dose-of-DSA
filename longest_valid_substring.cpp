#include<bits/stdc++.h>
#include<string.h>

using namespace std;

int findMaxLen(string str)
{
	int n = str.length();

	stack<int> stk;
	stk.push(-1);

	int result = 0;

	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
			stk.push(i);

		else{
			if(!stk.empty())
			{
				stk.pop();
			}


			if(!stk.empty())
				result = max(result, i - stk.top());
			else
				stk.push(i);
		}
	}

	return result;
}


int main()
{
	string expr;
	cout<<"Enter the string for example (())";
	cin>>expr;

	cout<<"Length of the maximum substring is "<<findMaxLen(expr)<<endl;

	return 0;
}