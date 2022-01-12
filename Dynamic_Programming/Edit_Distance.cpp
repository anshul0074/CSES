#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string x,y;
    cin>>x;
    cin>>y;
    int dp[x.size()+1][y.size()+1];
    dp[0][0]=0;
    for(int i=1;i<=x.size();i++){
        dp[i][0]=dp[i-1][0]+1;
    }
    for(int j=1;j<=y.size();j++){
        dp[0][j]=dp[0][j-1]+1;
    }
    for(int i=1;i<=x.size();i++){
        for(int j=1;j<=y.size();j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
            }
        }
    }
    cout<<dp[x.size()][y.size()];
}