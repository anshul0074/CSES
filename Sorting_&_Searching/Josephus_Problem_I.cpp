#include<bits/stdc++.h>
using namespace std;
#define int long long
 
signed main(){
    int n;cin>>n;
    deque<int>dq;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    int cnt=1;
    while(!dq.empty()){
        if(cnt%2==0){
            cout<<dq.front()<<" ";
            dq.pop_front();
        }
        else{
            dq.push_back(dq.front());
            dq.pop_front();
        }
        cnt++;
    }
}
