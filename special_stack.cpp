#include<iostream>
#include<stack>
#include<vector>
using namespace std;


class SpecialStack
{
	int min=-1;

	static const int demoVal=9999;

	stack<int>st;


public:


	void getMin()
	{
		cout<<"min is: "<<min<<endl;
	}


	void push(int val)
	{
		if(st.empty()||val<min)
		{
			min=val;
		}

		st.push(val*demoVal+min);
		cout<<"pushed: "<<val<<endl;
	}


	int pop()
	{
		if(st.empty()) {
			cout<<"stack underflow"<<endl;
			return -1;
		}

		int val=st.top();
		st.pop();

		if(!st.empty())
			min=st.top()%demoVal;
		else
			min=-1;
		cout<<"popped: "<<val / demoVal <<endl;

		return val/demoVal;
	}

	int peek()
	{
		return st.top() / demoVal;
	}
};

int main() 
{
	SpecialStack s;

	vector<int> arr;

	int n;
	cout<<"Enter the value of n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		arr.push_back(a);
	}
	for(auto i = 0;i<arr.size();i++)
		{
			s.push(arr[i]);
			s.getMin();
		}
		cout<<endl;
	for(auto i = 0;i<arr.size();i++)
	{
		s.pop();
		s.getMin();
	}
	return 0;
}