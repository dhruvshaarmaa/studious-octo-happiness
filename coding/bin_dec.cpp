#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int num,i,j,bin,arr[10],num1=0;
	cin>>num1;
	for(j=0;j<num1;j++)
	{
		bin=0;i=0;
        cin>>num;
	    while(num>0)
	    {
            bin+=(num%10)*pow(2,i);
            num=num/10;
		    i++;
	    }
		arr[j]=bin;

	}
	for(int j=0;j<i;j++)
	{
		cout<<arr[j];
	}
	return 0;
}
