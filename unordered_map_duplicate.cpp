#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int *a,int size)
{
	vector<int> output;
	unordered_map<int, bool> seen;
	for(int i = 0; i < size; i++)
	{
		if(seen.count(a[i]) > 0) {
			continue;
		}
		seen[a[i]] = true;
		output.push_back(a[i]);
	}
	return output;
}

int main() 
{
	int a[100];
	int n;
	cout<<"Enter the values of n";
	cin>>n;
	cout<<"Enter the values of the array"<<endl;
	for(int i = 0;i < n;i++)
	{
		cin>>a[i];
	}
	vector<int> output = removeDuplicates(a, n);
	cout<<"Array after removing duplicate is "<<endl;
	for(int i = 0;i<output.size();i++)
	{
		cout<<output[i]<<endl;
	}

	return 0;
}