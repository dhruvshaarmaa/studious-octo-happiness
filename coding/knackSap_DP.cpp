#include<iostream>
#include<vector>
using namespace std;
int knapsack(int size[],int value[],int w,int n,vector<vector<int> > &dp)
{
	if(n-1==0 or w==0)
	{
		dp[n-1][currCapacity]=0;
		return 0;
	}
	if(dp[n-1][currCapacity]!=-1)
    {
        return dp[si][currCapacity];
    }
	int val=0;
	if(currCapacity+size[si]<=maxCapacity)
	{
		int include=value[si]+knapsack(size,value,currCapacity+size[si],maxCapacity,n,si+1,dp);
		val=include;
	}
	int skip=knapsack(size,value,currCapacity,maxCapacity,n,si+1,dp);
	val=max(val,skip);
	dp[si][currCapacity]=val;
	return val;
}
int main() {
	int n,s,size[1000],value[1000];
	cin>>n>>s;
	vector<vector<int> > dp(n+1,vector<int> (s+1,-1));
	for(int i=0;i<n;i++)
	{
		cin>>size[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>value[i];
	}
	cout<<knapsack(size,value,s,n,dp);
	return 0;
}
