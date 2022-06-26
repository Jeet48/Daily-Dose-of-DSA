#include<bits/stdc++.h>
using namespace std;

int climb(int n)
{
	if(n == 0)
		return 1;
    if(n == 1)
    	return 1;


	return climb(n-1) + climb(n-2);

}

int main()
{
	vector<int> dp(1000, -1);
	int n;
	cout<<"Enter the value of n";
	cin>>n;

	dp[0] = 1;
	dp[1] = 1;
	for(int i = 2; i <= n ;i++)
	{
		dp[i] = dp[i-1] + dp[i-2];
	}
	cout<<"Number of ways through which we can reach nth step is ";
	cout<<dp[n];

	return 0;
}