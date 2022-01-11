#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr,arr+n);
    int time=0,score=0;
    for(int i=0;i<n;i++){
        time+=arr[i].first;
        score+=arr[i].second-time;
    }
    cout<<score;
}