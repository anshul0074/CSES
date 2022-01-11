#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,p;cin>>n>>p;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int l=0,r=1e18,ans=1e18;
    while(l<=r){
        int m=(l+r)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(m/arr[i]);
            if(sum>=p){
                break;
            }
        }
        if(sum>=p){
            ans=m;
            r=m-1;
        }
        else{
            l=m+1;
        }
    }
    cout<<ans;
}