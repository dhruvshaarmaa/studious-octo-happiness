#include <iostream>

using namespace std;
int main()
{
    int num;
    cin>>num;
    for(int i=1;i<=num;i++)
    {
        int k=1;
        for(int j=1;j<=num-i;j++)
        {
           cout<<"\t";

        }
        int val=i;
        for(int j=1;j<=i;j++)
        {
            cout<<val<<"\t";
            val++;
        }
        val=val-2;
        for(int j=1;j<=i-1;j++)
        {
            cout<<val<<"\t";
            val--;
        }
        cout<<'\n';
    }
    return 0;
}
