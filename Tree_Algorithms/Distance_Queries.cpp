#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int lvl[200002]; 
vector<int>g[200002]; 
int dp[21][200002]; 
void dfs(int u,int p,int l) {
    dp[0][u]=p;
    lvl[u]=l;
	for(auto v:g[u]){ 
		if(v!=p){ 
		    dfs(v,u,l+1);
        }
    }
}
int lca(int x,int y){
	if(lvl[x]<lvl[y]){
	    swap(x,y);
    }
	int diff=lvl[x]-lvl[y];
	for(int i=20;i>-1;i--){ 
		if(diff & (1<<i)){ 
		    x=dp[i][x];
        }
    }
	if(x==y){
        return x;
    }
	for (int i=20;i>-1;i--){
		if(dp[i][x]!=dp[i][y]){
			x=dp[i][x];y=dp[i][y];
		}
	}
	return dp[0][x];
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=1;i<n;i++) {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }    
    dfs(1,-1,0);
	for(int i=1;1<<i<=n;i++){ 
	    for(int j=0;j<=n;j++){
	        dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    while(q--){
        int u,v;cin>>u>>v;
        cout<<lvl[u]+lvl[v]-2*lvl[lca(u,v)]<<"\n";
    }
}