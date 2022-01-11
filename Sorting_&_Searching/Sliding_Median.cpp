#include<bits/stdc++.h>
using namespace std;
#define int long long

const int size=200001;
int bit[size];

int total(int x){
    int sum=0;
	for(;x>0;x-=x&-x){
         sum+=bit[x];
    }
    return sum;
}
void add(int x,int val){
	for(;x<size;x+=x&-x){
         bit[x]+=val;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
    int arr[n];
    map<int,int>c,d;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		c[arr[i]]=0;
	}
	int idx=1;
	for(auto& i :c){
		i.second=idx++;
		d[i.second]=i.first;
	}
	for(int i=1;i<=n;i++){
		add(c[arr[i]],1);
		if(i>=k+1){
            add(c[arr[i-k]],-1);
        }
		int mid=(k/2)+(k&1);
		if(i>= k){
			int l=1,r=200001,ans=-1;
			while(l<=r){
				int m=(l+r)/2;
				if(total(m)>=mid and total(m-1)<mid){
					ans=m; 
                    break;
				}
				else if(total(m)<mid){
                    l=m+1;
                }
				else{
                    r=m-1;
                }
			}
			cout<<d[ans]<<" ";
		}
	}
}