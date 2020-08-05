#include<iostream>
using namespace std;
int main() {
	int a,b,i=2;
	cin>>a>>b;
	bool check=true;
	while(check)
    {
        if(i%a==0 and i%b==0)
        {
            check=false;
        }
        else
        {
            i++;
        }
    }
    cout<<i;

	return 0;
}
