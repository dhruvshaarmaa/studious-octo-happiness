#include<bits/stdc++.h>
using namespace std;
class person
{
    public:
    int age;
    string name;
    person(string name,int age)
    {
        this->name=name;
        this->age=age;
    }
};
//compare class has to be made for personalized queue comparing
class compare
{
    public:
    bool operator()(person a,person b)
    {
        //descending order age
        return a.age<b.age;
    }
};
int main() {
    //default max heap
    priority_queue<person,vector<person>,compare> q;
    int n=4;
    //cin>>n;
    for(int i=0;i<n;i++)
    {
        string name;
        int age;
        cin>>name>>age;
        person p(name,age);
        q.push(p);
    }
    while(!q.empty())
    {
        person p=q.top();
        cout<<p.name<<" "<<p.age<<endl;
        q.pop();
    }
	return 0;
}
