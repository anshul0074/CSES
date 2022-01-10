#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;
        int x=(2*a-b),y=(2*b-a);
        if(x>=0 and y>=0 and x%3==0 and y%3==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}