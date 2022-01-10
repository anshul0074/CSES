#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    int sum=n*(n+1)/2;
    if(sum%2==1){
        cout<<"NO";
        return 0;
    }
    int cnt=0;
    bool visited[n+1];
    memset(visited,false,sizeof(visited));
    visited[0];
    sum/=2;
    for(int i=n;i>0;i--){
        if(i<=sum){
            sum-=i;
            visited[i]=true;
            cnt++;
        }
    }
    cout<<"YES\n";
    cout<<cnt<<"\n";
    for(int i=1;i<=n;i++){
        if(visited[i]){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
    cout<<n-cnt<<"\n";
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            cout<<i<<" ";
        }
    }
}