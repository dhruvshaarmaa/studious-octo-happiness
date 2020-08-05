#include<bits/stdc++.h>
using namespace std;
class graph
{
    map<string, list<pair<string,int>> > l;
public:
    void addEdge(string x,string y,bool bidirec,int weight)
    {
        l[x].push_back({y,weight});
        if(bidirec) l[y].push_back({x,weight});
    }
    void display()
    {
        for(auto x:l)
        {
            cout<<x.first<<"->";
            for(auto y:x.second)
            {
                cout<<y.first<<","<<y.second<<" ";
            }
            cout<<endl;
        }
    }
};
int main() {
    graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.addEdge("B","D",true,30);
    g.addEdge("C","D",true,40);
    g.display();
	return 0;
}
