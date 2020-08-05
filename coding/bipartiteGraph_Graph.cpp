#include<bits/stdc++.h>
using namespace std;
vector<int> graph[10];
int colour[10]={0};
int vis[10]={0};
int odd_cycle=0;
void dfs(int curr,int par)
{
    vis[curr]=1; //marked current visited
	for(auto x:graph[curr])
    {
        if(!vis[x])
        {
            colour[x]=3-colour[curr]; //3^colour[curr]
            dfs(x,curr);
        }
        else if(x!=par and colour[x]==colour[curr]) //back edge detected
        {
            odd_cycle=1;
        }
    }
}
int main() {
	int n,m;
	cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    colour[1]=1;
	dfs(1,0);
	if(odd_cycle==1) cout<<"Odd Cycle Detected";
	else cout<<"Bipartite Graph";
	//for(auto x:colour) cout<<x<<" ";
	return 0;
}
/*
5 5
1 2
1 5
2 3
3 4
4 5

*/
/*
6
1 2
1 3
3 4
3 5
5 6
*/
