#include<iostream>
using namespace std;

int shellSort(int arr[], int n)
{
	for(int gap = n/2;gap > 0; gap /=2)
	{
		for(int i = gap ; i < n ; i+=1)
		{
			int temp = arr[i];

			int j;
			for(j = i; j >= gap && arr[j-gap] > temp; j -= gap)
				arr[j] = arr[j - gap];

			arr[j] = temp;
		}
	}
	return 0;
}

void printArray(int arr[], int n)
{
	for(int i = 0;i<n;i++)
		cout<< arr[i] << " ";
}

int main()
{
	int arr[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;

	cout<<"Enter elements in an array";
	for(int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}

	cout<<"Array before sorting ";
	printArray(arr, n);

	shellSort(arr, n);

	cout<<"Array after sorting ";
	printArray(arr, n);

	return 0;
}