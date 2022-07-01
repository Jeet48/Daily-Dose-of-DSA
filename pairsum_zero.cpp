#include<bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n)
{

    unordered_map<int, int> m; 
	int ans = 0;
	for(int i = 0;i < n; i++)
	{
		int b = -arr[i];
		if(m[b])
		{
			ans+=m[b];
		}
		m[arr[i]]++;
	}
	return ans;
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<pairSum(arr, n);

	return 0;
}