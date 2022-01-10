#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;cin>>n;
    if(n<4){
        if(n==1){
            cout<<1;
            return 0;
        }
        cout<<"NO SOLUTION";
        return 0;
    }
    vector<int>odd,even;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            even.push_back(i);
        }
        else{
            odd.push_back(i);
        }
    }
    for(int i=odd.size()-1;i>-1;i--){
        cout<<odd[i]<<" ";
    }
    for(int i=even.size()-1;i>-1;i--){
        cout<<even[i]<<" ";
    }
}