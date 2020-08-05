#include<iostream>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<string> v;
bool shouldSwap(string str,int start,int curr)
{
	for(int i=start;i<curr;i++)
	{
		if(str[i]==str[curr])
		{
			return false;
		}
	}
	return true;
}
void permutations(string str,int start,int end)
{
	if(start>=end)
	{
	    v.push_back(str);
		//cout<<str<<endl;
		return ;
	}
	for(int i=start;i<=end;i++)
	{
		bool check=shouldSwap(str,start,i);
		if(check)
		{
			swap(str[start],str[i]);
			permutations(str,start+1,end);
			swap(str[start],str[i]);
		}
	}
}
int main() {
	string str;
	cin>>str;
	permutations(str,0,str.length()-1);
	sort(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
	return 0;
}
