#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    set<string>st;
    string s;cin>>s;
    sort(s.begin(),s.end());
    do{
        if(st.find(s)==st.end()){
            st.insert(s);
        }
    }
    while(next_permutation(s.begin(),s.end()));
    cout<<st.size()<<"\n";
    set<string>::iterator i;
    for(i=st.begin();i!=st.end();i++){
        cout<<*i<<"\n";
    }
}