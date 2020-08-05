#include <iostream>

using namespace std;

int main()
{
    int num;

    cin>>num; //number is odd
    int mid=(num/2)+1;
    for(int i=1; i<=mid; i++)
    {
        if(i==1)
        {
            for(int j=1; j<=num; j++)
            {
                cout<<"*"<<"\t";
            }
        }
        else
        {
            for(int j=mid-i+1; j>=1; j--)
            {
                cout<<"*\t";
            }
            for(int j=1; j<=2*(i-1)-1; j++)
            {
                cout<<"\t";
            }
            for(int j=mid-i+1; j>=1; j--)
            {
                cout<<"*\t";
            }

        }
        cout<<'\n';
    }
    for(int i=mid-1; i>=1; i--)
    {
        if(i==1)
        {
            for(int j=1; j<=num; j++)
            {
                cout<<"*"<<"\t";
            }
        }
        else
        {
            for(int j=mid-i+1; j>=1; j--)
            {
                cout<<"*\t";
            }
            for(int j=1; j<=2*(i-1)-1; j++)
            {
                cout<<"\t";
            }
            for(int j=mid-i+1; j>=1; j--)
            {
                cout<<"*\t";
            }

        }
        cout<<'\n';
    }
    return 0;
}
