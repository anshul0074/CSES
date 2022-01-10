#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    map<char,int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    map<char,int>::iterator i;
    int oddcnt=0;
    char c='*';
    for(i=mp.begin();i!=mp.end();i++){
        if(i->second%2==1){
            oddcnt++;
            c=i->first;
        }
    }
    if(oddcnt>1){
        cout<<"NO SOLUTION\n";
        return 0;
    }
    string ans="";
    if(oddcnt==1){
        ans+=c;
    }
    for(i=mp.begin();i!=mp.end();i++){
        if(i->first==c and i->second==1){
            continue;
        }
        string s(i->second/2,i->first);
        ans=ans+s;
        ans=s+ans;
    }
    cout<<ans;
}