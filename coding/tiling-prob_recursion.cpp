#include<iostream>
using namespace std;
int tilingProblem(int row,int col,int n,int m)
{
	if(row==m or col==n)
	{
		return 1;
	}
	int cnt=0;
	if(n-row>=m)
    {
        int vertical=tilingProblem(row,col+1,n,m);
        cnt+=vertical;
    }
    if(m-col>=m)
    {
        int horizontal=tilingProblem(row+1,col,n,m);
        cnt+=horizontal;
    }
	return cnt;
}
int main() {
	int test,n,m;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		cin>>n>>m;
		cout<<tilingProblem(0,0,n,m)<<endl;
	}
	return 0;
}
