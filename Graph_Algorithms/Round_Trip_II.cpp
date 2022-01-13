#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+1;
vector<int> graph[N],vis(N,0),done(N,0);
 
void dfs(int v){
    vis[v]=1;
    for(auto &i :graph[v]){
        if(!vis[i]){
            done[v]=i;
            dfs(i);
        }
        else if(vis[i]==1){
            vector<int> ans;
            ans.push_back(i);
            int j=i;
            done[v]=i;
            while(done[j]!=i){
                ans.push_back(done[j]);
                j=done[j];
            }
            ans.push_back( i );
            cout<<ans.size()<<"\n";
            for(auto &j :ans){
                cout<<j<<" ";
            }
            exit(0);
        }
    }
    vis[v]=2;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        if(x==y){
            cout<<"2\n";
            cout<<x<<" "<<y<<"\n";
        }
        graph[x].push_back(y);
    }
    for(int i=1;i<= n;i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    cout<<"IMPOSSIBLE\n";
}