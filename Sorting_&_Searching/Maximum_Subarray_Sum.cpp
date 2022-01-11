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
    int sum=arr[0],ans=sum;
    for(int i=1;i<n;i++){
        sum=max(arr[i],sum+arr[i]);
        ans=max(ans,sum);
    }
    cout<<ans;
}