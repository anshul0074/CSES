#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int dp[n+1];
    memset(dp,0,(n+1)*sizeof(dp[0]));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j<0){
                break;
            }
            dp[i]+=dp[i-j];
            dp[i]%=1000000007;
        }
    }
    cout<<dp[n];
}