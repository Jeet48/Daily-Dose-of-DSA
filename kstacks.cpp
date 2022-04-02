#include<bits/stdc++.h>
using namespace std;

class kstacks
{
	int *arr;
	int *top;
	int *next;

	int n,k;
	int free;

public:
	kstacks(int k,int n);

	bool isFull() { return (free==-1); }

	void push(int item,int sn);

	int pop(int sn);

	bool isEmpty(int sn) { return (top[sn]==-1); }
};

kstacks::kstacks(int k1,int n1)
{
	k=k1,n=n1;
	arr = new int[n];
	top = new int [k];
	next = new int [n];

	for(int i=0;i<k;i++)
	   top[i] = -1;

	free = 0;
	for(int i=0;i<n-1;i++)
		next[i]=i+1;
	next[n-1] = -1;
}

void kstacks::push(int item, int sn)
{
	if(isFull())
	{
		cout<<"\n Stack Overflow";
		return;
	}

	int i = free;

	free = next[i];
	next[i] = top[sn];
	top[sn]=i;

	arr[i] = item;
}

int kstacks::pop(int sn)
{
	if(isEmpty(sn))
	{
		cout<<"\n Stack UnderFlow";
		return INT_MAX;
	}

	int i = top[sn];

	top[sn] = next[i];

	next[i]=free;
	free=i;
	return arr[i];
}


int main()
{
	int k = 3,n = 10;
	kstacks ks(k, n);

	ks.push(15, 2);
	ks.push(45, 2);

	ks.push(17, 1);
	ks.push(49, 1);
	ks.push(39, 1);



	ks.push(11, 0);
	ks.push(9, 0);
	ks.push(7, 0);

	cout<<"Popped element from stack 2 is "<<ks.pop(2)<<endl;
	cout<<"Popped element from stack 1 is "<<ks.pop(1)<<endl;
	cout<<"Popped element from stack 0 is "<<ks.pop(0)<<endl;

	return 0;
}