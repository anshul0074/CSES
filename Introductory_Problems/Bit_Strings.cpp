#include<bits/stdc++.h>
using namespace std;
#define int long long

int fun(int x,int n,int mod){
    if(n==0){
        return 1;
    }
    int u=fun(x,n/2,mod);
    u=(u*u)%mod;
    if(n%2==1){
        return (x*u)%mod;
    }
    return u;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int x=2;
    int mod=1000000007;
    cout<<fun(x,n,mod);
}