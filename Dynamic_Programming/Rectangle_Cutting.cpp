#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b;cin>>a>>b;
    int dp[a+1][b+1];
    for(int i=0;i<=a;i++){
        for(int j=0;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
            }
            else{
                dp[i][j]=1e9;
                for(int k=0;k<i;k++){
                    dp[i][j]=min(dp[i][j],1+dp[k][j]+dp[i-k][j]);
                }
                for(int k=0;k<j;k++){
                    dp[i][j]=min(dp[i][j],1+dp[i][k]+dp[i][j-k]);
                }
            }
        }
    }   
    cout<<dp[a][b];
}