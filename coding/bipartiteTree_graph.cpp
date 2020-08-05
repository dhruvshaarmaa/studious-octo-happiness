#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10];
int depth[10]={0};
set<int> s[2];
int colour[10]={0};
void dfs(int curr,int par)
{
    s[depth[curr]%2].insert(curr);
    //even depth set 0
    //odd depth set 1
	for(auto x:graph[curr])
    {
        if(x!=par)
        {
            colour[x]=3-colour[curr]; //3^colour[curr]
            depth[x]=depth[curr]+1;
            dfs(x,curr);
        }
    }
}
int main() {
	int n;
	cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    depth[1]=1;
    colour[1]=1;
	dfs(1,0);
	for(auto x:colour) cout<<x<<" ";
	return 0;
}
/*
6
1 2
1 3
3 4
3 5
5 6
*/
