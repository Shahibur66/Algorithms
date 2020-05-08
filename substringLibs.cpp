#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 

	string s1 = "hello world"; 

	string r = s1.substr(2, 3); 

	cout << "String is: " << r<<endl; 
	
	int pos = s1.find(" "); 
	
	string sub = s1.substr(pos + 1); 
  
  
    cout << "String is: " << sub; 

	return 0; 
} 
