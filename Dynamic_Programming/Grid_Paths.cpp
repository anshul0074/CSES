#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    char grid[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int dp[n][n];
    bool flag=0;
    for(int i=0;i<n;i++){
        if(grid[i][0]=='.' and flag==0){
            dp[i][0]=1;
        }
        else{
            dp[i][0]=0;
            flag=1;
        }
    }
    flag=0;
    for(int j=0;j<n;j++){
        if(grid[0][j]=='.' and flag==0){
            dp[0][j]=1;
        }
        else{
            dp[0][j]=0;
            flag=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]=='*'){
                dp[i][j]=0;
                continue;
            }
            else if(grid[i-1][j]=='.' and grid[i-1][j]=='.'){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else if(grid[i-1][j]=='.'){
                dp[i][j]=dp[i-1][j];
            }
            else if(grid[i][j-1]=='.'){
                dp[i][j]=dp[i][j-1];
            }
            else{
                dp[i][j]=0;
            }
            dp[i][j]%=1000000007;
        }
    }
    cout<<dp[n-1][n-1];
}