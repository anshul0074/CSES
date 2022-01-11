#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    int ans=1,i=0,j=0;
    for(i=0;i<n;i++){
        j=max(j,mp[arr[i]]);
        ans=max(ans,i-j+1);
        mp[arr[i]]=i+1;
    }
    cout<<ans;
}