#include<bits/stdc++.h>
using namespace std;

//TRIE
class node
{
    public:
    char data;
    //vector of pointers :  vector<node*> children(128,NULL);
    //using hashmap
    unordered_map<char,node*> children;
    bool terminal;
    node(char data)
    {
        this->data=data;
        terminal=false;
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
            }
            else
            {
                node *p=new node(ch);
                temp->children[ch]=p;
                temp=p;
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

};
int main() {
    trie t;
    string str[10]={"awesome","miku","issei","rias","mi","not","no"};
    for(int i=0;i<7;i++)
    {
        t.insert(str[i]);
    }
    string s;
    cin>>s;
    if(t.search(s)) cout<<"Present"<<endl;
    else cout<<"Absent";
	return 0;
}