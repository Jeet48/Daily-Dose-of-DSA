#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start ++;
		end --;
	}
}

void printArray(int arr[], int size)
{
	for(int i = 0;i < size; i++)
		cout<<arr[i]<<" ";

	cout<<endl;
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the size of the array";
	cin>>n;
	cout<<"Enter the elements of the array";
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"Original array is ";
	printArray(arr, n);

	reverse(arr, 0, n-1);

	printArray(arr, n);

	return 0;
}