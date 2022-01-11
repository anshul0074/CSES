#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    stack<pair<int,int>>st;
    int x;cin>>x;
    st.push({x,1});
    cout<<0<<" ";
    for(int i=1;i<n;i++){
       int x;cin>>x;
       while(!st.empty() and st.top().first>=x){
           st.pop();
       }
       if(!st.empty()){
            cout<<st.top().second<<" ";
       }
       else{
           cout<<0<<" ";
       }
       st.push({x,i+1});
    }
}