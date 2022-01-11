#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int l,n;cin>>l>>n;
    set<int>st;
    multiset<int>ms;
    st.insert(0);
    st.insert(l);
    ms.insert(l);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        auto it=st.lower_bound(x);
        auto jt=it;
        --jt;
        ms.erase(ms.find(*it-*jt));
        ms.insert(*it-x);
        ms.insert(x-*jt);
        cout<<*(--ms.end())<<" ";
        st.insert(x);
    }
}