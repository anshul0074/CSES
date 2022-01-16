#include<bits/stdc++.h>
using namespace std;
#define int long long
 
vector<int>g[200002];
 
pair<int,int> bfs(int s){
	int d=0;
	queue<pair<int,int>>q;
	q.push({s,0});
	vector<bool>vis(200002,0);
	pair<int,int> u;
	while(!q.empty()) {
		u=q.front();
		vis[u.first]=1;
		q.pop();
		for(int v: g[u.first])
			if(!vis[v]){
			    q.push({v,u.second+1});
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
	pair<int,int>a=bfs(1);
	pair<int,int>b=bfs(a.first);
	cout<<b.second;
}