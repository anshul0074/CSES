#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,sum;cin>>n>>sum;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,pair<int,int>>mp;
    for(int i=n-1;i>-1;i--){
        for(int j=i-1;j>-1;j--){
            int rsum=sum-arr[i]-arr[j];
            if(mp.find(rsum)!=mp.end()){
                cout<<i+1<<" "<<j+1<<" "<<mp[rsum].first<<" "<<mp[rsum].second;
                exit(0);
            }
        }
        for(int j=i+1;j<n;j++){
            mp[arr[i]+arr[j]]={i+1,j+1};
        }
    }
    cout<<"IMPOSSIBLE";
}