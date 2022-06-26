#include <bits/stdc++.h>

using namespace std;

int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    
    
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}


int main() 
{

  vector<int> arr;
  int n;
  cout<<"Enter the value of n";
  cin>>n;

  int a;
  cout<<"Enter the elements in the vector";
  for(int i=0;i<n;i++)
  {
    cin>>a;
    arr.push_back(a);
  }
  cout<<"Maxmimum elements with no adjacent sum is "<<solve(n,arr);

}