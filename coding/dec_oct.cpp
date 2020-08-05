#include<iostream>
#include<cmath>

using namespace std;
int main(){
    int num,oct=0,i=0;
    cin>>num;
    while(num>0)
    {
        oct=oct+(num%8)*pow(10,i);
        num/=8;
        i++;
    }
    cout<<oct;
	return 0;
}
