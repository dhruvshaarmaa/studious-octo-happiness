#include <iostream>

using namespace std;
int main()
{
    int num;
    cin>>num;
    for(int i=1;i<=num+1;i++)
    {
        for(int space=1;space<=i-1;space++)
        {
            cout<<"  ";
        }
        for(int dec=num-i+1;dec>=0;dec--)
        {
            cout<<dec<<" ";
        }
        for(int inc=1;inc<=num-i+1;inc++)
        {
            cout<<inc<<" ";
        }
        cout<<'\n';
    }
    for(int i=num;i>=1;i--)
    {
        for(int space=1;space<=i-1;space++)
        {
            cout<<"  ";
        }
        for(int dec=num-i+1;dec>=0;dec--)
        {
            cout<<dec<<" ";
        }
        for(int inc=1;inc<=num-i+1;inc++)
        {
            cout<<inc<<" ";
        }
        cout<<'\n';
    }
    return 0;
}
