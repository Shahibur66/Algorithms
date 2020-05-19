#include <bits/stdc++.h>
using namespace std;

//binary counter
void allPossibleSubset(int arr[],int n)
{
	int  count = pow(2,n);
	// The outer for loop will run 2^n times to print all subset .
	// Here variable i will act as a binary counter
	for (int i = 0; i < count; i++)
	{
		// This loop will generate a subset
		for (int j = 0; j < n; j++)
		{
			// This if condition will check if jth bit in binary representation of  i  is set or not
			// if the value of (i & (1 << j)) is greater than 0 , include arr[j] in the current subset
			// otherwise exclude arr[j]
			if ((i & (1 << j)) > 0)
			{
			    cout<<"(i & (1 << j)): "<<(i & (1 << j))<<" ";
			    cout << arr[j] << " ";
			}
		}
		cout <<endl;
	}
}

int main()
{
	int n;
	//cin >> n;
	n=3;

	int arr[n]={1,2,3};
/*
	for(int i=0;i<n;i++)
		cin >> arr[i];
*/
	allPossibleSubset(arr,n);
	
	return 0;
}
