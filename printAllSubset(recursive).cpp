#include <bits/stdc++.h> 
using namespace std; 
int totalSubset;
void findcombination(vector<int> ar,vector<int> sol,int index)
{
   totalSubset++;
   cout<<"{";
    for(int i=0;i<sol.size();i++)
        {
            if( i==sol.size()-1)
            cout<<sol[i];
            else
            cout<<sol[i]<<" ";
        }
    cout<<"}"<<endl;

    
    for(int i=index;i<ar.size();i++)
    {
        sol.push_back(ar[i]);
        findcombination(ar,sol,i+1);
        sol.pop_back();
        
    }
    
    return;
}
int main() 
{ 
	vector<int> ar; 
	ar.push_back(1); 
	ar.push_back(2); 
	ar.push_back(3); 
	//ar.push_back(4); 
	int n = ar.size();
	vector<int> sol;
	//int curr_sum =0;
	int index=0;
	//int sum = 8; // set value of sum 
	findcombination(ar,sol,index);

	cout<<"totalSubset: "<<totalSubset<<" (2^n subset)"<<endl;
	
} 
