#include<bits/stdc++.h>
using namespace std;
// template<typename T>
//pointer should be declared as node<T> *temp;
//like stl vector<int> v;
template<typename T>
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
        this->next=NULL;
    }
};
template<typename T>
class hashtable
{
    public:
    //pointer to a pointer
    node<T> **bucket;
    int maxSize;
    int currSize;
    //constructor
    hashtable(int maxSize)
    {
        this->maxSize=maxSize;
        this->currSize=0;
        bucket=new node<T>*[maxSize];
        for(int i=0;i<maxSize;i++)
        {
            bucket[i]=NULL;
        }
    }
    //find index value for a particular key
    int hashFunction(string key)
    {
        int hashValue=0;
        int p=1;
        for(int i=0;i<key.length();i++)
        {
            hashValue+=key[i]*p;
            hashValue%=maxSize;
            p=p*31;
            p%=maxSize;
        }
        return hashValue;
    }
    void insert(string key,T value)
    {
        double load_factor = (double)currSize / maxSize;

		if (load_factor > 0.7) {
			rehash();
		}

        int index=hashFunction(key);
        node<T> *n=new node<T>(key,value);
        n->next=bucket[index];
        bucket[index]=n;
        currSize++;
    }
    node<T>* search(string key)
    {
        int index=hashFunction(key);
        node<T>* temp=bucket[index];
        if(temp==NULL) return NULL;
        while(temp!=NULL)
        {
            if(temp->key==key)
            {
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
    void remove(string key)
    {
        int index=hashFunction(key);
        node<T> *temp=bucket[index];
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
        // pointer pointing to base address of main list
        node<T> **oldBucket=bucket;
        int oldSize=maxSize;
        currSize=0;
        maxSize*=2;
        //new memory allocation for new array of hashtable with size twice that of maxsize
        bucket=new node<T>*[maxSize];
        for(int i=0;i<maxSize;i++) bucket[i]=NULL;
        for(int i=0;i<oldSize;i++)
        {
            node<T> *temp=oldBucket[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp=temp->next;
            }
        }
        delete [] oldBucket;
    }
};
int main() {
    hashtable<int> H(3000);
    H.insert("BB",5);
    H.insert("aA",10);
    cout<<H.hashFunction("BB")<<endl;
    //cout<<H.search("BB")->value<<endl;
	return 0;
}
