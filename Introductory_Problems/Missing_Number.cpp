#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    visited[0]=true;
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
        visited[x]=true;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<i;
            return 0;
        }
    }
}