#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

bool arePermutation(string str1, string str2)
{
	int count[NO_OF_CHARS] = {0};
	int i;

	for(i = 0;str1[i] && str2[i]; i++)
	{
		count[str1[i]]++;
		count[str2[i]]--;
	}

	if(str1[i] || str2[i])
		return false;

	for(i = 0; i < NO_OF_CHARS; i++)
		if(count[i])
			return false;
		return true;
}

int main()
{
	string str1,str2;
	cout<<"Enter string 1 ";
	cin>>str1;
	cout<<"Enter string 2 ";
	cin>>str2;

	if(arePermutation(str1, str2))
		cout<<"Yes";
	else
		cout<<"No";

	return 0;
}