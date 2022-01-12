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
    int dp[v];
    memset(dp,0,(v+1)*sizeof(dp[0]));
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=v;j++){
            if(j-coins[i]>=0){
                dp[j]+=dp[j-coins[i]];
                dp[j]%=1000000007;
            }
        }
    }
    cout<<dp[v];
}
