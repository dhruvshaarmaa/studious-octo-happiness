#include<iostream>
using namespace std;
void mappedStrings(string str,string ans)
{
	if(str.length()==0)
	{
		cout<<ans<<endl;
		return;
	}

	char ch=str[0];
	string ros=str.substr(1);
	char letter=ch-'0'+64;
	mappedStrings(ros,ans+letter);
	if(str.length()>=2)
	{
		string ch=str.substr(0,2);
		string ros=str.substr(2);
		int digit=0,p=1;
		for(int i=1;i>=0;i--)
		{
			digit+=(ch[i]-'0')*p;
			p=p*10;
		}
		char letter=64+digit;
		if(64+digit<=26)
        {
            mappedStrings(ros,ans+letter);

        }
	}

}
int main() {
	string str;
	cin>>str;
	mappedStrings(str,"");
	return 0;
}
