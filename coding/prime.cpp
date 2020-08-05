#include<iostream>

using namespace std;
int main(){
    long int num,i=2,count1=1;
    cin>>num;
    while(i<num)
    {
        if(num%i==0)
        {
            count1=0;
        }
        i++;
    }
    if(count1==1)
    {
        cout<<"Prime";
    }
    else
    {
        cout<<"Not Prime";
    }
	return 0;
}
