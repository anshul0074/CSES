#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,0));
    dp[0][0]=1;
    vector<int>ans;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            dp[i][j]=dp[i-1][j];
            if(j-arr[i-1]>=0 and dp[i-1][j-arr[i-1]]){
                dp[i][j]=1;
            }
        }
    }
    for(int j=1;j<=sum;j++){
        if(dp[n][j]){
            ans.push_back(j);
        }
    }
    cout<<ans.size()<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}