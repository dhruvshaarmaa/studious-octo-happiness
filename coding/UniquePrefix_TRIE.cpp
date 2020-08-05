#include<bits/stdc++.h>
using namespace std;

//TRIE
class node
{
    public:
    char data;
    int cnt;
    //vector of pointers :  vector<node*> children(128,NULL);
    //using hashmap
    unordered_map<char,node*> children;
    bool terminal;
    node(char data)
    {
        this->data=data;
        terminal=false;
        cnt=0;
    }
};
class trie
{
    node *root;
public:
    trie()
    {
        root=new node('/0');
    }
    void insert(string s)
    {
        node *temp=root;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(temp->children.count(ch))
            {
                temp=temp->children[ch];
                temp->cnt=temp->cnt+1;
            }
            else
            {
                node *p=new node(ch);
                temp->children[ch]=p;
                temp=p;
                temp->cnt=temp->cnt+1;
            }
        }
        temp->terminal=true;
    }
    bool search(string s)
    {
        node *temp=root;
        for(auto x:s)
        {
            if(temp->children.count(x)==0)
            {
                return false;
            }
            else
            {
                temp=temp->children[x];
            }
        }
        return temp->terminal;
    }
    string uniquePrefix(string s)
    {
        string ans="";
        node *temp=root;
        for(auto x:s)
        {
            temp=temp->children[x];
            if(temp->cnt>1) ans+=temp->data;
            else
            {
                ans+=temp->data;
                return ans;
            }

        }
    }
};
int main() {
    trie t;
    string str[10]={"zebra","zebras","dog","dove","duck"};
    for(int i=0;i<5;i++)
    {
        t.insert(str[i]);
    }
    //string s;
    //cin>>s;
    //if(t.search(s)) cout<<"Present"<<endl;
    //else cout<<"Absent";
	for(int i=0;i<5;i++)
    {
        cout<<t.uniquePrefix(str[i])<<" ";
    }
	return 0;
}
