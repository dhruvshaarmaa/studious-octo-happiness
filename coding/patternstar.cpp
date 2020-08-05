#include<iostream>

using namespace std;
int main() {
    int num;
    cin>>num;
	for(int i=0;i<num;i++)
    {
        for(int j=0;j<num;j++)
        {
            if(j<=i)
            {
                cout<<j+1;
            }
            else
            {
                cout<<'*';
            }
        }
        cout<<'\n';
    }
	return 0;
}
