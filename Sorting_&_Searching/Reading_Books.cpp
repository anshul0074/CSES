#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int sum=0,mx=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        sum+=x;
        mx=max(mx,x);
    }
    cout<<max(2*mx,sum);
}