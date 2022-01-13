#include<bits/stdc++.h>
using namespace std;
#define int long long

bool vis[100001];
void fun(int s,int dis[],vector<pair<int,int>> g[]){
    priority_queue<pair<int,int>>pq;
    for(int i=1;i<100001;i++){
        dis[i]=1e18;
    }
    dis[s]=0;
    pq.push({0,s});
    memset(vis,0,sizeof(vis));
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto p: g[u]){
            int v=p.first,w=p.second;
            if (dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                pq.push({-dis[v],v});
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<pair<int,int>>g1[n+1],g2[n+1];
    vector<tuple<int,int,int>>e;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,w});
        g1[u].push_back({v,w});
        g2[v].push_back({u,w});
    }
    int dis1[100001],dis2[100001];
    fun(1,dis1,g1);
    fun(n,dis2,g2);
    int ans=1e18;
    for (auto t:e){
        int u=get<0>(t),v=get<1>(t),w=get<2>(t);
        ans=min(ans,dis1[u]+dis2[v]+w/2);
    }
    cout<<ans<<"\n";
}