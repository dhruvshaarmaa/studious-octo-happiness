#include<iostream>
using namespace std;
class list
{
public:
    int val;
    list* next;
    list(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
list* merge(list* a,list* b)
{
	if(a==NULL)
	{
		return b;
	}
	if(b==NULL)
	{
		return a;
	}
	list* newHead;
	if(a->val<b->val)
	{
		newHead=a;
		newHead->next=merge(a->next,b);
	}
	else
	{
		newHead=b;
		newHead->next=merge(a,b->next);
	}
	return newHead;
}
list* createList(int n){
   list *head, *p;
   if(n==0)
   {
       return NULL;
   }
   int val;
   cin>>val;
   p = head = new list(val);
   for (int i = 1; i < n; i++) {
        cin>>val;
        p->next = new list(val);
        p = p->next;
   }
   return head;
}
int main() {

	int test,n,m;
	cin>>test;
	for(int j=0;j<test;j++)
	{
		list* l1=NULL;
	    list* l2=NULL;
		cin>>n;
		l1=createList(n);
		cin>>m;
		l2=createList(m);
	    list* l=merge(l1,l2);
	    while(l!=NULL)
	    {
		    cout<<l->val<<" ";
		    l=l->next;
	    }
		cout<<endl;
	}

	return 0;
}
