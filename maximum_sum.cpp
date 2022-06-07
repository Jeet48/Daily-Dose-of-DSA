#include<bits/stdc++.h>
using namespace std;

int max(int x, int y)
{
	return (x > y) ? x : y;
}

int maxPathSum(int ar1[], int ar2[], int m, int n)
{
	int i = 0, j = 0;

	int result = 0, sum1 = 0, sum2 = 0;

	while(i < m && j < n)
	{
		if(ar1[i] < ar2[j])
			sum1 += ar1[i++];

		else if ( ar1[i] > ar2[j])
			sum2 += ar2[j++];
		else
		{
			result += max(sum1, sum2) + ar1[i];

			sum1 = 0;
			sum2 = 0;

			i++;
			j++;
		}
	}

	while(i < m)
		sum1 += ar1[i++];

	while(j < n)
		sum2 += ar2[j++];

	result += max(sum1, sum2);


	return result;
}


int main()
{
	int ar1[100];
	int m;
	cout<<"Enter the value of m";
	cin>>m;
	cout<<"Enter the elements of array 1"<<" ";
	for(int i = 0;i < m ;i++)
	{
		cin>>ar1[i];
	}

    int ar2[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the elements of array 2"<<" ";
	for(int i = 0;i < n ;i++)
	{
		cin>>ar2[i];
	}

	cout<<"Maximum sum path is "<<maxPathSum(ar1, ar2, m, n);

	return 0;

}