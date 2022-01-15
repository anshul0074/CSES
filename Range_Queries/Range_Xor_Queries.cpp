#include<bits/stdc++.h>
using namespace std;
#define int long long 

int xorf(int arr[],int t[],int v,int tl,int tr,int l,int r){
	if(l>r){
		return 0;
	}
	else if(l==tl and r==tr){
		return t[v];
	}
	else{
		int tm=(tr+tl)/2;
		return xorf(arr,t,2*v+1,tl,tm,l,min(tm,r))^xorf(arr,t,2*v+2,tm+1,tr,max(l,tm+1),r);
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
		t[v]=t[2*v+1]^t[2*v+2];
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
		t[i]=0;
	}
	build(arr,t,0,0,n-1);
	while(q--){
        int x,y;cin>>x>>y;
        x--;y--;
        cout<<xorf(arr,t,0,0,n-1,x,y)<<"\n";
    }
}
