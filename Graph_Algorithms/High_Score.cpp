#include<bits/stdc++.h>
using namespace std;
#define int long long

int dist[2501];
vector<int> g1[2501],g2[2501];
bool vis1[2501],vis2[2501];
void dfs(int s,bool vis[],vector<int>g[]){
    vis[s]=1;
    for(auto x:g[s]){
        if(!vis[x]){
            dfs(x,vis,g);
        }
    }
}
signed main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
    }
    dist[1]=0;
    vector<tuple<int,int,int>>e;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,-w});
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    dfs(1,vis1,g1);
    dfs(n,vis2,g2);
    bool flag=1;
    for(int i=0;i<n and flag;i++){
        flag=0;
        for(auto t:e){
            int u=get<0>(t),v=get<1>(t),w=get<2>(t);
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                flag=1;
                if(i==n-1 and vis1[v] and vis2[v]){
                    cout<<"-1\n";
                    return 0;
                }
            }
        }
    }
    cout<<-dist[n];
}