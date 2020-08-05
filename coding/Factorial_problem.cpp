#include<iostream>
#include<math.h>
using namespace std;
int factorial(int n)
{
    int fact=1;
    for(int i=1;i<=n;i++)
    {
        fact=fact*i;
    }
    return fact;
}
int main() {
	int test,n,k,x;
	cin>>test;
	int arr1[test]={0},arr2[test]={0},arr3[test]={0};
	for(int i=1;i<=test;i++)
    {
        cin>>n>>k;
        arr1[i-1]=n;
        arr2[i-1]=k;
    }
    for(int j=1;j<=test;j++)
    {

    int check=1;
    x=0;
    while(check!=0)
    {
        int c=factorial(arr1[j-1]);
        int m=pow(arr2[j-1],x);
       // cout<<c<<m<<endl;
        if(c%m!=0)
        {
            check=0;
           // cout<<check;
        }
        x++;
    }
    x=x-2;
    arr3[j-1]=x;

    }
    for(int i=1;i<=test;i++)
    {
        cout<<arr3[i-1]<<endl;
    }

    return 0;
}
