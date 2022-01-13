#include<bits/stdc++.h>
using namespace std;
#define int long long

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x,int y,int r,int c,string grid[]){
    grid[x][y]='#';
    for(int i=0;i<4;i++){
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(xx>=0 and xx<r and yy>=0 and yy<c and grid[xx][yy]=='.'){
            dfs(xx,yy,r,c,grid);
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int r,c;cin>>r>>c;
    string grid[r];
    for(int i=0;i<r;i++){
        cin>>grid[i];
    }
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]=='.'){
                cnt++;
                dfs(i,j,r,c,grid);
            }
        }
    }
    cout<<cnt;
}