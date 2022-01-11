#include<bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t;cin>>n>>t;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        int x;cin>>x;
        arr[i]={x,i+1};
    }
    sort(arr,arr+n);
    for(int i=0;i<n-2;i++){
        int l=i+1,r=n-1;
        while(l<r){
            int sum=arr[i].first+arr[l].first+arr[r].first;
            if(sum==t){
                cout<<arr[i].second<<" "<<arr[l].second<<" "<<arr[r].second;
                return 0;
            }
            else if(sum>t){
                r--;
            }
            else{
                l++;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}