#include <bits/stdc++.h>
using namespace std;
#define int long long

int p[100001],dist[100001];
bool vis[100001];
vector<int>g[100001];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vis[1]=1;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v :g[u]){
            if(!vis[v]){
                dist[v]=dist[u]+1;
                vis[v]=1;
                p[v]=u;
                q.push(v);
            }
        }
    }
    if(!vis[n]){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    int u=n;
    int x=dist[n];
    vector<int>ans(x+1);
    for(int i=x;i>-1;i--){
        ans[i] =u;
        u=p[u];
    }
    cout<<x+1<<"\n";
    for(int i=0;i<=x;i++){
        cout<<ans[i]<<" ";
    }
}