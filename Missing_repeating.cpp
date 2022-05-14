#include <bits/stdc++.h>
using namespace std;
 

void getTwoElements(int arr[], int n,int* x, int* y)
{
    
    int xor1;
 
    
    int set_bit_no;
 
    int i;
    *x = 0;
    *y = 0;
 
    xor1 = arr[0];
 
    
    for (i = 1; i < n; i++)
        xor1 = xor1 ^ arr[i];
 
    
    for (i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
 
    
    set_bit_no = xor1 & ~(xor1 - 1);
 
    
    for (i = 0; i < n; i++) {
        if (arr[i] & set_bit_no)
            
            *x = *x ^ arr[i];
 
        else
            
            *y = *y ^ arr[i];
    }
    for (i = 1; i <= n; i++) {
        if (i & set_bit_no)
            
            *x = *x ^ i;
 
        else
            
            *y = *y ^ i;
    }
 
    
}
 
/* Driver code */
int main()
{
    int arr[100];
    int n;
    cout<<"Enter the value of n ";
    cin>>n;
    cout<<"Enter the value in the array\n";
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int* x = (int*)malloc(sizeof(int));
    int* y = (int*)malloc(sizeof(int));
    
    getTwoElements(arr, n, x, y);
    cout << " The missing element is " << *x << " and the repeating"<< " number is " << *y;
    getchar();

    return 0;
}
 