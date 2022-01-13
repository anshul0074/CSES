#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+1;
vector<int>graph[N];
vector<bool>vis(N,0);
vector<int>done(N,-1);
 
void dfs(int s,int p){
      done[s]=p;
      vis[s]=1;
      for(auto x:graph[s]){
        if(!vis[x]){
            dfs(x,s);
        }
        else if(x!=p){
          vector<int>cycle;   
          int cur=s;
          cycle.push_back(s);
          while(done[cur]!=x){
             cur=done[cur];
             cycle.push_back(cur);
          }
          cycle.push_back(x);
          cycle.push_back(s);
          cout<<cycle.size()<<"\n";          
          for(auto x:cycle){
            cout<<x<<" ";
          }
          exit(0);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    for(int i=0;i<q;i++){
        int x,y;cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1);
        }
    }
    cout<<"IMPOSSIBLE\n";
}