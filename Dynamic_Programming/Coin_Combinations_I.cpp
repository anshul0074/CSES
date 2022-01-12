#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,v;cin>>n>>v;
    int coins[n];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int dp[v+1];
    memset(dp,0,(v+1)*sizeof(dp[0]));
    dp[0]=1;
    for(int i=1;i<=v;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0){
               dp[i]+=dp[i-coins[j]];
                dp[i]%=1000000007;
            }
        }
    }
    cout<<dp[v];
}