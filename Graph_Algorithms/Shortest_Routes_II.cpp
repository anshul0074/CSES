#include<bits/stdc++.h>
using namespace std;
#define int long long

int dist[501][501];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,q; cin>>n>>m>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dist[i][j]=1e12;
        }
    }
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        dist[u][u]=0;
        dist[v][v]=0;
        dist[u][v]=min(dist[u][v],w);
        dist[v][u]=min(dist[u][v],w);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        int x,y;cin>>x>>y;
        if(dist[x][y]<1e12){
            cout<<dist[x][y]<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
}
