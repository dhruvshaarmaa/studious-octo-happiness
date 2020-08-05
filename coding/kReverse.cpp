#include<iostream>
using namespace std;
class list
{
public:
    int val;
    list* next=NULL;
    list(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void insert(list* &head,int val)
{
    list* n= new list(val);
    n->next=head;
    head=n;
}
void insertAtTail(list* &head,int data)
{
    if(head==NULL)
    {
        insert(head,data);
        return;
    }
    list* n=new list(data);
    list* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
}
list* kReverse(list* &head,int k)
{
	if(head==NULL or head->next==NULL)
	{
		return head;
	}
	list* prev=NULL;
	list* curr=head;
	int steps=1;
	while(steps<=k and curr!=NULL)
	{
		list* n=curr->next;
		curr->next=prev;
		prev=curr;
		curr=n;
		steps++;
	}
	head->next=kReverse(curr,k);
	list* newHead=prev;
	return newHead;
}
int main() {
	list* l=NULL;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		int val;
		cin>>val;
		insertAtTail(l,val);
	}
	l=kReverse(l,k);
	list* temp=l;
	while(temp!=NULL)
	{
		cout<<temp->val<<" ";
		temp=temp->next;
	}
	return 0;
}
