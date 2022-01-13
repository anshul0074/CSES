#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fe[100001];
vector<int> be[100001];

signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	int indegree[n+1],dp[n+1];
	memset(indegree,0,sizeof(indegree));
    memset(dp,0,sizeof(dp));
	dp[1]=1;
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		fe[u].push_back(v);
		be[v].push_back(u);
		indegree[v]++;
	}
	queue<int>q;
	for(int i=0;i<n;i++) {
		if(indegree[i]==0) {
			q.push(i);
		}
	}
	while(!q.empty()) {
		int u=q.front();q.pop();
		for(int v:fe[u]) {
			indegree[v]--;
			if(indegree[v]==0){
                q.push(v);
            }
		}
		for(int prv:be[u]) {
			dp[u]=(dp[u]+dp[prv])%1000000007;
		}
	}
	cout<<dp[n]<<"\n";
}