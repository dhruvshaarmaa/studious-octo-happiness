#include<iostream>
#include<climits>
#include<vector>
using namespace std;
//memoization
long long dp[10][10]={0};
long long matrixChainMul(int arr[],int i,int j)
{
    if(i==j)
    {
        dp[i][j]=0;
        return 0;
    }
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }
    long long minCost=INT_MAX;
    for(int k=i;k<j;k++)
    {
        minCost=min(minCost,matrixChainMul(arr,i,k)+matrixChainMul(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
    }
    dp[i][j]=minCost;
    return minCost;
}
long long matrixChainMul_PureDp(int arr[],int n)
{
    int l=n-1;
    for(int i=1;i<l;i++)
    {
        dp[i][i]=0;
    }
    for(int L=2;L<=n-1;L++)
    {
        //for each length of matrix
        for(int i=1;i<=n-L;i++)
        {
            //sub problem recursive case
            int j=i+L-1;
            dp[i][j]=INT_MAX;
            for(int k=i;k<j;k++)
            {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
            }
        }
    }
    return dp[1][n-1];
}
int main() {
    int arr[5]={1,2,3,4};
    int n=4;
    //vector<vector<int> > dp(n,vector<int> (n,-1));
    cout<<matrixChainMul_PureDp(arr,n)<<endl;
	return 0;
}
