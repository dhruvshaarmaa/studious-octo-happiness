#include<bits/stdc++.h>
using namespace std;
template<typename T>
//unorderedMap
class node
{
public:
    string key;
    T value;
    node<T> *next;
    node(string key,T value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }
};
template<typename T>
class hashtable
{
    public:
    node<T> **bucket;
    int maxSize;
    int currSize;
    hashtable(int maxSize)
    {
        this->maxSize=maxSize;
        bucket=new node<T>*[maxSize];
        for(int i=0;i<maxSize;i++) bucket[i]=NULL;
        this->currSize=0;
    }
    //O(key.length())
    int hashFunction(string key)
    {
        int hashVal=0;
        int p=1;
        for(int i=0;i<key.length();i++)
        {
            hashVal+=key[i]*p;
            hashVal%=maxSize;
            p=p*31;
            p%=maxSize;
        }
        return hashVal;
    }
    //O(1)
    void insert(string key,T value)
    {
        double load_factor=double(currSize)/maxSize;
        if(load_factor>0.7)
        {
            rehash();
        }
        int index=hashFunction(key);
        node<T> *temp=new node<T>(key,value);
        temp->next=bucket[index];
        bucket[index]=temp;
        currSize++;
    }
    //O(N)
    node<T>* search(string key)
    {
        int index=hashFunction(key);
        node<T> *temp=bucket[index];
        if(temp==nullptr) return NULL;
        while(temp!=nullptr)
        {
            if(temp->key==key)
            {
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    //O(N)
    void remove(string key)
    {
        int index=hashFunction(key);
        node<T> *temp=bucket[index];
        if(temp==NULL) return ;
        if(temp->key==key)
        {
            bucket[index]=temp->next;
            delete [] temp;
            return ;
        }
        while(temp->next!=NULL)
        {
            if(temp->next->key==key)
            {
                temp=temp->next->next;
                return ;
            }
            temp=temp->next;
        }
    }

    void rehash()
    {
        node<T> **oldbucket=bucket;
        int oldSize=currSize;
        maxSize*=2;
        currSize=0;
        bucket=new node<T>*[maxSize];
        for(int i=0;i<maxSize;i++) bucket[i]=NULL;
        for(int i=0;i<oldSize;i++)
        {
            node<T> *temp=oldbucket[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
        }
        delete [] oldbucket;
    }
};
int main() {
    hashtable<int> H(3000);
    H.insert("aA",10);
    H.insert("BB",5);
    node<int> *temp=H.search("BB");
    cout<<temp->value<<endl;
    cout<<H.hashFunction("aA")<<endl;
    cout<<H.hashFunction("BB")<<endl;
	return 0;
}
