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
    sort(arr,arr+n);
    int sum[n+1];
    sum[0]=1;
    for(int i=1;i<=n;i++){
        if(sum[i-1]<arr[i-1]){
            cout<<sum[i-1];
            return 0;
        }
        sum[i]=sum[i-1]+arr[i-1];
    }
    cout<<sum[n];
}