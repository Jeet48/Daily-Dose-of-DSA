#include <bits/stdc++.h>
using namespace std;
 
// to find maximum length of sub array having sum 0
int maxSubArrayLen(vector<int>arr){
         
    map<int,int>hm;
    hm[0] = 0;
    int length = -1;
    int cumSum = 0;
 
    for (int i = 0; i < arr.size(); i++) {
        cumSum = cumSum + arr[i];
 
        if (hm.find(cumSum) != hm.end()) {
            length = max(length,
                  i + 1 - hm[cumSum]);
        }
        else {
            hm[cumSum] = i + 1;
        }
    }
    return length;
}
 
 
// Driver Code
int main(){
 

 int n,a;
 cout<<"Enter the value of n";
 cin>>n;
vector<int>arr ;

cout<<"Enter the elements in an array\n";
for(int i=0;i<n;i++)
{
    cin>>a;
    arr.push_back(a);
}
cout<<"Maximum sub Array of sum 0 is "<<maxSubArrayLen(arr)<<endl;
 
}
 
