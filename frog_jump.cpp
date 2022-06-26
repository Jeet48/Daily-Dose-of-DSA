#include<bits/stdc++.h>
#include<vector>
using namespace std;

int solve(int ind, vector<int>& height, vector<int>& dp){
    if(ind==0) 
    	return 0;
    if(dp[ind]!=-1) 
    	return dp[ind];
    int jumpTwo = INT_MAX;
    int jumpOne= solve(ind-1, height,dp)+ abs(height[ind]-height[ind-1]);
    if(ind>1)
        jumpTwo = solve(ind-2, height,dp)+ abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(jumpOne, jumpTwo);
}


int main() 
{
  
  int n;
  cout<<"Enter the value of n";
  cin>>n;

  vector<int> height;
  
  int a;
  cout<<"Enter the elements in the vector";
  for(int i = 0;i<n;i++)
  {
  	cin>>a;
  	height.push_back(a);
  }
  vector<int> dp(n,-1);
  cout<<"Minimum energy required for the frog to jump "<<solve(n-1,height,dp);
}