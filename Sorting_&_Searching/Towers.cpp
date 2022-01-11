#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto it=upper_bound(v.begin(),v.end(),x);
        if(it==v.end()){
            v.push_back(x);
        }
        else{
            v[it-v.begin()]=x;
        }
    }
    cout<<v.size();
}