#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int n)
{
	int max_sum = 0,curr_sum = 0,start = 0,end = 0,s = 0;

	for(int i = 0;i < n;i++)
	{
		curr_sum = curr_sum + a[i];

		if(curr_sum > max_sum)
		{
			max_sum = curr_sum;
			start = s;
			end = i;
		}
		if(curr_sum < 0)
		{
			curr_sum = 0;
			s = i + 1;
		}
	}
	cout<<"Maximum contigous sum is "<<max_sum<<endl;

	cout<<"Starting index is " <<start<<endl<<"Ending Index is is "<<end<<endl;

}


int main()
{
	int a[100];
	int n;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Insert values in the array";
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	int max_sum = maxSubArraySum(a,n);

	return 0;
}