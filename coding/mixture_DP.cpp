#include<iostream>
#include<vector>
#include<climits>
#include<string.h>
using namespace std;
long long dp[10][10];
long long sum(int arr[],int s,int e)
{
	long long ans=0;
	for(int i=s;i<=e;i++)
	{
		ans+=arr[i];
		ans%=100;
	}
	return ans;
}
long long mixtures(int arr[],int i,int j)
{
	if(i>=j)
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	long long smoke=INT_MAX;
	for(int k=i;k<=j;k++)
	{
		smoke=min(smoke,mixtures(arr,i,k)+mixtures(arr,k+1,j)+sum(arr,i,k)*sum(arr,k+1,j));
	}
	dp[i][j]=smoke;
	return smoke;
}
int main() {
	int n,arr[10];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<mixtures(arr,0,n-1)<<endl;
	return 0;
}
