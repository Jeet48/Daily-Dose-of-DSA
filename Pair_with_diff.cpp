#include<iostream>
using namespace std;

int getPairsWithDifference(int *arr,int n, int k)
{
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = i+1 ; j<n; j++)
			if(arr[i] - arr[j] == k || arr[j] - arr[i] == k)
				count++;
	}
	return count;
}

int main()
{
	int n;
	cout<<"Enter the value of n";
	cin>>n;

	int a[100];
	cout<<"Enter the value of array";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}

	int k;
	cout<<"Enter the value of k";
	cin>>k;

	cout<<getPairsWithDifference(a, n, k);

	return 0;
}