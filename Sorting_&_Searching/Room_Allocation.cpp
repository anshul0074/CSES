#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    multimap<pair<int,int>,int>mp;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        mp.insert({{x,y},i});
    }
    int idx[n];
    priority_queue<pair<int,int>>pq;
    multimap<pair<int,int>,int>::iterator i=mp.begin();
    int cnt=1,ans=0;
    pq.push({-i->first.second,cnt});
    idx[i->second]=cnt;
    i++;
    while(i!=mp.end()){
        if(-pq.top().first>=i->first.first){
            idx[i->second]=++cnt;
            pq.push({-i->first.second,cnt});
            ans=max(ans,(int)pq.size());
        }
        else{
            idx[i->second]=pq.top().second;
            pq.pop();
            pq.push({-i->first.second,idx[i->second]});
        }
        i++;
    }
    cout<<cnt<<"\n";
    for(int i=0;i<n;i++){
        cout<<idx[i]<<" ";
    }
}