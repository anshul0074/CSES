#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,W;cin>>n>>W;
    int wt[n],val[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int k[n+1][W+1];
    for(int i=0;i<=n;i++){
        k[i][0]=0;
    }
    for(int j=0;j<=W;j++){
        k[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(w-wt[i-1]>=0){
                k[i][w]=max(k[i-1][w],val[i-1]+k[i-1][w-wt[i-1]]);
            }
            else{
                k[i][w]=k[i-1][w];
            }
        }
    }
    cout<<k[n][W];
}