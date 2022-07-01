#include<bits/stdc++.h>
using namespace std;

void printf(int ind, vector<int> &ds, int arr[], int n)
{
	if(ind==n)
	{
		for(auto it : ds)
		{
			cout<<it<<" ";
		}
		cout<<endl;
		return;
	}

	ds.push_back(arr[ind]);
	printf(ind + 1,ds,arr,n);
	ds.pop_back();

	printf(ind + 1,ds,arr,n);
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

	vector<int>ds;
	printf(0, ds, arr, n);
}