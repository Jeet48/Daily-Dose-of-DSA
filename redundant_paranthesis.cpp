#include <bits/stdc++.h>
using namespace std;

bool checkRedundancy(string &str)
{
	stack<char> st;

	for(auto& ch : str)
	{
		if(ch == ')')
		{
			char top = st.top();
			st.pop();

			bool flag = true;

			while(!st.empty() and top != '(')
			{
				if(top == '+' || top == '-' || top == '*' || top == '/')
				    flag = false;

				top = st.top();
				st.pop();
			}


			if(flag == true)
				return true;
		}

		else
			st.push(ch);
	}
	return false;
}

void findRedundancy(string &str)
{
	bool ans = checkRedundancy(str);
	if(ans == true)
		cout<<"Yes the string is redundant";
	else
		cout<<"No the string is not redundant";
}

int main()
{
	string str;
	cout<<" Enter the string ";
	cin>>str;

	findRedundancy(str);

	return 0;
}