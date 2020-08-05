#include<iostream>
using namespace std;
string arr[10]={"","abc","def","ghi","jkl","mno","pqrs","tuv","wx","yz"};
void keypad(string str, string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<" ";
		return ;
	}

	char ch=str[0];
	string ros=str.substr(1);
	int index=ch-'0';
	string key=arr[index];
	for(int i=0;i<key.length();i++)
	{
		keypad(ros,ans+key[i]);
	}
}
int main() {
	string str;
	cin>>str;
	keypad(str,"");
	int count=1;
	for(int i=0;i<str.length();i++)
	{
	    int index=str[i]-'0';
		count=(arr[index].length())*count;
	}
	cout<<endl<<count;

	return 0;
}
