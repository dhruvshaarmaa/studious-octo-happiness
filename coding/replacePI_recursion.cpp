#include<iostream>
using namespace std;
string replacePi(string str)
{
    if(str.length()==0)
    {
        return "";
    }

    char ch=str[0];
    string ros=str.substr(1);
    string rr=replacePi(ros);
    if(ch=='p' and rr[0]=='i')
    {
        return "3.14"+rr.substr(1);
    }
    return ch+rr;
}

int main() {
	int n;
	string str;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>str;
		cout<<replacePi(str)<<endl;
	}
	return 0;
}
