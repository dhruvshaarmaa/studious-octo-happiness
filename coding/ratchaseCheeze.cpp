#include<iostream>
using namespace std;
int result=0,sol[10][10]={0};
void ratMaze(char path[10][10],int sr,int sc,int er,int ec)
{
	if(sr==er and sc==ec)
	{
		sol[er][ec]=1;
		//result=1;
		for(int i=0;i<=er;i++)
		{
			for(int j=0;j<=ec;j++)
			{
				cout<<sol[i][j]<<" ";
			}
			cout<<endl;
		}
		return ;
	}
	if(sr<0 or sc<0 or sr>er or sc>ec)
	{
		return;
	}
	if(path[sr][sc]=='X' or sol[sr][sc]==1)
	{
		return;
	}
	sol[sr][sc]=1;
	//up
	ratMaze(path,sr-1,sc,er,ec);
	//down
	ratMaze(path,sr+1,sc,er,ec);
	//right
	ratMaze(path,sr,sc+1,er,ec);
	//left
	ratMaze(path,sr,sc-1,er,ec);
	sol[sr][sc]=0;
}
int main() {
	int n,m;
	cin>>n>>m;
	char path[10][10];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>path[i][j];
		}
	}
	ratMaze(path,0,0,n-1,m-1);
	return 0;
}
