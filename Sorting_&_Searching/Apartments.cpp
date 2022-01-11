#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m,k;cin>>n>>m>>k;
    int a[n],b[n],x=0,y=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    while(x<n and y<m){
        if(abs(a[x]-b[y])<=k){
            x++;y++;ans++;
        }
        else if(a[x]-b[y]>k){
            y++;
        }
        else if(b[y]-a[x]>k){
            x++;
        }
    }
    cout<<ans;
}