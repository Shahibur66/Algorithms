#include<bits/stdc++.h>
using namespace std;


int c=-1;
string astr;


void push(char str)
{
    if(c>100)
    {
        
        cout<<"Stack is full"<<endl;
        
    }
    else{
        
        astr[++c]=str;
        //cout<<"push->: c: "<<c<<" charArr: "<<astr[c]<<endl;
    }
}

char pop()
{
    char ch;
    if(c<0)
      cout<<"Stack is empty"<<endl;
    else{
        ch=astr[c];
       // cout<<"pop: c: "<<c<<" ch: "<<ch<<endl;
        c--;
    }
    
    return ch;
}

bool Balanced(string str)
{
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(' || str[i]=='[')
        {
            push(str[i]);
        }
        else{
            
            if(c<0) return false;
            
             char top=pop();
            // cout<<"top: "<<top<<endl;
             
             if((top=='(' && str[i]!=')')||(top=='[' && str[i]!=']'))
             {
                 return false;
             }
        }
        
    }
   // cout<<"balanced: c: "<<c<<endl;
    return c==-1? true:false;
}

int main()
{
    string str="[()()((()))[[]]]";
    
    if(Balanced(str))
    {
        std::cout << "Balanced" << std::endl;
    }
    else
    {
        std::cout <<"Not Balanced"  << std::endl;
    }
    
    return 0;
}