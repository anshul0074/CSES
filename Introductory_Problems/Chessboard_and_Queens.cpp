#include<bits/stdc++.h>
using namespace std;
#define int long long

string board[8];
bool col[8],sum[15],diff[15];
int ans=0;

void back(int row){
    if(row==8){
        ans++;
        return;
    }
    for(int j=0;j<8;j++){
        if(board[row][j]=='*' or col[j] or sum[row+j] or diff[row-j+7]){
            continue;
        }
        col[j]=sum[row+j]=diff[row-j+7]=true;
        back(row+1);
         col[j]=sum[row+j]=diff[row-j+7]=false;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    for(int i=0;i<8;i++){
        cin>>board[i];
    }
    back(0);
    cout<<ans;
}