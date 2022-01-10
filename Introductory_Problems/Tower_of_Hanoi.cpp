#include<bits/stdc++.h>
using namespace std;
#define int long long

void toh(int n,int l,int r,int m,vector<pair<int,int>>&ans){
    if(n==1){
        ans.push_back({l,r});
        return;
    }
    toh(n-1,l,m,r,ans);
    ans.push_back({l,r});
    toh(n-1,m,r,l,ans);

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int l=1,m=2,r=3;
    vector<pair<int,int>>ans;
    toh(n,l,r,m,ans);
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<" "<<ans[i].second<<"\n";
    }
}