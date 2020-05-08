#include<bits/stdc++.h>

using namespace std;
 
int main()
{
    int i,j,temp;
    char str[100]={"This is a pattern matching"};
    char substr[20]={"pattern"};
    
    
    int str_len=strlen(str);
    int substr_len=strlen(substr);
    
    for(i=0;i<str_len;i++)
    {
        j=0;
        int k=i;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[k]==substr[j])
            {
                k++;
                j++;
            }
 
            if(substr_len==j)
            {
                cout<<"The substring is present in given string at position: "<<temp<<endl;
            }
        }
    }
}
           