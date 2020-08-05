#include<iostream>
#include<string>
using namespace std;
string invertDigitMinimumNumber(string s)
{

	int n=s.length();
	string newnum="";
	if(s[0]=='9')
        {
            newnum+='9';

        }
        else
        {
        int digit=s[0]-48;
		int invertDigit=9-digit;
		int ch=min(digit,invertDigit);
		newnum=newnum+to_string(ch);
        }
	for(int i=1;i<n;i++)
	{

	    int digit=s[i]-48;
		int invertDigit=9-digit;
		int ch=min(digit,invertDigit);
		newnum=newnum+to_string(ch);
	//	cout<<"HELLo"<<endl;

	}
	return newnum;
}

int main() {
    string s;
	cin>>s;
	cout<<invertDigitMinimumNumber(s);
	return 0;
}
