#include<iostream>
using namespace std;
int main() {
	int a,b;
	cin>>a>>b;
	int greater=a;
	if(b>a)
	{greater=b;}
	for(int i=greater;i>=1;i--)
	{
		if(a%i==0 && b%i==0)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
