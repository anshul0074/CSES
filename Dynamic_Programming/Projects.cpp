#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+1;
int n, a[N], b[N];
int p[N], dp[2*N];
struct project {
    int time, id, type;
} 
times[2*N];
map<int,int> mp;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>p[i];
        times[2*i]={a[i],i,0};
        times[2*i+1]={b[i],i,1};
    }
    sort(times+2,times+2*n+2, [](project x,project y){
        return x.time==y.time ? x.id<y.id : x.time<y.time;
    });
    for(int i=2;i<=2*n+1;i++){
        if(!mp[times[i].time]){
            mp[times[i].time]=i;
        }
    }
    for(int i=2;i<=2*n+1;i++){
        if(times[i].type==0){
            dp[i]=dp[i-1];
        }
        else {
            dp[i] = max(dp[i-1], dp[mp[a[times[i].id]]-1] + p[times[i].id]);
        }
    }
    cout<<dp[2*n+1];
}