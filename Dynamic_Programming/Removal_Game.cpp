#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int l=n-1;l>-1;l--){
        for(int r=l;r<n;r++){
            if(l==r){
                dp[l][r]=arr[l];
            }
            else{
                dp[l][r]=max(arr[l]-dp[l+1][r],arr[r]-dp[l][r-1]);
            }
        }
    }
    cout<<(sum+dp[0][n-1])/2;
}