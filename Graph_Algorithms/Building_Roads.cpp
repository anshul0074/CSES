#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> adj[100005];
bool vis[100005];
void dfs(int s){
    if(vis[s]){
        return;
    }
    vis[s]=1;
    for(auto i: adj[s]){
        dfs(i);
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>v;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            v.push_back(i);
            dfs(i);
        }
    }
    cout<<v.size()-1<<"\n";
    for(int i=1;i<v.size();i++){
        cout<<v[i]<<" "<<v[i-1]<<"\n";
    }
}    