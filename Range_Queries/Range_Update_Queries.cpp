#include <bits/stdc++.h>
using namespace std;
#define int long long

int ds[2*100000+1];

void update(int n,int idx, int val){
    for(int i=idx;i<=n;i+=-i&i){
        ds[i]+=val;
    }
}
int query(int idx){
    int sum=0;
    for(int i=idx;i>0;i-=-i&i){
        sum+=ds[i];
    }
    return sum;
}
signed main(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        update(n,i,x);
        update(n,i+1,-x);
    }
    while(q--){
        int num;cin>>num;
        if(num==1){
            int a,b,u;cin>>a>>b>>u;
            update(n,b+1,-u);
            update(n,a,u);
        } 
        else{
            int k;cin>>k;
            cout<<query(k)<<"\n";
        }
    }
}