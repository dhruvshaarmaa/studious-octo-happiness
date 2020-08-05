#include<iostream>
#include<cmath>

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

//O(N*sqrt(N))
bool prime(int num)
{
    if(num==1)
    {
        return false;
    }
    if(num==2)
    {
        return true;
    }


        for(int i=3;i*i<num;i++)
        {
            if(num%i==0)
            {
                return false;
            }
        }
        return true;

}

int main() {
   int a[100],b[100],test,k[100]={0},p[10000]={0};
   cin>>test;
   for(int j=0;j<test;j++)
   {

       cin>>a[j]>>b[j];
       int low;
       if(a[j]%2==0)
       {
           low=a[j]+1;
       }
       else if(a[j]<0)
       {
           low=1;
       }
       else
       {
           low=a[j];
       }

       primes(p,b[j]);

    for(int i=low;i<=b[j];i++)
    {
       if(p[i]==1)
       {
            k[j]++;
       }


    }
    }
    for(int i=0;i<test;i++)
    {
        cout<<k[i]<<endl;
    }


	return 0;
}
