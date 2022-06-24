#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
	priority_queue<int> pq;

	for(int i = 0; i < k; i++)
	{
		pq.push(arr[i]);
	}

	for(int i = k; i < n ;i++)
	{
		if(arr[i] < pq.top())
		{
			pq.pop();

			pq.push(arr[i]);
		}
	}

	return pq.top();
}

int main()
{
	int n;
	cout<<"Enter the element of n";
	cin>>n;

	int arr[100];
	cout<<"Enter the elements of the array";
	for(int i = 0;i < n;i++)
	{
		cin>>arr[i];
	}
	int k;
	cout<<"Enter the value of k";
	cin>>k;

	cout<<"kth smallest element is "<<kthSmallest(arr, n, k);

	return 0;
}

