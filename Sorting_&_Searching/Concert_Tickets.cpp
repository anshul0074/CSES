#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	multiset<int>st;
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		st.insert(x);
	}
	for(int i=0;i<m;i++){
		int x;cin>>x;
		auto it=st.upper_bound(x);
		if(it==st.begin()){
			cout<<-1<<"\n";
		}
		else{
			cout<<*(--it)<<"\n";
			st.erase(it);
		}
	}
}