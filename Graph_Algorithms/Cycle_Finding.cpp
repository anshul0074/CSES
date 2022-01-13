#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    vector<tuple<int,int,int>>e;
    for(int i=0;i<m;i++){
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,w});
    }
    int dist[n+1],parent[n+1]={0};
    for(int i=1;i<=n;i++){
        dist[i]=1e18;
    }
    dist[1]=0; 
    int flag;
    for(int i=1;i<=n;i++){
        flag=0;
        for (auto t:e){
            int u=get<0>(t),v=get<1>(t),w=get<2>(t);
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
                flag=v;
            }
        }
    }
    if(!flag){
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    vector<int>v;
    for(int i=1;i<=n;i++){
        flag=parent[flag];
    }
    int i=flag;
    while(1){
        v.push_back(i);
        if(i==flag and v.size()>1){
            break;
        }
        i=parent[i];
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}