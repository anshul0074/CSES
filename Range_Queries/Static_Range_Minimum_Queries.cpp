#include<bits/stdc++.h>
using namespace std;
#define int long long 

int minf(int arr[],int t[],int v,int tl,int tr,int l,int r){
	if(l>r){
		return INT_MAX;
	}
	else if(l==tl and r==tr){
		return t[v];
	}
	else{
		int tm=(tr+tl)/2;
		return min(minf(arr,t,2*v+1,tl,tm,l,min(tm,r)),minf(arr,t,2*v+2,tm+1,tr,max(l,tm+1),r));
	}
}
void build(int arr[],int t[],int v,int tl,int tr){
	if(tl==tr){
		t[v]=arr[tl];
	}
	else{
		int tm=(tl+tr)/2;
		build(arr,t,2*v+1,tl,tm);
		build(arr,t,2*v+2,tm+1,tr);
		t[v]=min(t[2*v+1],t[2*v+2]);
	}
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);	
	int n,q;cin>>n>>q;
	int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
	int t[4*n];
	for(int i=0;i<4*n;i++){
		t[i]=INT_MAX;
	}
	build(arr,t,0,0,n-1);
	while(q--){
        int x,y;cin>>x>>y;
        x--;y--;
        cout<<minf(arr,t,0,0,n-1,x,y)<<"\n";
    }
}
