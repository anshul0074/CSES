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
    dp[0]=0;
    for(int i=1;i<=v;i++){
        dp[i]=INT_MAX;
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[v]==INT_MAX){
        dp[v]=-1;
    }
    cout<<dp[v];
}