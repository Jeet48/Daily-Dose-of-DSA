#include<bits/stdc++.h>
using namespace std;

bool findpartition(int arr[], int n)
{
	int sum = 0;
	int i, j;

	for(i=0;i<n;i++)
		sum += arr[i];

	if(sum % 2 != 0)
		return false;

	bool part[sum / 2 + 1][n + 1];
	for(i = 0; i <= n ; i++)
		part[0][i] = true;

	for(i = 1;i<=sum/2;i++)
		part[i][0] = false;

	for(i = 1; i <= sum/2;i++)
	{
		for(j = 1; j<=n ; j++)
		{
			part[i][j] = part[i][j-1];
			if(i >= arr[j-1])
				part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
		}
	}

	for(i = 0;i <= sum/2; i++)
	{
		for(j = 0; j <= n; j++)
			cout<<part[i][j];

		cout<<endl;
	}

	return part[sum / 2][n];
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;

	cout<<"Enter the elements of the array";
	for(int i = 0; i< n; i++)
	{
		cin>>arr[i];
	}

	if(findpartition(arr, n) == true)
		cout<<"Can be divivded into subparts";
	else
		cout<<"Cannot be divided into subparts";

	return 0;
}