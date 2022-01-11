#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    int tsum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        tsum+=arr[i];
    }
    sort(arr,arr+n);
    int ans=1000000000000000000,cost=0,psum=0;
    for(int i=0;i<n;i++){
        cost=tsum-2*psum+arr[i]*(2*i-n);
        ans=min(ans,cost);
        psum+=arr[i];
    }
    cout<<ans;
}