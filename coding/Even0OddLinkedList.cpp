#include<iostream>
using namespace std;
class LinkedList
{
	public:
	int val;
	LinkedList* next;
	LinkedList(int val)
	{
		this->val=val;
		this->next=NULL;
	}
};
LinkedList* createList(int n)
{
	LinkedList *head,*p;
	int val;
	if(n==0)
	{
		return NULL;
	}
	cin>>val;
	head=p=new LinkedList(val);
	for(int i=1;i<n;i++)
	{
		cin>>val;
		p->next=new LinkedList(val);
		p=p->next;
	}
	return head;
}
LinkedList* evenAfterOdd(LinkedList* head)
{
	LinkedList *dummy1=new LinkedList(0),*curr1=dummy1,*dummy2=new LinkedList(0),*curr2=dummy2;
	while(head)
	{
		int value=head->val;
		if(value&2!=0)
		{
			curr1->next=head;
			curr1=curr1->next;
		}
		else
		{
			curr2->next=head;
			curr2=curr2->next;
		}
		head=head->next;
	}
	curr1->next=dummy2->next;
	curr2->next=NULL;
	return dummy1->next;
}
int main() {
	int n;
	cin>>n;
	LinkedList* head=NULL;
	head=createList(n);
	head=evenAfterOdd(head);
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	return 0;
}
