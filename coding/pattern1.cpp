

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n=5;
    for(int i=0;i<n;i++)
    {   int k=(i+1)%2;
        for(int j=0;j<=i;j++)
        {
            cout<<k<<' ';
            k=!k;
        }
        cout<<endl;
    }

	return 0;
}

