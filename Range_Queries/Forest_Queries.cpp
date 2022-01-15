#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[1001][1001];
bool grid[1001][1001];
void build(int n){
    dp[0][0]=0;
    dp[1][0]=0;
    dp[0][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+grid[i][j];
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;cin>>c;
            if(c=='*'){
                grid[i][j]=1;
            }
            else{
                grid[i][j]=0;
            }
        }
    }
    build(n);
    while(q--){
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]<<"\n";
    }
}