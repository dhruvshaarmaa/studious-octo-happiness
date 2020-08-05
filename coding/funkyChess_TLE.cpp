#include <iostream>
#include<climits>
using namespace std;
bool helper(int chess[10][10],int n,int row,int col)
{
    if(row>=n or col>=n or row<0 or col<0)
    {
        return false;
    }
    if(chess[row][col]==1 or chess[row][col]==0)
    {
        return true;
    }
    return false;
}
int ans=INT_MAX;
void funkyChess(int chess[10][10],int n,int row,int col,int count)
{
    if(helper(chess,n,row-2,col-1))
    {
        if(chess[row-2][col-1])
        {
            count++;
        }
        chess[row-2][col-1]=-1;
        funkyChess(chess,n,row-2,col-1,count);
        chess[row-2][col-1]=1;
    }
    if(helper(chess,n,row-2,col+1))
    {
        if(chess[row-2][col+1])
        {
            count++;
        }
        chess[row-2][col+1]=-1;
        funkyChess(chess,n,row-2,col+1,count);
        chess[row-2][col+1]=1;
    }
    if(helper(chess,n,row+2,col-1))
    {
        if(chess[row+2][col-1])
        {
            count++;
        }
        chess[row+2][col-1]=-1;
        funkyChess(chess,n,row+2,col-1,count);
        chess[row+2][col-1]=1;
    }
    if(helper(chess,n,row+2,col+1))
    {
        if(chess[row+2][col+1])
        {
            count++;
        }
        chess[row+2][col+1]=-1;
        funkyChess(chess,n,row+2,col+1,count);
        chess[row+2][col+1]=1;
    }
    if(helper(chess,n,row+1,col+2))
    {
        if(chess[row+1][col+2])
        {
            count++;
        }
        chess[row+1][col+2]=-1;
        funkyChess(chess,n,row+1,col+2,count);
        chess[row+1][col+2]=1;
    }
    if(helper(chess,n,row+1,col-2))
    {
        if(chess[row+1][col-2])
        {
            count++;
        }
        chess[row+1][col-2]=-1;
        funkyChess(chess,n,row+1,col-2,count);
        chess[row+1][col-2]=1;
    }
    if(helper(chess,n,row-1,col+2))
    {
        if(chess[row-1][col+2])
        {
            count++;
        }
        chess[row-1][col+2]=-1;
        funkyChess(chess,n,row-1,col+2,count);
        chess[row-1][col+2]=1;
    }
    if(helper(chess,n,row-1,col-2))
    {
        if(chess[row-1][col-2])
        {
            count++;
        }
        chess[row-1][col-2]=-1;
        funkyChess(chess,n,row-1,col-2,count);
        chess[row-1][col-2]=1;
    }
    int c=0;
    for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(chess[i][j]==1)
			{
				c++;
			}
		}
	}
	ans=min(c,ans);
    return ;
}
int main()
{
    int n,arr[10][10]={0},count=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	funkyChess(arr,n,0,0,count);
	cout<<ans;
    return 0;
}
