#include<iostream>
#include<cmath>
using namespace std;
bool helper(int arr[9][9],int n,int row,int col,int val)
{
	//col and row
	for(int i=0;i<n;i++)
	{
		if(arr[i][col]==val or arr[row][i]==val)
		{
			return false;
		}
	}
	//subgrid
	int rn=sqrt(n);
	int sx=(row/rn)*rn;
	int sy=(col/rn)*rn;
	for(int i=sx;i<sx+rn;i++)
	{
		for(int j=sy;j<sy+rn;j++)
        {
            if(arr[i][j]==val)
            {
                return false;
            }
        }
	}
	return true;
}
bool sudokuSolver(int arr[9][9],int row,int col,int n)
{
	//base case
	if(row==n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	if(col==n)
	{
		bool rest=sudokuSolver(arr,row+1,0,n);
        return rest;
	}
	if(arr[row][col]!=0)
    {
        bool rest=sudokuSolver(arr,row,col+1,n);
        return rest;
    }
    for(int i=1;i<=9;i++)
    {
        if(helper(arr,n,row,col,i))
        {
            arr[row][col]=i;
            bool rest=sudokuSolver(arr,row,col+1,n);
            if(rest==true)
            {
                return true;
            }

        }
    }
    arr[row][col]=0;
    return false;
}
int main() {
	int n,arr[9][9];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>arr[i][j];
		}
	}
	sudokuSolver(arr,0,0,n);
	return 0;
}
