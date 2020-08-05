#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int compare(int x,int y)
{
    string x1=to_string(x);
    string y1=to_string(y);
    string s=x1.append(y1);
    string s1=y1.append(x1);
    return s.compare(s1) > 0 ? 1 : 0 ;
}
void formBiggestNumber(int arr[],int n)
{
    sort(arr,arr+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}
int main() {
	int arr[100],n,test;
	cin>>test;
	for(int i=0;i<test;i++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        formBiggestNumber(arr,n);

    }
	return 0;
}
