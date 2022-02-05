#include<iostream>
using namespace std;

int main()
{
	int *xptr;
	int x= 10;

	int **xxptr = &xptr;
	xptr = &x;

	cout<<&x<<endl;
	cout<<xptr<<endl;
	cout<<*(&x);
	cout<<*(xptr);
	cout<<*(&xptr);
	cout<<*xptr;
	cout<<xxptr<<endl;

	return 0;


}