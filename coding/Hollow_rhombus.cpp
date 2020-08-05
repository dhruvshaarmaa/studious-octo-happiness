#include <iostream>

using namespace std;
int main()
{
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        for(int j=num-i;j>=1;j--)
        {
            cout<<" ";
        }
        if(i==1 || i==num)
        {
            for(int j=1;j<=num;j++)
            {
                cout<<"*";
            }
        }
        else
        {
            cout<<"*";
            for(int j=1;j<=num-2;j++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
     cout<<'\n';
    }

    return 0;
}
