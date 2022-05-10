// #include <bits/stdc++.h>
// using namespace std;

// bool checkStackPermutations(int ip[], int op[],int n)
// {
// 	stack<int> s;

// 	int j = 0;

// 	for(int i= 0;i<n;i++)
// 	{
// 		s.push(ip[i]);

// 		while(!s.empty() && s.top==op[j])
// 		{
// 			s.pop();

// 			j++;
// 		}
// 	}

// 	if(s.empty())
// 	{
// 		return true;
// 	}
// 	return false;
// }

// int main()
// {

//     int n;
//     cout<<"Enter the value of n";
//     cin>>n;


// 	int input[100];

// 	for(int a=0;a<=n;a++)
// 	{
// 		cout<<"Enter the values of input array";
// 		cin>>input[a];
// 	}

// 	int output[100];

// 	for(int b=0;b<=n;b++)
// 	{
// 		cout<<"Enter the values of input array";
// 		cin>>output[b];
// 	}

	

// 	if(checkStackPermutations(input, output, n))
// 		cout<<"Yes";
// 	else
// 		cout<<"Not possible";


// 	return 0;
// }





// Given two arrays, check if one array is
// stack permutation of other.
#include<bits/stdc++.h>
using namespace std;

// function to check if input array is
// permutable to output array
bool checkStackPermutation(int ip[], int op[], int n)
{
	// we will be pushing elements from input array to stack uptill top of our stack
	// matches with first element of output array
	stack<int>s;
	
	// will maintain a variable j to iterate on output array
	int j=0;

	// will iterate one by one in input array
	for(int i=0;i<n;i++)
	{
		// pushed an element from input array to stack
		s.push(ip[i]);
		// if our stack isn't empty and top matches with output array
		// then we will keep popping out from stack uptill top matches with
		// output array
		while(!s.empty() and s.top()==op[j])
		{
		s.pop();
		// increasing j so next time we can compare next element in output array
		j++;
		}
	}
	
	// if output array was a correct permutation of input array then
	// by now our stack should be empty
	if(s.empty())
	{
		return true;
	}
	return false;
	
}

// Driver program to test above function
int main()
{
	// 


    int n;
    cout<<"Enter the value of n";
    cin>>n;


	int input[n];
    
    cout<<"Enter the values of input array";
	for(int a=0;a<n;a++)
	{
		
		cin>>input[a];
	}

	int output[n];

    cout<<"Enter the values of output array";
	for(int b=0;b<n;b++)
	{
		
		cin>>output[b];
	}

  
	if (checkStackPermutation(input, output, n))
		cout << "Yes";
	else
		cout << "Not Possible";
	return 0;
}
