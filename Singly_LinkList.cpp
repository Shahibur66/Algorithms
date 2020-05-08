
#include<bits/stdc++.h>

using namespace std;

typedef struct node{
    int key;
    struct node *next;
}Node;

Node *head,*tail;
void print()
{
     Node *travers=head;
    
    while(travers->next!=NULL)
    {
        cout<<travers->key<<" ";
        travers=travers->next;
    }cout<<endl;
}

void pushBack(int data)
{
    Node *newNode=(Node*)malloc(sizeof(newNode));
    newNode->key=data;
    newNode->next=NULL;
    
    Node *temp=head;
    if(temp->next==NULL)
     {
         //cout<<"empty"<<endl;
         temp->next=newNode;
         temp=newNode;
         tail=newNode;
         //cout<<"tail->data:"<<tail->key<<endl;
     }
    else{
        tail->next=newNode;
        tail=newNode;
        //cout<<"tail->data:"<<tail->key<<endl;
    }
     //cout<<"head->data:"<<head->key<<endl;
}


void popBack()
{
    
    Node *temp=head;
    if(temp->next==NULL)
     {
         temp=tail=NULL;
     }
    else{
        
        
        while(temp->next->next!=NULL)//1 2 3 
        {
            temp=temp->next;
        }
        
        temp->next=NULL;
        tail=temp;
    }
     //cout<<"head->data:"<<head->key<<endl;
}

void popFont()
{
    
    Node *temp=head;
    if(temp->next==NULL)
     {
         temp=tail=NULL;
     }
    else{
        
        head=head->next;
        if(head->next==NULL)
        {
            tail=head;
        }
    }
     //cout<<"head->data:"<<head->key<<endl;
}


void pushFont(int data)
{
    Node *newNode=(Node*)malloc(sizeof(newNode));
    newNode->key=data;
    newNode->next=NULL;
    
    Node *temp=head;
    if(temp->next==NULL)
     {
         temp->next=newNode;
         temp=newNode;
         tail=newNode;
         //cout<<"tail->data:"<<tail->key<<endl;
     }
    else{
        newNode->next=head;
        head=newNode;
        //cout<<"tail->data:"<<tail->key<<endl;
    }
     //cout<<"head->data:"<<head->key<<endl;
}


void addAfter(int key,int data)
{
    Node *newNode=(Node*)malloc(sizeof(newNode));
    newNode->key=data;
    newNode->next=NULL;
    
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
            break;
        }
    }
    
    if(!found)
    {
        cout<<"Data is not found in the list"<<endl;
    }
    if(newNode->next==NULL)
    {
        tail=newNode;
        cout<<"tail->key :"<<tail->key<<endl;
    }
 
}

void addBefor(int key,int data)
{
    Node *newNode=(Node*)malloc(sizeof(newNode));
    newNode->key=data;
    newNode->next=NULL;
    
    Node *temp=head;
    Node *tempBefore;
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
    
    //cout<<"tempBefore: "<<tempBefore->key<<" temp->key: "<<temp->key<<endl;
    
     if(!found)
    {
        cout<<"Data is not found in the list"<<endl;
    }
    
    newNode->next=tempBefore->next;
    tempBefore->next=newNode;
    
}



int main()
{
    
    Node *node=(Node*)malloc(sizeof(node));
    cout<<"Node created at: "<<node<<endl;
    node->key=10;
    node->next=NULL;
    head=node;
    cout<<"Head Indicating at: "<<head<<endl;
    cout<<"Push at back: "<<endl;
    pushBack(100);
    pushBack(200);
    pushBack(300);
    pushBack(500);
    pushBack(600);
    print();
    
    cout<<"Push at font: "<<endl;
    pushFont(8);
    pushFont(5);
    print();
    cout<<"Pop at back: "<<endl;
    popBack();
    popBack();
    print();
    cout<<"Pop at font: "<<endl;
    popFont();
    popFont();
    print();
    cout<<"Add after at positon(key, data): "<<endl;
    addAfter(100,150);
    addAfter(150,250);
    print();
    cout<<"Add before at positon (key, data): "<<endl;
    addBefor(100,99);
    addBefor(99,89);
    print();
    
    return 0;
}
