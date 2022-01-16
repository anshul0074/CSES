#include<bits/stdc++.h>
using namespace std;
#define int long long 

vector<int>g[200002];
int dp[200002];
 
void dfs(int u,int p){
	dp[u]=1;
	for (auto v: g[u]){
		if (v!=p){
			dfs(v,u);
			dp[u]+=dp[v];
		}
	}	
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    for(int i=2;i<=n;i++) {
        int x;cin>>x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) {
        cout<<dp[i]-1<<" ";
    }
}