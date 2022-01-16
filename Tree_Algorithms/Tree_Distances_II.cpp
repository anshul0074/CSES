#include<bits/stdc++.h>
using namespace std;
#define int long long 
 
vector<int>g[200002];
int dp[200002],in[200002],out[200002];
 void indfs(int u,int p,int n){
	dp[u]=1;
	for(auto v:g[u]){
		if (v!=p){
			indfs(v,u,n);
			dp[u]+=dp[v];
			in[u]+=in[v]+dp[v];
		}
	}	
}
void outdfs(int u,int p,int n) {
	int tmp=0;
	for(auto v:g[u]) {
		if(v!=p)
		tmp+=in[v]+2*dp[v];
	}
	for(int v:g[u]){
		if(v!=p){
			out[v]=(out[u]+1*(n-dp[u]+1))+(tmp-(in[v]+2*dp[v]));
			outdfs(v,u,n);
		}
	}
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++) {
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	indfs(1,0,n);
	outdfs(1,0,n);
	for(int i=1;i<=n;i++){ 
		cout<<in[i]+out[i]<<" ";
    }	
}