#include<iostream>

using namespace std;
int main(){
    int num,i,k=0,arr[50]={0,1,1};
    for(i=3;i<50;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cin>>num;
    for(i=0;i<num;i++)
    {
        for(int j=0;j<i+1;j++)
        {
            cout<<arr[k]<<'\t';
            k++;
        }
        cout<<'\n';
    }

	return 0;
}
