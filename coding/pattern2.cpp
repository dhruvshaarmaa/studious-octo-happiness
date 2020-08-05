#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n=5,k=1,colsize=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=colsize;j++)
        {
            cout<<k<<' ';
            k++;
            if(k>9)
            {
                k=1;
            }

        }
        cout<<endl;
        colsize=colsize*2;
    }

	return 0;
}
