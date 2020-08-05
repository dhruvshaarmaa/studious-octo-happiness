#include<iostream>
#include<cmath>

using namespace std;
int main(){
    char ch;
    int num1,num2,i=1,countn=0,arr[]={0},flag=0;
    while(i==1)
    {
        cin>>ch;


            if(ch=='+'){
                cin>>num1>>num2;
                arr[countn]=num1+num2;
            }

            else if(ch=='-'){
                cin>>num1>>num2;
                arr[countn]=num1-num2;
            }

            else if(ch=='*'){
                cin>>num1>>num2;
                arr[countn]=num1*num2;
            }

            else if(ch=='%'){
                cin>>num1>>num2;
                arr[countn]=num1%num2;

            }
            else if(ch=='/'){
                cin>>num1>>num2;
                arr[countn]=num1/num2;

            }
            else if(ch=='X'||ch=='x'){
                i=0;
                break;
            }
            else{
                flag=-99;
                arr[countn]=flag;
            }
            countn++;


    }
    for(int i=0;i<countn;i++)
    {
        if(arr[i]==-99)
        {
             cout<<"Invalid operation. Try again."<<endl;
        }
        else
        {
             cout<<arr[i]<<endl;
        }
    }
	return 0;
}
