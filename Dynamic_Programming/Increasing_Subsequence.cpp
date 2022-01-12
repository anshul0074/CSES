#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>dp;
    for(int i=0;i<n;i++){
        auto it=lower_bound(dp.begin(),dp.end(),arr[i]);
        if(it==dp.end()){
            dp.push_back(arr[i]);
        }
        else{
            *it=arr[i];
        }
    }
    cout<<dp.size();
}