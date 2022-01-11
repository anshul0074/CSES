#include<bits/stdc++.h>
using namespace std;
#define int long long

bool check(int m,int arr[],int n,int k){
    int cnt=0,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]>m){
            return false;
        }
        if(sum+arr[i]>m){
            cnt++;
            sum=0;
        }
        sum+=arr[i];
    }
    if(sum>0){
        cnt++;
    }
    return cnt<=k;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;cin>>n>>k;
    int arr[n];
    int l=0,r=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        r+=arr[i];
    }
    int ans=0;
    while(l<=r){
        int m=(l+r)/2;
        if(check(m,arr,n,k)){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans;
}