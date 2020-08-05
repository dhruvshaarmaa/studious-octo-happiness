#include<bits/stdc++.h>
using namespace std;
#define P pair<int,int>
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main() {
    int n,m;
    cin>>n>>m;
    string s[n];
    bool vis[n][m];
    int dis[n][m];
    pair<int,int> nearest_shop[n][m];
    //{x,y}
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        for(int j=0;j<m;j++)
        {
            vis[i][j]=false;
            dis[i][j]=INT_MAX;
            if(s[i][j]=='X')
            {
                vis[i][j]=true;
                dis[i][j]=0;
                nearest_shop[i][j]={i,j};
                //push shops in queue
                q.push({i,j});
            }
        }
    }
    while(!q.empty())
    {
        pair<int,int> curr=q.front();
        q.pop();
        int x=curr.first,y=curr.second;
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(xx>=0 && xx<n && yy>=0 && yy<m && !vis[xx][yy])
            {
                vis[xx][yy]=1;
                dis[xx][yy]=dis[x][y]+1;
                nearest_shop[xx][yy]=nearest_shop[x][y];
                q.push({xx,yy});
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<"{"<<nearest_shop[i][j].first<<","<<nearest_shop[i][j].second<<"} ";
        }
        cout<<endl;
    }
    return 0;
}
/*
7 9
000000000
000000X00
000000000
00X000000
000000000
000000000
0000X0000
*/
