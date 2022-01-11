#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int>arr(n);
    int psum=0;
    arr[psum]=1;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        psum+=x;
        arr[(psum%n+n)%n]++;
    }
    int ans=0;
    for(int x: arr){
        ans+=(x*(x-1)/2);
    }
    cout<<ans;
}