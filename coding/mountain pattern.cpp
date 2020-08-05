#include<iostream>

using namespace std;
int main() {
    int num;
    cin>>num;
    int c=2*num-1;
	for(int i=0;i<num;i++)
    {
        for(int j=0;j<2*num-1;j++)
        {
            if(j<i+1)
            {
                cout<<j+1<<'\t';
            }
            else if(j>=c-(i+1))
            {
                cout<<c-j<<'\t';
            }
            else
            {
                cout<<'\t';
            }
        }
        cout<<'\n';
    }
	return 0;
}
