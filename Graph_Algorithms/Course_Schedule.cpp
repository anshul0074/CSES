#include<bits/stdc++.h>
using namespace std;
#define int long long

bool vis[100001];
int tmp[100001];
vector<int>g[100001];
vector<int>v;
void dfs(int s){
    if(vis[s]){
        return;
    }
    vis[s]=1;
    for(auto i:g[s]){
        dfs(i);
    }
    v.push_back(s);
}
bool cycle(int s){
    tmp[s]=1;
    for (auto i:g[s]){
        if(!tmp[i]){
            if(cycle(i)){
                return 1;
            }
        }
        else if(tmp[i]==1){
            return 1;
        }
    }
    tmp[s]=2;
    return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if (!tmp[i] and cycle(i)){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        if(!vis[i]){
            dfs(i);
        }
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
