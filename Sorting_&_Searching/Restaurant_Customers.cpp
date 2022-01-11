#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n],lev[n];
    for(int i=0;i<n;i++){
        cin>>arr[i]>>lev[i];
    }
    sort(arr,arr+n);
    sort(lev,lev+n);
    int x=0,y=0,ans=0,cnt=0;
    while(x<n and y<n){
        if(arr[x]<lev[y]){
            cnt++;x++;
        }
        else{
            x++;y++;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
}