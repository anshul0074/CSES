#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>indexed_set;
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    indexed_set s;
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++){
        s.insert(i+1);
    }
    int idx=k%n;
    while(n--){
        auto y=s.find_by_order(idx);
        cout<<*y<<' ';
        s.erase(y);
        if(n){
            idx=(idx%n+k)%n;
        }
    }   
}
