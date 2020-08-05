#include<iostream>
using namespace std;
int magicalpark(char arr[4][4],int m,int n,int k,int s)
{
    for(int row=0;row<m;row++)
    {

        for(int col=0;;col++)
        {
            if(s<k)
            {
                break;
            }
            if(arr[row][col]=='.')
            {
                s=s-2;
            }
            else if(arr[row][col]=='*')
            {
                s=s+5;
            }
            else if(arr[row][col]=='#')
            {
                break;
            }
            if(col==n-1)
            {
                break;
            }
            else
            {
                s=s-1;
            }
        }
    }
    if(s>k)
    {
        cout<<"Yes"<<endl;
        return s;
    }
    else
    {
        cout<<"No"<<endl;
        return s;
    }
}
int main()
{
    char arr[4][4]={'.','.','*','.','.','#','.','.','*','*','.','.','.','#','*','*'};
    int answer=0,m=4,n=4,k=5,s=20;
    //cin>>m>>n>>k>>s;
    /*for(int row=0;row<m;row++)
    {
        for(int col=0;col<n;col++)
        {
            cin>>arr[row][col];
        }
    }*/
    answer=magicalpark(arr,m,n,k,s);
    cout<<answer;
    return 0;
}
