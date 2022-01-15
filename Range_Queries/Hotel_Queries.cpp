#include <bits/stdc++.h>
using namespace std;
#define int long long
 
struct vertex{
  int val;
  int idx;
};
void build(vertex tree[],int a[], int v, int tl, int tr){
    if(tl==tr){
        tree[v].val=a[tl];
        tree[v].idx=tl+1;
        return;
    }
    int m=(tl+tr)/2;
    build(tree,a,2*v,tl,m);
    build(tree,a,2*v+1,m+1,tr);
    if(tree[2*v].val>=tree[2*v+1].val){
       tree[v]=tree[2*v];
    }
    else{
       tree[v]=tree[2*v+1];
    }
}
int query(vertex tree[],int v, int tl, int tr, int num){
    if(tree[v].val<num){
        return 0;
    }
    if(tl==tr){
        tree[v].val-=num;
        return tree[v].idx;
    }
    int m=(tl+tr)/2,x;
    if(tree[2*v].val>=num){
        x=query(tree,2*v,tl,m,num);
        if(tree[2*v].val>=tree[2*v+1].val){
            tree[v]=tree[2*v];
        }
        else{
            tree[v]=tree[2*v+1];
        }
   }
   else{
        x=query(tree,2*v+1,m+1,tr,num);
        if(tree[2*v].val>=tree[2*v+1].val){
         tree[v]=tree[2*v];
        }
        else{
            tree[v]=tree[2*v+1];
        }
    }
    return x;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,q;cin>>n>>q;
    int h[n],r[q];
    vertex tree[4*n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    for(int i=0;i<q;i++){
        cin>>r[i];
    }
    build(tree,h,1,0,n-1);
    for(int i=0;i<q;i++){
        cout<<query(tree,1,0,n-1,r[i])<<" ";
    }
}