#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int key;
    struct node *next,*prev;
}Node;

Node *head,*tail;

Node* createNewNode(int data)
{
    
    Node *newNode=(Node*)malloc(sizeof(newNode));
    newNode->key=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    
    return newNode;
}
void print()
{
     Node *travers=head;
    //cout<<"Before-travers-key: "<<travers->key<<endl;
    while(travers->next)
    {
        cout<<travers->key<<" ";
        travers=travers->next;
    }cout<<endl;
    //cout<<"After-travers-key: "<<travers->key<<endl;

}

void printReverse()
{
     Node *travers=tail;
    
    while(travers->prev!=NULL)
    {
        cout<<travers->key<<" ";
        travers=travers->prev;
    }cout<<endl;
}

void pushBack(int data)
{
    Node *newNode=createNewNode(data);
    Node *temp=head;
    //cout<<" pushBack-key: "<<temp->key<<endl;
  //cout<<"Before-pushBack-key: "<<tail->key<<endl;
 // cout<<"Before-pushBack-next: "<<newNode->next<<endl;
   if(tail->next==NULL)
    {
     tail->next=newNode;
     newNode->prev=tail;
    // newNode->next=NULL;
     tail=newNode;
    }
    //cout<<"After-pushBack-next: "<<newNode->next<<endl;
    
}
void popBack()
{
    
    Node *temp=head;
    
    if(temp==NULL)
    {
        cout<<"Empty list"<<endl;
    }
    else if(head==tail)
    {
        head=tail=NULL;
    }
    else{
        tail=tail->prev;
        tail->next=NULL;
    }
}

void addAfter(int key,int data)
{
    Node *newNode=createNewNode(data);
    Node *temp=head;
    
    int found=0;
    while(temp->key!=key && temp->next!=NULL)
    {
        temp=temp->next;
        
        if(temp->key==key)
        {
            found=1;
            
            newNode->next=temp->next;
            temp->next=newNode;
            newNode->prev=temp;
            if(newNode->next!=NULL)
             newNode->next->prev=newNode;
            if(tail==temp)
              tail=newNode;
            break;
        }
    }
    
    if(found)
    cout<<"Item is not found in the list"<<endl;
   
}

void addBefor(int key,int data)
{
    Node *newNode=createNewNode(data);
    Node *temp=head;
    Node *tempBefore=head;
   
     int found=0;
    while(temp->key!=key && temp->next!=NULL)
    {
        tempBefore=temp;
        temp=temp->next;
        
        if(temp->key==key)
        {
            found=1;
            break;
        }
    }
    
    if(found)
    cout<<"Item is not found in the list"<<endl;
    
    else{
        
         newNode->next=tempBefore;
         newNode->prev=tempBefore->prev;
         tempBefore->prev=newNode;
         if(newNode->prev!=NULL)
         {
             newNode->prev->next=newNode;
         }
         if(head==tempBefore){
             head=newNode;
         }
    }
    
}

int main()
{
    
    Node *node=createNewNode(10);
    cout<<"Node created at: "<<node<<endl;
    head=tail=node;
    cout<<"Head Indicating at: "<<head<<endl;
    cout<<"Tail Indicating at: "<<tail<<endl<<endl;
    cout<<"Push at back: "<<endl;
    pushBack(20);
    pushBack(30);
    //pushBack(40);
    print();
    printReverse();
    //popBack();
    //addAfter(20,24);
    //print();
    cout<<"Add item at Befor: "<<endl;
    addBefor(24,42);
    print();
    printReverse();
    
    return 0;
}