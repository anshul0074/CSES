#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int sum=n*(n+1)/2;
    if(sum%2==1){
        cout<<0;
        return 0;
    }
    sum/=2;
    vector<vector<int>>dp(n,vector<int>(sum+1,0));
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j-i>=0){
                dp[i][j]+=dp[i-1][j-i];
            }
            dp[i][j]%=1000000007;
        }
    }
    cout<<dp[n-1][sum];
}