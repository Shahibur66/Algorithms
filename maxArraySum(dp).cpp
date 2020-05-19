#include<bits/stdc++.h>
using namespace std;
int main()
{
    //printf("Hello World");
    int n;
    cin>>n;
    int arr[n+1];
    int dp[n+1];

    for(int i=0; i<n; i++)
        cin>>arr[i];
    
    int mx=0;
    dp[0] = 0; dp[1] = arr[0]; dp[2] = arr[1];
    
    
     for(int i = 3; i <=n; i++) {
         
         int tmp = max(dp[i-2], dp[i-3]);
         
         if(0 <= arr[i-1]) 
          dp[i] = max(arr[i-1], tmp + arr[i-1]);
         else
          dp[i] = tmp;
           
         mx = max(mx, dp[i]);
     }
    
    cout<<mx<<endl;

    return 0;
}
