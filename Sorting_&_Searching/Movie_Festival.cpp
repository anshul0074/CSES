#include<bits/stdc++.h>
using namespace std;
#define int long long

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second<p2.second;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    pair<int,int>arr[n];
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        arr[i]={x,y};
    }
    sort(arr,arr+n,compare);
    int ans=1,prv=arr[0].second;
    for(int i=1;i<n;i++){
        if(arr[i].first>=prv){
            prv=arr[i].second;
            ans++;
        }
    }
    cout<<ans;
}