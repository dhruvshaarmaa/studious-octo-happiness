#include<iostream>

using namespace std;
int main(){
    int n1,n2,num=0,count1=0,i=1;
    cin>>n1>>n2;
    while(count1<n1)
    {
         num=3*(i)+2;
         if(num%n2!=0)
         {
             cout<<num<<'\n';
             count1++;
         }
         i++;
    }
	return 0;
}
