#include<bits/stdc++.h>
#include<stack>
using namespace std;


bool Balanced(string str)
{
   
    stack<char>s;
    
    for(int i=0; i<str.size(); i++)
    {
        if(str[i]=='(' || str[i]=='[')
        {
            s.push(str[i]);
        }
        else{
            
            if(s.empty()) 
            return false;
            
           char top=s.top();
           s.pop();
            
            if ((top=='(' && str[i]!=')') || (top=='[' && str[i]!=']'))
            return false;
        }
    }
    return s.empty();
}

int main()
{
    string str="([])[]()";
    
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