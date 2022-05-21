#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int n)
{
	int i,j;
	bool swapped;
	for(int i=0;i<n-1;i++)
	{
		swapped=false;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swap(arr[j],arr[j+1]);
				swapped=true;
			}
		}

		if(swapped==false)
			break;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for(i=0;i<size;i++)
		cout<<" "<<arr[i];
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the elements of an array";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}

	bubbleSort(arr,n);
	cout<<"Sorted array is ";
	printArray(arr, n);
	return 0;
}