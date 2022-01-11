#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,w;cin>>n>>w;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int x=0,y=n-1,ans=0;
    while(x<=y){
        if(x==y){
            ans++;
            break;
        }
        else if(arr[x]+arr[y]<=w){
            x++;y--;ans++;
        }
        else{
            y--;ans++;
        }
    }
    cout<<ans;
}