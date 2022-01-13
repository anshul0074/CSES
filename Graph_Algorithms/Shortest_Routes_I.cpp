#include<bits/stdc++.h>
using namespace std;
#define int long long

int vis[100001],dis[100001];
vector<pair<int,int>> g[100001];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    for(int i=2;i<=n;i++){
        dis[i]=(int)INFINITY;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u=pq.top().second;pq.pop();
        if(vis[u]){
            continue;
        }
        vis[u]=1;
        for(auto p:g[u]){
            int v=p.first,w=p.second;
            if (dis[v]>dis[u]+w){
                dis[v]=dis[u]+w;
                pq.push({dis[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dis[i]<<" ";
    }
}
