#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    int sum=0,ans=INT_MAX;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    for(int i=0;i<(1<<n);i++){
        int curr=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                curr+=arr[j];
            }
        }
        ans=min(ans,abs(2*curr-sum));
    }
    cout<<ans;
}