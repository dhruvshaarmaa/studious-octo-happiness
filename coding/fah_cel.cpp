#include<iostream>
#include<cmath>
using namespace std;
int temp(float n)
{
    float cel;
    cel=(n-(32))*(5.0/9.0);
    return cel;
}
int main()
{   int mini,maxi,step;
    cin>>mini>>maxi>>step;
    while(mini<=maxi)
    {
        cout<<mini<<'\t'<<temp(mini)<<'\n';
        mini+=step;
    }
	return 0;
}
