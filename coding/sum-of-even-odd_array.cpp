#include<iostream>
using namespace std;
int main() {
	int num,arr[15]={0},i=0;
    cin>>num;
    int temp=num;
    while(num>0)
    {
        arr[i]=num%10;
        num=num/10;
        i++;
    }
	int sumeven=0,sumodd=0;
	for(int j=0;j<i+1;j++)
	{
		if((j+1)%2==0)
		{
			sumeven+=arr[j];
		}
		else
		{
			sumodd+=arr[j];
		}
	}
	cout<<sumodd<<endl<<sumeven;
	return 0;
}
