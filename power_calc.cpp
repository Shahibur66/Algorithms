
#include <iostream> 
using namespace std; 


unsigned int power(unsigned int n,int y) 
{ 
	int res = 1, i; 
	for (i = 1; i <= y; i++) 
		res *= n; 
	return res; 
} 

int main() 
{ 
	int x = 5,y=2; 
	cout << "power of x^y is "
		<< power(x,y) << endl; 
	return 0; 
} 

// This code is contributed by Shivi_Aggarwal 
