#include<bits/stdc++.h>
using namespace std;
void draw(int n)
{
    if(n==0)
    return;
    
    draw(n-1);
    
    for(int i=0; i<n; i++)
    {
        cout<<"#";
    }cout<<endl;
   
}

int main()
{

    int n=5;
    draw(n);

    return 0;
}
