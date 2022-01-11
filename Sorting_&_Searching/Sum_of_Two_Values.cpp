#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t;cin>>n>>t;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        int num;cin>>num;
        arr[i]={num,i};
    }
    sort(arr,arr+n);
    int x=0,y=n-1;
    while(x<y){
        if(arr[x].first+arr[y].first==t){
            cout<<arr[x].second+1<<" "<<arr[y].second+1;
            return 0;
        }
        else if(arr[x].first+arr[y].first>t){
            y--;
        }
        else{
            x++;
        }
    }
    cout<<"IMPOSSIBLE";
}