#include<iostream>
using namespace std;
void primes(int* p,int n)
{
    for(int i=3;i<=n;i=i+2)
    {
        p[i]=1;
    }
    for(int i=3;i<=n;i=i+2)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=n;j=j+i)
            {
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;

}
int main()
 {
    int k=50;
    int num,p[100]={0},c=0,value=0;
	cin>>num;
	primes(p,k);

	for(int i=2;c!=num;i++)
	{
		if(p[i]==1)
		{
		    c++;
		    value=i;
        }
	}

    cout<<value;
	return 0;
}
