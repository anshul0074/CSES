#include<bits/stdc++.h>
using namespace std;
#define int long long

int lvl[200002]; 
vector<int>g[200002]; 
int dp[21][200002]; 
void dfs(int u,int p,int l) {
    dp[0][u] = p;
    lvl[u]=l;
	for(auto v:g[u]){ 
		if(v!=p){ 
		    dfs(v,u,l+1);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=2;i<=n;i++) {
        int u;cin>>u;
        g[u].push_back(i);
        g[i].push_back(u);
    }    
    dfs(1,-1,0);
	for(int i=1;1<<i<=n;i++){ 
	    for(int j=0;j<=n;j++){
	        dp[i][j]=dp[i-1][dp[i-1][j]];
        }
    }
    while(q--){
        int u,k;cin>>u>>k;
		int v=u;
		for(int i=0;i<=20;i++){
		    if(k&(1<<i)){
		        v=dp[i][v];
            }
        }
        if(v==0){
            v--;
        }
        cout<<v<<"\n";
    }
}