#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e6+6;
int dp[N][2];
const int r=1e9+7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    dp[1][0]=dp[1][1]=1;
    for (int i=2;i<N;i++){
        dp[i][0]=(dp[i-1][0]*4%r+dp[i-1][1])%r;
        dp[i][1]=(dp[i-1][0]+dp[i-1][1]*2%r)%r;
    }
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        cout<<(dp[n][0] +dp[n][1])%r<<"\n";
    }
}