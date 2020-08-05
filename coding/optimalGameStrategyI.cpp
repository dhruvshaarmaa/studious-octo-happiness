#include<bits/stdc++.h>
using namespace std;
int optimalStrategy(int arr[],int start,int end,vector<vector<int> > &dp)
{
	if(start>end)
	{
		return 0;
	}
	if(dp[start][end]!=-1)
	{
		return dp[start][end];
	}
	int first=arr[start]+min(optimalStrategy(arr,start+2,end,dp),optimalStrategy(arr,start+1,end-1,dp));
	int last=arr[end]+min(optimalStrategy(arr,start+1,end-1,dp),optimalStrategy(arr,start,end-2,dp));
	int ans=max(first,last);
	dp[start][end]=ans;
	return ans;
}
int main() {
	int n,arr[1000];
	cin>>n;
	vector<vector<int> > dp(n,vector<int> (n,-1));
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<optimalStrategy(arr,0,n-1,dp);
	return 0;
}
