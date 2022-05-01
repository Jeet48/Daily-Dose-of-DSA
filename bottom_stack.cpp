// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;


stack<int> recur(stack<int> S, int N)
{
	
	if (S.empty())
		S.push(N);

	else {

		
		int X = S.top();

		
		S.pop();

		
		S = recur(S, N);

		
		S.push(X);
	}
	return S;
}


void insertToBottom(
	stack<int> S, int N)
{

	
	S = recur(S, N);

	
	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
}


int main()
{
	// Input
	stack<int> S;
	S.push(8);
	S.push(7);
	S.push(6);
	S.push(5);
	S.push(4);
	S.push(3);
	S.push(2);
	S.push(1);

	int N = 15;

	insertToBottom(S, N);

	return 0;
}
