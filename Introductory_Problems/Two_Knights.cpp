#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int k;cin>>k;
    cout<<0<<"\n";
    for(int x=2;x<=k;x++){
        cout<<x*x*(x*x-1)/2-4*(x-1)*(x-2)<<"\n";
    }
}