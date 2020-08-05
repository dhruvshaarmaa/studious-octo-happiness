#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int pureDp(int size[],int value[],int capacityLimit,int n)
{
	vector<vector<int> > dp(n+1,vector<int> (capacityLimit+1));
	//base case
	for(int i=0;i<=capacityLimit;i++)
	{
		dp[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		dp[i][0]=0;
	}
	for(int row=1;row<=n;row++)
	{
		for(int col=1;col<=capacityLimit;col++)
		{
			int include=INT_MIN,exclude=INT_MIN;
			if(size[row-1]<=col)
			{
				include=dp[row-1][col-size[row-1]]+value[row-1];
			}
			exclude=dp[row-1][col];
			dp[row][col]=max(include,exclude);
		}
	}
	return dp[n][capacityLimit];
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
	cout<<pureDp(size,value,s,n);
	return 0;
}
