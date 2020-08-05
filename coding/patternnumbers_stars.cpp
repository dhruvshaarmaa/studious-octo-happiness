#include<iostream>

using namespace std;
int main() {
    int num;
    cin>>num;
	for(int i=0;i<num;i++)
    {
        for(int j=0;j<2*num-2;j++)
        {
            if(j<num-i)
            {
                cout<<j+1<<'\t';
            }
            else if(i==0 && j>=num)
            {
                cout<<'\t';
            }
            else if(j>=num+(i-1))
            {
                cout<<'\t';
            }
            else
            {
                cout<<'*'<<'\t';
            }
        }
        cout<<'\n';
    }
	return 0;
}
