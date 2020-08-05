#include<iostream>
using namespace std;
int noOfIntergers(int n)
{
	if(n==1 or n==2)
	{
		return n+1;
	}
	return noOfIntergers(n-2)+noOfIntergers(n-1);
}
int main() {
	int test,n;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		cin>>n;
		cout<<"#"<<i+1<<" : "<<noOfIntergers(n)<<endl;
	}
	return 0;
}
