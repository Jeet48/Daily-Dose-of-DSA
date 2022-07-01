#include <bits/stdc++.h>
using namespace std;

int mostFrequent(int arr[], int n)
{
	unordered_map<int, int> hash;
	for(int i = 0;i<n;i++)
		hash[arr[i]]++;

	int maxcount = 0, res=-1;
	for(auto i : hash)
	{
		if(maxcount<i.second)
		{
			res = i.first;
			maxcount = i.second;
		}
	}
	return res;
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;

	cout<<"Enter the elements of the array";
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"Most frequent elements in the array is "<<mostFrequent(arr, n);

	return 0;
}