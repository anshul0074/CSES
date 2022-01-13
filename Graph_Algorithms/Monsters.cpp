#include<bits/stdc++.h>
using namespace std;
#define int long long

int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};
string step="UDRL";
int nx[1001][1001];
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    char grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    } 
    queue<pair<int,int>>q;
    int ax,ay;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='M'){
                q.push({i,j});
            }
            else if(grid[i][j]=='A'){
                ax=i;ay=j;
            }
        }
    }
    q.push({ax,ay});
    nx[ax][ay]=-1;
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;q.pop();
        if(grid[x][y]=='A' and (x==0 or x==n-1 or y==0 or y==m-1)){
            cout<<"YES\n";
            string s="";
            int t=nx[x][y];
            while(t!=-1){
                s+=step[t];
                x-=dx[t];y-=dy[t];
                t=nx[x][y];
            }
            reverse(s.begin(),s.end());
            cout<<s.size()<<"\n";
            cout<<s<<"\n";
            return 0;
        }
        for(int i=0;i<4;i++){
            int xx=x+dx[i],yy=y+dy[i];
            if(xx<0 or xx>=n or yy<0 or yy>=m or grid[xx][yy]!='.'){
                continue;
            }
            grid[xx][yy]=grid[x][y];
            if(grid[xx][yy]=='A'){
                nx[xx][yy]=i;
            }
            q.push({xx,yy});
        }
    }
    cout<<"NO";
}
