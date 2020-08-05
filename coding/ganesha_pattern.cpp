#include <iostream>

using namespace std;
int main()
{
    int num;
    cin>>num;
    int mid=(num/2)+1;
    for(int i=1;i<=mid;i++)
    {
        if(i==1)
        {
            for(int j=1;j<=num;j++)
        {
            if(j==1 || j>=mid)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }

        }
        else if(i>1 && i<=mid-1)
        {
        for(int j=1;j<=num;j++)
        {
            if(j==1 || j==mid)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        }
        else
        {
        for(int j=1;j<=num;j++)
        {
            cout<<"*";
        }
        }

        cout<<'\n';
    }
     for(int i=mid-1;i>=1;i--)
    {
        if(i==1)
        {
            for(int j=1;j<=num;j++)
        {
            if(j==num || j<=mid)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }

        }
        else if(i>1 && i<=mid-1)
        {
        for(int j=1;j<=num;j++)
        {
            if(j==num || j==mid)
            {
                cout<<"*";
            }
            else
            {
                cout<<" ";
            }
        }
        }

        cout<<'\n';
    }

    return 0;
}
