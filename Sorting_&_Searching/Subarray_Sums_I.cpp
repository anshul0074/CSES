#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,x;cin>>n>>x;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int>mp;
    mp[0]=1;
    int psum=0,ans=0;
    for(int i=0;i<n;i++){
        psum+=arr[i];
        ans+=mp[psum-x];
        mp[psum]++;
    }
    cout<<ans;
}