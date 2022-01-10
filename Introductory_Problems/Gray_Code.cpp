#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<string> make(int n){
    if(n==1){
        return {"0","1"};
    }
    vector<string>tmp=make(n-1);
    vector<string>ans;
    for(int i=0;i<tmp.size();i++){
        ans.push_back('0'+tmp[i]);
    }
    for(int i=tmp.size()-1;i>-1;i--){
        ans.push_back('1'+tmp[i]);
    }
    return ans;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    vector<string>ans=make(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
}