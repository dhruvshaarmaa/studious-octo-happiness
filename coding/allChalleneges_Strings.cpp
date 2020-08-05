#include<iostream>
using namespace std;

void stringCompression(string str)
{
	int n=str.length(),count=1;

    int prev=0;
	for(int i=1;i<n;i++)
	{
		if(str[prev]!=str[i])
		{
			cout<<str[prev]<<count;
			prev=i;
			count=1;
		}
		else
		{
			count++;
		}
	}
	cout<<str[prev]<<count;

}

int equalsubstringLength(string s,int k)
{
	int allowed=0,n=s.length();
	int left=0,right=0,count=0,maxCounta=0;
	while(right<n)
	{
		if(s[right]=='b')
		{
			allowed++;
		}
		while(allowed>k)
		{
			if(s[left]=='b')
			{
				allowed--;
			}
			left++;
		}
		count=right-left+1;
		maxCounta=max(maxCounta,count);
		right++;
	}
	allowed=0;n=s.length();
	left=0;right=0;count=0;int maxCountb=0;
	while(right<n)
	{
		if(s[right]=='a')
		{
			allowed++;
		}
		while(allowed>k)
		{
			if(s[left]=='a')
			{
				allowed--;
			}
			left++;
		}
		count=right-left+1;
		maxCountb=max(maxCountb,count);
		right++;
	}
	int ans=max(maxCounta,maxCountb);
	return ans;

}

void magicalpark2(char arr[1000][1000],int m,int n,int k,int s)
{
    for(int row=0;row<m;row++)
    {

        for(int col=0;col<n;col++)
        {
			if(s<k)
			{
				break;
			}
            if(arr[row][col]=='.')
            {
                s=s-2;
            }
            else if(arr[row][col]=='*')
            {
                s=s+5;
            }
            else
            {
                break;
            }
            if(col!=n-1)
            {
                s--;
            }
        }
    }
    if(s>=k)
    {
        cout<<"Yes"<<endl;
        cout<<s;
    }
    else
    {
        cout<<"No"<<endl;
    }
}

void readStringInCamel(string s)
{
	int n=s.length();
	int left=0,right=1;
	while(right<n+1)
	{
		if(s[right]<'a' || right==n)
		{
			while(left!=right)
			{
				cout<<s[left];
				left++;
			}
			cout<<endl;
		}
		right++;
	}
}

void characterType()
{
    char ch;
	cin>>ch;
	if(int(ch)>=65 and int(ch)<=90)
	{
		cout<<'U';
	}
	else
	{
        if(int(ch)>=97 and int(ch)<=122)
		{
			cout<<'L';
		}
		else
		{
            cout<<'I';
		}
	}
}
void lowerUpper()
{
    char ch;
	cin>>ch;
	if(int(ch)>=65 and int(ch)<=90)
	{
		cout<<"UPPERCASE";
	}
	else
	{
        if(int(ch)>=97 and int(ch)<=122)
		{
			cout<<"lowercase";
		}
		else
		{
            cout<<"Invalid";
		}
	}
}

void asciiDifference(string str)
{
    string c;
    int n=str.length();
    for(int i=0;i<n-1;i++)
    {
        int diff=str[i+1]-str[i];
        cout<<str[i]<<diff;
    }
    cout<<str[n-1];
}
bool palindrome(string s)
{
	int n=s.length();
	int left=0,right=n-1;
	while(left<right)
	{
		if(s[left]!=s[right])
		{
			return false;
		}
		left++;
		right--;
	}
	return true;
}
int main() {
	string str="acb";
	asciiDifference(str);
	return 0;
}
