#include<bits/stdc++.h>
using namespace std;

int n=5;
int arr[5];
int enqueue_c=0,dequeue_c=0;
   
void enqueue(int x)
{
    
    if(arr[enqueue_c]==-1 && arr[enqueue_c+1]!=-1)
    {
        cout<<"Queue is full"<<endl;
        return;
    }
    if(enqueue_c==n)
     enqueue_c=0;
    
     arr[enqueue_c]=x;
     cout<<"Enqueue(): "<<arr[enqueue_c]<<endl;
     enqueue_c++;
     
    //cout<<"enqueue_c: "<<enqueue_c<<endl;
}

void dequeArr()
{
    
    if(dequeue_c==enqueue_c)
     {
         cout<<"Queue is empty"<<endl;
         return;
     }     
     
    if(dequeue_c==n)
     dequeue_c=0;
   
    int x=arr[dequeue_c];
    arr[dequeue_c]=-1;
    dequeue_c++;
    cout<<"Dequeue(): "<<x<<endl;//https://www.onlinegdb.com/online_c_compiler#tab-stdin
    //cout<<"dequeue_c: "<<dequeue_c<<endl;

  
}

int main()
{
   enqueue(10);
   enqueue(100);
   enqueue(1000);
   enqueue(10000);
   enqueue(5000);
   dequeArr();
   dequeArr();
   dequeArr();
   enqueue(160);
   enqueue(220);
   
    return 0;
}
