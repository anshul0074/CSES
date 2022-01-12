#include<bits/stdc++.h>
using namespace std;
#define int long long

int maxdig(int x){
    string s=to_string(x);
    int y=0;
    for(int i=0;i<s.size();i++){
        y=max(y,(int)s[i]-'0');
    }
    return y;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int cnt=0;
    while(n%10!=n){
        n-=maxdig(n);
        cnt++;
    }
    if(n!=0){
        cnt++;
    }
    cout<<cnt;
}