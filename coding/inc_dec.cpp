#include<iostream>
using namespace std;
int main() {
	int temp,a,b,num;
	bool inc=true;
	cin>>num;
	cin>>a;
	for(int i=1;i<=num-1;i++)
	{
        cin>>b;
		if(a>b)
		{
			inc=false;
		}
	}
	if(inc)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
}
