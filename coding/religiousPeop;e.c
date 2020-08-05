#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<long long> graph[N];
long long vis[N]={};
vector<long long> count1(N,0);
void dfs(long long root,long long colour)
{
    vis[root]=colour;
	count1[colour]++;
    for(auto x:graph[root])
    {
        if(!vis[x])
        {
            dfs(x,colour);
        }
    }
}
int religiousPeople(long long n,long long m,long long a,long long b)
{
	long long ncc=0,ans=0;
	for(long long i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ncc++;
			dfs(i,ncc);
		}
	}
	ans+=ncc*a;
	for(long long i=0;i<count1.size();i++)
	{
		if(count1[i])
		{
			ans+=(count1[i]-1)*b;
		}
	}
	return ans;
}
int main() {
	long long n,m,a,b,t;
	cin>>t;
	for(int j=0;j<t;j++)
	{
		cin>>n>>m>>a>>b;
		for(int i=0;i<m;i++)
		{
        	int x,y;
 	        cin>>x>>y;
 	        graph[x].push_back(y);
  			graph[y].push_back(x);
  		}
		if(a<=b) cout<<a*n<<endl;
		else cout<<religiousPeople(n,m,a,b)<<endl;
	}

	return 0;
}
