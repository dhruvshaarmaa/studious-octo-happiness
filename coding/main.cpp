#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    string key;
    int val;
    node* next;
    node(string key,int val)
    {
        this->key=key;
        this->val=val;
        this->next=NULL;
    }
};
class MyHashSet {
public:
    /** Initialize your data structure here. */
    int maxsize;
    node** bucket;
    MyHashSet() {
        maxsize=1000000;
        bucket=new node*[maxsize];
        for(int i=0;i<maxsize;i++)
        {
            bucket[i]=NULL;
        }
    }
    int hashFunction(int key)
    {
        string mykey=to_string(key);
        int p=1,hashValue=0;;
        for(int i=0;i<mykey.length();i++)
        {
            hashValue+=(mykey[i]*p);
            hashValue%=maxsize;
            p*=31;
            p%=maxsize;
        }
        return hashValue;
    }
    void add(int key) {
        int hashValue=hashFunction(key);
        if(contains(key)) return;
        node *curr=new node(to_string(key),key);
        curr->next=bucket[hashValue];
        bucket[hashValue]=curr;
    }

    void remove(int key) {
        int hashValue=hashFunction(key);
        node *temp=bucket[hashValue];
        if(temp==NULL) return;
        if(temp->val==key)
        {
            bucket[hashValue]=temp->next;
            delete temp;
            return;
        }
        while(temp->next!=NULL)
        {
            if(temp->next->val==key)
            {
                temp=temp->next->next;
                return ;
            }
            temp=temp->next;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int hashValue=hashFunction(key);
        node *temp=bucket[hashValue];
        //if(temp==NULL) return false;
        while(temp!=NULL)
        {
            if(temp->val==key) return true;
            temp=temp->next;
        }
        return false;
    }
};
int main(){
    MyHashSet hashSet;
    cout<<hashSet.hashFunction(3)<<endl;
    hashSet.add(1);
    hashSet.add(2);
    cout<<hashSet.contains(1)<<endl;
    cout<<hashSet.contains(3)<<endl;
    hashSet.add(2);
    cout<<hashSet.contains(2)<<endl;
    hashSet.remove(2);
    /*
hashSet.add(1);
hashSet.add(2);
hashSet.contains(1);    // returns true
hashSet.contains(3);    // returns false (not found)
hashSet.add(2);
hashSet.contains(2);    // returns true
hashSet.remove(2);
hashSet.contains(2);    // returns false (already removed)
*/
    return 0;
}
