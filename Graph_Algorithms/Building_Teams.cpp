#include <bits/stdc++.h>
using namespace std;

bool flag,vis[100001],team[100001];
vector<int> g[100001];
void dfs(int u,int p=0){
    for(int v:g[u]){
        if(v!=p){
            if(!vis[v]){
                team[v]=!team[u];
                vis[v]=1;
                dfs(v,u);
            } 
            else{
                if(team[v]==team[u]){
                    flag=0;
                }
            }
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    flag=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            dfs(i);
        }
    }
    if(!flag){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        for(int i=1;i<=n;i++){
            if(!team[i]){
                cout<<"1 ";
            }
            else{
                cout<<"2 ";
            }
        }
    }
}