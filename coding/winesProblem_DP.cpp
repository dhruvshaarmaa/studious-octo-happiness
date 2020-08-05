#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int winesMaxProfit(int arr[],int start,int end,int year,vector<vector<int> > &dp)
{
    if(start==end)
    {
        dp[start][end]=arr[start]*year;
        return arr[start]*year;
    }
    if(dp[start][end]!=-1)
    {
        return dp[start][end];
    }
    int first=year*(arr[start])+winesMaxProfit(arr,start+1,end,year+1,dp);
    int last=year*(arr[end])+winesMaxProfit(arr,start,end-1,year+1,dp);
    int ans=max(first,last);
    dp[start][end]=ans;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"********************************************************";
    cout<<endl;
    return ans;
}
int winesPureDp(int arr[],int n)
{
    vector< vector<int> > dp(n,vector<int> (n));
    //base case
    for(int i=0;i<n;i++)
    {
        dp[i][i]=arr[i]*n;
    }
    for(int row=n-2;row>=0;row--)
    {
        int year=n-1;
        for(int col=row+1;col<n;col++)
        {
            //recursive case
            int first=year*arr[row]+dp[row+1][col];
            int last=year*arr[col]+dp[row][col-1];
            int ans=max(first,last);
            dp[row][col]=ans;
            year--;
        }
    }
    return dp[0][n-1];
}
int main() {
    int arr[5]={2,3,5,1,4};
    int n=5;
    vector<vector<int> > dp(n,vector<int> (n,-1));
    cout<<winesPureDp(arr,n);
	return 0;
}
