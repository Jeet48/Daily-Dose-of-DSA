#include<bits/stdc++.h>

using namespace std;

int findDuplicate(vector < int > &nums) {
	int slow = nums[0];
	int fast = nums[0];

	do
	{
      slow = nums[slow];
      fast = nums[nums[fast]];
	} while(slow != fast);

	fast = nums[0];

	while(slow!=fast)
	{
		slow = nums[slow];
		fast = nums[fast];
	}

	return slow;
}

int main() {
	vector <int> arr;
	int n,input;
	cout<<"Enter the value of n";
	cin>>n;
	cout<<"Enter the values in an array\n";
	for(int i = 0;i<n;i++)
	{
		cin>>input;
		arr.push_back(input);
	}
	cout<<"The duplicate elements in an array is " << findDuplicate(arr)<<endl;

	return 0;
}