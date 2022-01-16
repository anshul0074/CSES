#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int>g[200002];
vector<int>ans(200002,-1);
int bfs(int s){
	queue<int>q;
	vector<int>dist(200002,-1);
	dist[s]=0;
	ans[s]=max(ans[s],dist[s]);
	q.push(s);
    int u;
	while(!q.empty()) {
		u=q.front();q.pop();
		for(int v: g[u]){
			if(dist[v]==-1){
				q.push(v);
				dist[v]=dist[u]+1;
				ans[v]=max(ans[v],dist[v]);
			}
		}
	}
	return u;
}
signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<n;i++) {
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int a=bfs(1),b=bfs(a);
	bfs(b);
	for(int i=1;i<=n ;i++) {
		cout<<ans[i]<<" ";
	}
}